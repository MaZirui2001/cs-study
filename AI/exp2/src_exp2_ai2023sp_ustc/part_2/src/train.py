#!/usr/bin/env python3
from sys import argv
import torch
import torch.nn as nn
import torch.nn.functional as funct
from typing import List


class CharTokenizer:
    """
    a very simple char-based tokenizer. the tokenizer turns a string into a list of integers.
    """

    def __init__(self, corpus: List[str]):
        self.corpus = corpus
        # calculate the vocab size and create a dictionary that maps each character to a unique integer
        self.n_vocab = len(set("".join(corpus)))
        self.char2int = {char: i for i, char in enumerate(set("".join(corpus)))}

    def encode(self, string: str):
        # convert a string into a list of integers and return, using the dictionary you created above
        encoded = [self.char2int[char] for char in string]
        return encoded

    def decode(self, codes: List[int]):
        # convert a list of integers into a string and return, using the dictionary you created above
        decoded = [list(self.char2int.keys())[list(self.char2int.values()).index(code)] for code in codes]
        return "".join(decoded)

    def save(self, path):
        # save the dictionary to a file
        torch.save(self.char2int, path)

    def load(self, path):
        # load the dictionary from a file
        self.char2int = torch.load(path)
        self.n_vocab = len(self.char2int)


class Head(nn.Module):
    """single head of self-attention"""

    def __init__(self, head_size):
        super().__init__()
        # create three linear layers, Key, Query, and Value, each of which maps from n_embd to head_size

        self.Key = nn.Linear(n_embd, head_size)
        self.Query = nn.Linear(n_embd, head_size)
        self.Value = nn.Linear(n_embd, head_size)
        self.register_buffer("tril", torch.tril(torch.ones(block_size, block_size)))

    def forward(self, inputs):
        # the input is a tensor of shape (batch, time, n_embd)
        # the output should be a tensor of shape (batch, time, head_size)
        # you may use the tril buffer defined above to mask out the upper triangular part of the affinity matrix

        Key = self.Key(inputs)
        Query = self.Query(inputs)
        Value = self.Value(inputs)

        # Q @ K^T / sqrt(d_k)
        affinity = torch.matmul(Query, Key.transpose(-1, -2)) / (Key.size(-1) ** 0.5)
        # mask out the upper triangular part of the affinity matrix
        time = inputs.size(1)
        affinity = affinity.masked_fill(self.tril[:time, :time] == 0, -torch.inf)
        affinity = funct.softmax(affinity, dim=-1)
        # V @ softmax(Q @ K^T / sqrt(d_k))
        out = torch.matmul(affinity, Value)
        return out


class MultiHeadAttention(nn.Module):
    def __init__(self, _n_heads, head_size):
        super().__init__()
        # create a list of heads
        self.heads = nn.ModuleList([Head(head_size) for _ in range(_n_heads)])
        # create a linear layer that maps from n_heads * head_size to n_embd
        self.projection = nn.Linear(_n_heads * head_size, n_embd)

    def forward(self, inputs):
        # implement the forward function of the multi-head attention
        out = torch.cat([head(inputs) for head in self.heads], dim=-1)
        return self.projection(out)


class FeedForward(nn.Module):
    def __init__(self, _n_embd):
        super().__init__()
        # implement the feed-forward network
        self.net = nn.Sequential(
            nn.Linear(_n_embd, 32 * _n_embd),
            nn.ReLU(),
            nn.Linear(32 * _n_embd, _n_embd),
        )

    def forward(self, inputs):
        return self.net(inputs)


class Block(nn.Module):
    def __init__(self, _n_embd, _n_heads):
        super().__init__()
        # create a layer normalization layer
        self.norm1 = nn.LayerNorm(_n_embd)
        # create a multi-head attention layer
        self.attn = MultiHeadAttention(_n_heads, _n_embd // _n_heads)
        # create another layer normalization layer
        self.norm2 = nn.LayerNorm(_n_embd)
        # create a feed-forward network layer
        self.ff = FeedForward(_n_embd)

    def forward(self, inputs):
        # Residual Connections
        out1 = self.norm1(inputs + self.attn(inputs))
        out2 = self.norm2(out1 + self.ff(out1))
        return out2


class PositionalEncoding(nn.Module):
    def __init__(self, _n_embd):
        super().__init__()
        # calculate the positional encoding and store it in a buffer
        self.n_embd = _n_embd
        self.encoding = torch.zeros(block_size, _n_embd, device=device)
        self.encoding.requires_grad = False
        pos = torch.arange(0, block_size, device=device).unsqueeze(1)
        step = torch.arange(0, _n_embd, 2, device=device).float()
        self.encoding[:, 0::2] = torch.sin(pos / 10000 ** (step / _n_embd))
        self.encoding[:, 1::2] = torch.cos(pos / 10000 ** (step / _n_embd))

    def forward(self, inputs):
        _, time = inputs.shape
        return self.encoding[:time, :]


class Transformer(nn.Module):
    def __init__(self):
        super().__init__()
        # create the embedding table
        self.embedding = nn.Embedding(n_vocab, n_embd)
        # create the positional encoding layer
        self.positional_encoding = PositionalEncoding(n_embd)
        # create the stack of blocks
        self.blocks = nn.Sequential(*[Block(n_embd, n_heads) for _ in range(n_layers)])
        # create the layer normalization layer
        self.norm = nn.LayerNorm(n_embd)
        # create the linear layers
        self.linear = nn.Linear(n_embd, n_vocab)

    def forward(self, inputs, labels=None):

        # embedding:(batch, context, embedding)
        embedding = self.embedding(inputs)
        # positional_encoding:(context, embedding)
        positional_encoding = self.positional_encoding(inputs)
        # attens:(batch, context, embedding)
        attens = self.blocks(embedding + positional_encoding)
        # attens:(batch, context, embedding)
        attens = self.norm(attens)
        # logits:(batch, context, attens)
        logits = self.linear(attens)

        # compute the loss
        if labels is None:
            loss = None
        else:
            batch, time, channel = logits.shape
            logits = logits.view(batch * time, channel)
            labels = labels.view(batch * time)
            loss = funct.cross_entropy(logits, labels)
        return logits, loss

    def generate(self, inputs, max_new_tokens):
        # generate new tokens from the transformer, using the inputs as the context,
        # and return the generated tokens with length of max_new_tokens
        for _ in range(max_new_tokens):
            # generates new tokens by iteratively sampling from the model's predicted probability distribution,
            # concatenating the sampled tokens to the input sequence, and returning the updated sequence.
            batch, time = inputs.shape
            logits, _ = self.forward(inputs[:, max(0, time + 1 - block_size):time + 1])
            logits = torch.softmax(logits[:, -1, :], dim=-1)
            logits = torch.multinomial(logits, num_samples=1)
            logits = logits.view(batch, 1)
            inputs = torch.cat([inputs, logits], dim=-1)

        return inputs


def get_batch(split):
    data = train_data if split == "train" else val_data
    ix = torch.randint(len(data) - block_size, (batch_size,))
    x = torch.stack([data[i: i + block_size] for i in ix])
    y = torch.stack([data[i + 1: i + block_size + 1] for i in ix])
    x, y = x.to(device), y.to(device)
    return x, y


@torch.no_grad()
def estimate_loss(_model):
    out = {}
    _model.eval()
    for split in ["train", "val"]:
        losses = torch.zeros(eval_iters)
        for k in range(eval_iters):
            x, y = get_batch(split)
            _, loss = _model(x, y)
            losses[k] = loss.item()
        out[split] = losses.mean()
    return out


def generate(_model, context_test):
    if len(context_test) == 0:
        context = torch.zeros((1, 1), device=device, dtype=torch.long)
    else:
        context = torch.tensor([tokenizer.encode(context_test)], device=device, dtype=torch.long)
    print(decode(_model.generate(context, max_new_tokens=100)[0].tolist()))


def train(_model):
    optimizer = torch.optim.AdamW(_model.parameters(), lr=learning_rate)

    for _iter in range(max_iters):

        if _iter % eval_interval == 0:
            losses = estimate_loss(_model)
            print(
                f"step {_iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}"
            )

        inputs, labels = get_batch("train")

        _, loss = _model(inputs, labels)
        optimizer.zero_grad(set_to_none=True)
        loss.backward()
        optimizer.step()


# define the hyperparameters
batch_size = 16
block_size = 256
max_iters = 20000
eval_interval = 500
learning_rate = 1e-4
device = "cuda" if torch.cuda.is_available() else "cpu"
eval_iters = 200
n_embd = 64
n_heads = 8
n_layers = 6
n_vocab = 0

if len(argv) == 1:
    # read the dataset
    with open("../data/input.txt", "r", encoding="utf-8") as f:
        text = f.readlines()
    for i in range(len(text)-2, -1, -1):
        if text[i] == "\n" and text[i+1].endswith(":\n") or text[i+1] == "\n":
            text.pop(i+1)
    text = "".join(text)
    chars = sorted(list(set(text)))

    # initialize the vocabulary
    tokenizer = CharTokenizer(chars)
    encode = tokenizer.encode
    decode = tokenizer.decode
    n_vocab = tokenizer.n_vocab

    # separate the dataset into train and validation
    train_data = torch.tensor(encode(text[: -len(text) // 10]), dtype=torch.long)
    val_data = torch.tensor(encode(text[-len(text) // 10:]), dtype=torch.long)

    # define the model
    model = Transformer().to(device)
    train(model)
    CharTokenizer.save(tokenizer, "../model/vocab.json")
    torch.save(model.state_dict(), "../model/model.json")
    generate(model, "To be, or not to be: that is the ")
else:
    to_trans = argv[1]
    tokenizer = CharTokenizer([])
    encode = tokenizer.encode
    decode = tokenizer.decode
    tokenizer.load("../model/vocab.json")
    n_vocab = tokenizer.n_vocab

    model = Transformer().to(device)
    model.load_state_dict(torch.load("../model/model.json", map_location=device))
    generate(model, to_trans)
