#!/usr/bin/env python
# coding: utf-8

# # 量子神经网络在自然语言处理中的应用
# 
# [![下载Notebook](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/website-images/master/resource/_static/logo_notebook.png)](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/notebook/master/mindquantum/zh_cn/mindspore_qnn_for_nlp.ipynb)&emsp;[![下载样例代码](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/website-images/master/resource/_static/logo_download_code.png)](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/notebook/master/mindquantum/zh_cn/mindspore_qnn_for_nlp.py)&emsp;[![查看源文件](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/website-images/master/resource/_static/logo_source.png)](https://gitee.com/mindspore/docs/blob/master/docs/mindquantum/docs/source_zh_cn/qnn_for_nlp.ipynb)
# 
# ## 概述
# 
# 在自然语言处理过程中，词嵌入（Word embedding）是其中的重要步骤，它是一个将高维度空间的词向量嵌入到一个维数更低的连续向量空间的过程。当给予神经网络的语料信息不断增加时，网络的训练过程将越来越困难。利用量子力学的态叠加和纠缠等特性，我们可以利用量子神经网络来处理这些经典语料信息，加入其训练过程，并提高收敛精度。下面，我们将简单地搭建一个量子经典混合神经网络来完成一个词嵌入任务。

# 导入本教程所依赖模块

# In[1]:


import numpy as np
import time
import mindspore as ms
import mindspore.ops as ops
import mindspore.dataset as ds
from mindspore import nn
from mindquantum.framework import MQLayer
from mindquantum.core.gates import RX, RY, X, H
from mindquantum.core.circuit import Circuit, UN
from mindquantum.core.operators import Hamiltonian, QubitOperator


# 本教程实现的是一个[CBOW模型](https://blog.csdn.net/u010665216/article/details/78724856)，即利用某个词所处的环境来预测该词。例如对于“I love natural language processing”这句话，我们可以将其切分为5个词，\["I", "love", "natural", "language", "processing”\]，在所选窗口为2时，我们要处理的问题是利用\["I", "love", "language", "processing"\]来预测出目标词汇"natural"。这里我们以窗口为2为例，搭建如下的量子神经网络，来完成词嵌入任务。
# 
# ![quantum word embedding](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/website-images/master/docs/mindquantum/docs/source_zh_cn/images/qcbow.png)

# 这里，编码线路会将"I"、"love"、"language"和"processing"的编码信息编码到量子线路中，待训练的量子线路由四个Ansatz线路构成，最后我们在量子线路末端对量子比特做$\text{Z}$基矢上的测量，具体所需测量的比特的个数由所需嵌入空间的维数确定。
# 
# ## 数据预处理
# 
# 我们对所需要处理的语句进行处理，生成关于该句子的词典，并根据窗口大小来生成样本点。

# In[2]:


def GenerateWordDictAndSample(corpus, window=2):
    all_words = corpus.split()
    word_set = list(set(all_words))
    word_set.sort()
    word_dict = {w: i for i, w in enumerate(word_set)}
    sampling = []
    for index, _ in enumerate(all_words[window:-window]):
        around = []
        for i in range(index, index + 2*window + 1):
            if i != index + window:
                around.append(all_words[i])
        sampling.append([around, all_words[index + window]])
    return word_dict, sampling


# In[3]:


word_dict, sample = GenerateWordDictAndSample("I love natural language processing")
print(word_dict)
print('word dict size: ', len(word_dict))
print('samples: ', sample)
print('number of samples: ', len(sample))


# 根据如上信息，我们得到该句子的词典大小为5，能够产生一个样本点。
# 
# ## 编码线路
# 
# 为了简单起见，我们使用的编码线路由$\text{RX}$旋转门构成，结构如下。
# 
# ![encoder circuit](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/website-images/master/docs/mindquantum/docs/source_zh_cn/images/encoder.png)
# 
# 我们对每个量子门都作用一个$\text{RX}$旋转门。

# In[4]:


def GenerateEncoderCircuit(n_qubits, prefix=''):
    if prefix and prefix[-1] != '_':
        prefix += '_'
    circ = Circuit()
    for i in range(n_qubits):
        circ += RX(prefix + str(i)).on(i)
    return circ.as_encoder()


# In[5]:


GenerateEncoderCircuit(3, prefix='e').svg()


# 我们通常用$\left|0\right>$和$\left|1\right>$来标记二能级量子比特的两个状态，由态叠加原理，量子比特还可以处于这两个状态的叠加态：
# 
# $$\left|\psi\right>=\alpha\left|0\right>+\beta\left|1\right>$$
# 
# 对于$n$比特的量子态，其将处于$2^n$维的希尔伯特空间中。对于上面由5个词构成的词典，我们只需要$\lceil \log_2 5 \rceil=3$个量子比特即可完成编码，这也体现出量子计算的优越性。
# 
# 例如对于上面词典中的"love"，其对应的标签为2，2的二进制表示为`010`，我们只需将编码线路中的`e_0`、`e_1`和`e_2`分别设为$0$、$\pi$和$0$即可。下面来验证一下。

# In[6]:


from mindquantum.simulator import Simulator

n_qubits = 3 # number of qubits of this quantum circuit
label = 2 # label need to encode
label_bin = bin(label)[-1: 1: -1].ljust(n_qubits, '0') # binary form of label
label_array = np.array([int(i)*np.pi for i in label_bin]).astype(np.float32) # parameter value of encoder
encoder = GenerateEncoderCircuit(n_qubits, prefix='e') # encoder circuit
encoder_params_names = encoder.params_name # parameter names of encoder

print("Label is: ", label)
print("Binary label is: ", label_bin)
print("Parameters of encoder is: \n", np.round(label_array, 5))
print("Encoder circuit is: \n", encoder)
print("Encoder parameter names are: \n", encoder_params_names)

# quantum state evolution operator
state = encoder.get_qs(pr=dict(zip(encoder_params_names, label_array)))
amp = np.round(np.abs(state)**2, 3)

print("Amplitude of quantum state is: \n", amp)
print("Label in quantum state is: ", np.argmax(amp))


# 通过上面的验证，我们发现，对于标签为2的数据，最后得到量子态的振幅最大的位置也是2，因此得到的量子态正是对输入标签的编码。我们将对数据编码生成参数数值的过程总结成如下函数。

# In[7]:


def GenerateTrainData(sample, word_dict):
    n_qubits = np.int(np.ceil(np.log2(1 + max(word_dict.values()))))
    data_x = []
    data_y = []
    for around, center in sample:
        data_x.append([])
        for word in around:
            label = word_dict[word]
            label_bin = bin(label)[-1: 1: -1].ljust(n_qubits, '0')
            label_array = [int(i)*np.pi for i in label_bin]
            data_x[-1].extend(label_array)
        data_y.append(word_dict[center])
    return np.array(data_x).astype(np.float32), np.array(data_y).astype(np.int32)


# In[8]:


GenerateTrainData(sample, word_dict)


# 根据上面的结果，我们将4个输入的词编码的信息合并为一个更长向量，便于后续神经网络调用。
# 
# ## Ansatz线路
# 
# Ansatz线路的选择多种多样，我们选择如下的量子线路作为Ansatz线路，它的一个单元由一层$\text{RY}$门和一层$\text{CNOT}$门构成，对此单元重复$p$次构成整个Ansatz线路。
# 
# ![ansatz circuit](https://mindspore-website.obs.cn-north-4.myhuaweicloud.com/website-images/master/docs/mindquantum/docs/source_zh_cn/images/ansatz.png)
# 
# 定义如下函数生成Ansatz线路。

# In[9]:


def GenerateAnsatzCircuit(n_qubits, layers, prefix=''):
    if prefix and prefix[-1] != '_':
        prefix += '_'
    circ = Circuit()
    for l in range(layers):
        for i in range(n_qubits):
            circ += RY(prefix + str(l) + '_' + str(i)).on(i)
        for i in range(l % 2, n_qubits, 2):
            if i < n_qubits and i + 1 < n_qubits:
                circ += X.on(i + 1, i)
    return circ.as_ansatz()


# In[10]:


GenerateAnsatzCircuit(5, 2, 'a').svg()


# ## 测量
# 
# 我们把对不同比特位上的测量结果作为降维后的数据。具体过程与比特编码类似，例如当我们想将词向量降维为5维向量时，对于第3维的数据可以如下产生：
# 
# - 3对应的二进制为`00011`。
# - 测量量子线路末态对$Z_0Z_1$哈密顿量的期望值。
# 
# 下面函数将给出产生各个维度上数据所需的哈密顿量（hams），其中`n_qubits`表示线路的比特数，`dims`表示词嵌入的维度：

# In[11]:


def GenerateEmbeddingHamiltonian(dims, n_qubits):
    hams = []
    for i in range(dims):
        s = ''
        for j, k in enumerate(bin(i + 1)[-1:1:-1]):
            if k == '1':
                s = s + 'Z' + str(j) + ' '
        hams.append(Hamiltonian(QubitOperator(s)))
    return hams


# In[12]:


GenerateEmbeddingHamiltonian(5, 5)


# ## 量子版词向量嵌入层
# 
# 量子版词向量嵌入层结合前面的编码量子线路和待训练量子线路，以及测量哈密顿量，将`num_embedding`个词嵌入为`embedding_dim`维的词向量。这里我们还在量子线路的最开始加上了Hadamard门，将初态制备为均匀叠加态，用以提高量子神经网络的表达能力。
# 
# 下面，我们定义量子嵌入层，它将返回一个量子线路模拟算子。

# In[13]:


def QEmbedding(num_embedding, embedding_dim, window, layers, n_threads):
    n_qubits = int(np.ceil(np.log2(num_embedding)))
    hams = GenerateEmbeddingHamiltonian(embedding_dim, n_qubits)
    circ = Circuit()
    circ = UN(H, n_qubits)
    encoder_param_name = []
    ansatz_param_name = []
    for w in range(2 * window):
        encoder = GenerateEncoderCircuit(n_qubits, 'Encoder_' + str(w))
        ansatz = GenerateAnsatzCircuit(n_qubits, layers, 'Ansatz_' + str(w))
        encoder.no_grad()
        circ += encoder
        circ += ansatz
        encoder_param_name.extend(encoder.params_name)
        ansatz_param_name.extend(ansatz.params_name)
    grad_ops = Simulator('mqvector', circ.n_qubits).get_expectation_with_grad(hams,
                                                                              circ,
                                                                              parallel_worker=n_threads)
    return MQLayer(grad_ops)


# 整个训练模型跟经典网络类似，由一个嵌入层和两个全连通层构成，然而此处的嵌入层是由量子神经网络构成。下面定义量子神经网络CBOW。

# In[14]:


class CBOW(nn.Cell):
    def __init__(self, num_embedding, embedding_dim, window, layers, n_threads,
                 hidden_dim):
        super(CBOW, self).__init__()
        self.embedding = QEmbedding(num_embedding, embedding_dim, window,
                                    layers, n_threads)
        self.dense1 = nn.Dense(embedding_dim, hidden_dim)
        self.dense2 = nn.Dense(hidden_dim, num_embedding)
        self.relu = ops.ReLU()

    def construct(self, x):
        embed = self.embedding(x)
        out = self.dense1(embed)
        out = self.relu(out)
        out = self.dense2(out)
        return out


# 下面我们对一个稍长的句子来进行训练。首先定义`LossMonitorWithCollection`用于监督收敛过程，并搜集收敛过程的损失。

# In[15]:


class LossMonitorWithCollection(ms.train.callback.LossMonitor):
    def __init__(self, per_print_times=1):
        super(LossMonitorWithCollection, self).__init__(per_print_times)
        self.loss = []

    def begin(self, run_context):
        self.begin_time = time.time()

    def end(self, run_context):
        self.end_time = time.time()
        print('Total time used: {}'.format(self.end_time - self.begin_time))

    def epoch_begin(self, run_context):
        self.epoch_begin_time = time.time()

    def epoch_end(self, run_context):
        cb_params = run_context.original_args()
        self.epoch_end_time = time.time()
        if self._per_print_times != 0 and cb_params.cur_step_num % self._per_print_times == 0:
            print('')

    def step_end(self, run_context):
        cb_params = run_context.original_args()
        loss = cb_params.net_outputs

        if isinstance(loss, (tuple, list)):
            if isinstance(loss[0], ms.Tensor) and isinstance(loss[0].asnumpy(), np.ndarray):
                loss = loss[0]

        if isinstance(loss, ms.Tensor) and isinstance(loss.asnumpy(), np.ndarray):
            loss = np.mean(loss.asnumpy())

        cur_step_in_epoch = (cb_params.cur_step_num - 1) % cb_params.batch_num + 1

        if isinstance(loss, float) and (np.isnan(loss) or np.isinf(loss)):
            raise ValueError("epoch: {} step: {}. Invalid loss, terminating training.".format(
                cb_params.cur_epoch_num, cur_step_in_epoch))
        self.loss.append(loss)
        if self._per_print_times != 0 and cb_params.cur_step_num % self._per_print_times == 0:
            print("\repoch: %+3s step: %+3s time: %5.5s, loss is %5.5s" % (cb_params.cur_epoch_num, cur_step_in_epoch, time.time() - self.epoch_begin_time, loss), flush=True, end='')


# 接下来，利用量子版本的`CBOW`来对一个长句进行词嵌入。运行之前请在终端运行`export OMP_NUM_THREADS=4`，将量子模拟器的线程数设置为4个，当所需模拟的量子系统比特数较多时，可设置更多的线程数来提高模拟效率。

# In[16]:


import mindspore as ms
ms.set_context(mode=ms.PYNATIVE_MODE, device_target="CPU")
corpus = """We are about to study the idea of a computational process.
Computational processes are abstract beings that inhabit computers.
As they evolve, processes manipulate other abstract things called data.
The evolution of a process is directed by a pattern of rules
called a program. People create programs to direct processes. In effect,
we conjure the spirits of the computer with our spells."""

ms.set_seed(42)
window_size = 2
embedding_dim = 10
hidden_dim = 128
word_dict, sample = GenerateWordDictAndSample(corpus, window=window_size)
train_x, train_y = GenerateTrainData(sample, word_dict)

train_loader = ds.NumpySlicesDataset({
    "around": train_x,
    "center": train_y
}, shuffle=False).batch(3)
net = CBOW(len(word_dict), embedding_dim, window_size, 3, 4, hidden_dim)
net_loss = nn.SoftmaxCrossEntropyWithLogits(sparse=True, reduction='mean')
net_opt = nn.Momentum(net.trainable_params(), 0.01, 0.9)
loss_monitor = LossMonitorWithCollection(500)
model = ms.Model(net, net_loss, net_opt)
model.train(350, train_loader, callbacks=[loss_monitor], dataset_sink_mode=False)


# 打印收敛过程中的损失函数值：

# In[17]:


import matplotlib.pyplot as plt

plt.plot(loss_monitor.loss, '.')
plt.xlabel('Steps')
plt.ylabel('Loss')
plt.show()


# 通过如下方法打印量子嵌入层的量子线路中的参数：

# In[18]:


net.embedding.weight.asnumpy()


# ## 经典版词向量嵌入层
# 
# 这里我们利用经典的词向量嵌入层来搭建一个经典的CBOW神经网络，并与量子版本进行对比。
# 
# 首先，搭建经典的CBOW神经网络，其中的参数跟量子版本的类似。

# In[19]:


class CBOWClassical(nn.Cell):
    def __init__(self, num_embedding, embedding_dim, window, hidden_dim):
        super(CBOWClassical, self).__init__()
        self.dim = 2 * window * embedding_dim
        self.embedding = nn.Embedding(num_embedding, embedding_dim, True)
        self.dense1 = nn.Dense(self.dim, hidden_dim)
        self.dense2 = nn.Dense(hidden_dim, num_embedding)
        self.relu = ops.ReLU()
        self.reshape = ops.Reshape()

    def construct(self, x):
        embed = self.embedding(x)
        embed = self.reshape(embed, (-1, self.dim))
        out = self.dense1(embed)
        out = self.relu(out)
        out = self.dense2(out)
        return out


# 生成适用于经典CBOW神经网络的数据集。

# In[20]:


train_x = []
train_y = []
for i in sample:
    around, center = i
    train_y.append(word_dict[center])
    train_x.append([])
    for j in around:
        train_x[-1].append(word_dict[j])
train_x = np.array(train_x).astype(np.int32)
train_y = np.array(train_y).astype(np.int32)
print("train_x shape: ", train_x.shape)
print("train_y shape: ", train_y.shape)


# 我们对经典CBOW网络进行训练。

# In[21]:


ms.set_context(mode=ms.GRAPH_MODE, device_target="CPU")

train_loader = ds.NumpySlicesDataset({
    "around": train_x,
    "center": train_y
}, shuffle=False).batch(3)
net = CBOWClassical(len(word_dict), embedding_dim, window_size, hidden_dim)
net_loss = nn.SoftmaxCrossEntropyWithLogits(sparse=True, reduction='mean')
net_opt = nn.Momentum(net.trainable_params(), 0.01, 0.9)
loss_monitor = LossMonitorWithCollection(500)
model = ms.Model(net, net_loss, net_opt)
model.train(350, train_loader, callbacks=[loss_monitor], dataset_sink_mode=False)


# 打印收敛过程中的损失函数值：

# In[22]:


import matplotlib.pyplot as plt

plt.plot(loss_monitor.loss, '.')
plt.xlabel('Steps')
plt.ylabel('Loss')
plt.show()


# 由上可知，通过量子模拟得到的量子版词嵌入模型也能很好的完成嵌入任务。当数据集大到经典计算机算力难以承受时，量子计算机将能够轻松处理这类问题。

# ## 参考文献
# 
# [1] Tomas Mikolov, Kai Chen, Greg Corrado, Jeffrey Dean. [Efficient Estimation of Word Representations in
# Vector Space](https://arxiv.org/pdf/1301.3781.pdf)
