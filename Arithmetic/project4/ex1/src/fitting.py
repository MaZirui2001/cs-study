import numpy as np
import matplotlib.pyplot as plt
from scipy import optimize as op

def __sst(y_no_fitting):
    
    y_mean = sum(y_no_fitting) / len(y_no_fitting)
    s_list =[(y - y_mean)**2 for y in y_no_fitting]
    sst = sum(s_list)
    return sst


def __ssr(y_fitting, y_no_fitting):
    y_mean = sum(y_no_fitting) / len(y_no_fitting)
    s_list =[(y - y_mean)**2 for y in y_fitting]
    
    ssr = sum(s_list)
    return ssr

def goodness_of_fit(y_fitting, y_no_fitting):
    SSR = __ssr(y_fitting, y_no_fitting)
    SST = __sst(y_no_fitting)
    rr = SSR / SST
    return rr


plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False    # 用来正常显示负号

def f_1(x, A, C):
    return A * x ** 2 * np.log2(x) * np.log10(x) / np.log10(7) + C

x_group = []
for i in range(1, 28):
    x_group.append(i * 27)
y_group = [
277,
1199.5,
2664.25,
5001,
7674.75,
10566.5,
14711,
19361.75,
23719.25,
29717.5,
33087.25,
40656,
59685.75,
69003.75,
79132.5,
94139,
103754,
119057.25,
136789.5,
146540.25,
165098,
183340.25,
212052.75,
233165.5,
257929.5,
279327.25,
312405.25
]

A, C = op.curve_fit(f_1, x_group, y_group)[0]

# 数据点与原先的进行画图比较
plt.scatter(x_group, y_group, marker='o',label='real value')
y = []
for x in x_group:
    y.append(f_1(x, A, C))
rr = goodness_of_fit(y, y_group)
print(rr)
plt.plot(x_group, y,color='red',label='fitted curve')
plt.title("顶点规模和运行时间的关系")
plt.legend() 
plt.xlabel("规模n")
plt.ylabel("运行时间t/us")

plt.show()
