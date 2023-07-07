#!/usr/bin/env python3
from sys import argv
import torch
import torch.nn as nn
import torch.nn.functional as F
from typing import List


class char_tokenizer:
    """
    a very simple char-based tokenizer. the tokenizer turns a string into a list of integers.
    """

    def __init__(self, corpus: List[str]):
        self.corpus = corpus
        # TODO: calculate the vocab size and create a dictionary that maps each character to a unique integer
        # calculate the vocab size
        self.n_vocab = len(set("".join(corpus)))
        # create a dictionary that maps each character to a unique integer
        self.char2int = {char: i for i, char in enumerate(set("".join(corpus)))}
        # End of your code

    def encode(self, string: str):
        # TODO: convert a string into a list of integers and return, using the dictionary you created above
        # convert a string into a list of integers
        encoded = [self.char2int[char] for char in string]
        return encoded
        # End of your code

    def decode(self, codes: List[int]):
        # TODO: convert a list of integers into a string and return, using the dictionary you created above
        # convert a list of integers into a string
        decoded = [list(self.char2int.keys())[list(self.char2int.values()).index(code)] for code in codes]
        return decoded
        # End of your code
    def save(self, path):
        torch.save(self.char2int, path)

    def load(self, path):
        self.char2int = torch.load(path)


class Head(nn.Module):
    """single head of self-attention"""

    def __init__(self, head_size):
        super().__init__()
        # TODO: create three linear layers, Key, Query, and Value, each of which maps from n_embd to head_size
        #       and assign them to self.Key, self.Query, and self.Value, respectively
        # create three linear layers

        self.Key = nn.Linear(n_embd, head_size)
        self.Query = nn.Linear(n_embd, head_size)
        self.Value = nn.Linear(n_embd, head_size)
        # End of your code
        self.register_buffer("tril", torch.tril(torch.ones(block_size, block_size)))

    def forward(self, inputs):
        # TODO: implement the forward function of the head
        #       the input is a tensor of shape (batch, time, n_embd)
        #       the output should be a tensor of shape (batch, time, head_size)
        #       you may use the tril buffer defined above to mask out the upper triangular part of the affinity matrix

        Key = self.Key(inputs)
        Query = self.Query(inputs)
        Value = self.Value(inputs)
        affinity = torch.matmul(Query, Key.transpose(-1, -2)) / (Key.size(-1) ** 0.5)
        # affinity = affinity * self.tril[:affinity.size(1), :affinity.size(2)]
        time = inputs.size(1)
        affinity = affinity.masked_fill(self.tril[:time, :time] == 0, -torch.inf)
        affinity = F.softmax(affinity, dim=-1)
        # out:(batch, time, head_size)
        out = torch.matmul(affinity, Value)
        # End of your code
        return out


class MultiHeadAttention(nn.Module):
    def __init__(self, n_heads, head_size):
        super().__init__()
        # TODO: implement heads and projection
        # heads: a list of heads
        # projection: a linear layer that maps from n_heads * head_size to n_embd
        # create a list of heads
        self.heads = nn.ModuleList([Head(head_size) for _ in range(n_heads)])
        # create a linear layer that maps from n_heads * head_size to n_embd
        self.projection = nn.Linear(n_heads * head_size, n_embd)
        # End of your code

    def forward(self, inputs):
        # TODO: implement the forward function of the multi-head attention
        out = torch.cat([head(inputs) for head in self.heads], dim=-1)
        return self.projection(out)


class FeedForward(nn.Module):
    def __init__(self, n_embd):
        super().__init__()
        # TODO: implement the feed-forward network
        self.net = nn.Sequential(
            nn.Linear(n_embd, 16 * n_embd),
            nn.ReLU(),
            nn.Linear(16 * n_embd, n_embd),
        )
        # End of your code

    def forward(self, inputs):
        return self.net(inputs)


class Block(nn.Module):
    def __init__(self, n_embd, n_heads):
        super().__init__()
        # TODO: implement the block of transformer using the MultiHeadAttention and 
        #       FeedForward modules, along with the layer normalization layers
        # create a layer normalization layer
        self.norm1 = nn.LayerNorm(n_embd)
        # create a multi-head attention layer
        self.attn = MultiHeadAttention(n_heads, n_embd // n_heads)
        # create another layer normalization layer
        self.norm2 = nn.LayerNorm(n_embd)
        # create a feed-forward network layer
        self.ff = FeedForward(n_embd)
        # End of your code

    def forward(self, inputs):
        # TODO: implement the forward function of the block, you may refer to the docs of this experiment
        # inputs:(batch, time, n_embd)
        # out1:(batch, time, n_embd)
        out1 = self.norm1(inputs + self.attn(inputs))
        # out2:(batch, time, n_embd)
        out2 = self.norm2(out1 + self.ff(out1))
        # End of your code
        return out2


class PositionalEncoding(nn.Module):
    def __init__(self, n_embd):
        super().__init__()
        self.n_embd = n_embd
        self.encoding = torch.zeros(block_size, n_embd, device=device)
        self.encoding.requires_grad = False
        pos = torch.arange(0, block_size, device=device).unsqueeze(1)
        step = torch.arange(0, n_embd, 2, device=device).float()
        self.encoding[:, 0::2] = torch.sin(pos / 10000 ** (step / n_embd))
        self.encoding[:, 1::2] = torch.cos(pos / 10000 ** (step / n_embd))

    def forward(self, inputs):
        batch, time = inputs.shape
        return self.encoding[:time, :]


class Transformer(nn.Module):
    def __init__(self):
        super().__init__()
        # TODO: create the embedding table, the stack of blocks, the layer normalization layer, and the linear layers.
        #       assign them to self.embedding, self.blocks, self.norm, and self.linear, respectively
        # create the embedding table
        self.embedding = nn.Embedding(n_vocab, n_embd)
        # create the stack of blocks
        self.blocks = nn.Sequential(*[Block(n_embd, n_heads) for _ in range(n_layers)])
        # create the layer normalization layer
        self.norm = nn.LayerNorm(n_embd)
        # create the linear layers
        self.linear = nn.Linear(n_embd, n_vocab)

        self.positional_encoding = PositionalEncoding(n_embd)
        # End of your code

    def forward(self, inputs, labels=None):
        # TODO: implement the forward function of the transformer

        # embedding:(batch, context, embedding)
        embedding = self.embedding(inputs)

        positional_encoding = self.positional_encoding(inputs)
        # attens:(batch, context, embedding)
        attens = self.blocks(embedding + positional_encoding)

        # attens:(batch, context, embedding)
        attens = self.norm(attens)

        # logits:(batch, context, attens)
        logits = self.linear(attens)

        # End of your code

        # compute the loss

        if labels is None:
            loss = None
        else:
            batch, time, channel = logits.shape
            logits = logits.view(batch * time, channel)
            labels = labels.view(batch * time)
            loss = F.cross_entropy(logits, labels)
        return logits, loss

    def generate(self, inputs, max_new_tokens):
        # TODO: generate new tokens from the transformer, using the inputs as the context,
        #  and return the generated tokens with length of max_new_tokens
        for _ in range(max_new_tokens):
            # generates new tokens by iteratively sampling from the model's predicted probability distribution,
            # concatenating the sampled tokens to the input sequence, and returning the updated sequence.
            # inputs:(batch, context)
            batch, time = inputs.shape
            # logits:(batch, context, attens)
            logits, _ = self.forward(inputs[:, max(0, time+1-block_size):time+1])
            # logits:(batch, context)
            logits = logits[:, -1, :]
            # logits:(batch, 1)
            logits = torch.softmax(logits, dim=-1)
            # logits:(batch, 1)
            logits = torch.multinomial(logits, num_samples=1)
            # logits:(batch, 1)
            logits = logits.view(batch, 1)
            # inputs:(batch, context+1)
            inputs = torch.cat([inputs, logits], dim=-1)

        # End of your code
        return inputs


def get_batch(split):
    data = train_data if split == "train" else val_data
    ix = torch.randint(len(data) - block_size, (batch_size,))
    x = torch.stack([data[i: i + block_size] for i in ix])
    y = torch.stack([data[i + 1: i + block_size + 1] for i in ix])
    x, y = x.to(device), y.to(device)
    return x, y


@torch.no_grad()
def estimate_loss(model):
    out = {}
    model.eval()
    for split in ["train", "val"]:
        losses = torch.zeros(eval_iters)
        for k in range(eval_iters):
            x, y = get_batch(split)
            logits, loss = model(x, y)
            losses[k] = loss.item()
        out[split] = losses.mean()
    return out


def generate(model, context_test):
    # context = torch.zeros((1, 1), device=device, dtype=torch.long)
    # context_test = "I have a dream that one day"
    context = torch.tensor([tokenizer.encode(context_test)], device=device, dtype=torch.long)
    print(decode(model.generate(context, max_new_tokens=100)[0].tolist()))


def train(model):
    optimizer = torch.optim.AdamW(model.parameters(), lr=learning_rate)

    for iter in range(max_iters):

        if iter % eval_interval == 0:
            losses = estimate_loss(model)
            print(
                f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}"
            )

        inputs, labels = get_batch("train")

        logits, loss = model(inputs, labels)
        optimizer.zero_grad(set_to_none=True)
        loss.backward()
        optimizer.step()


# define the hyperparameters
batch_size = 16
block_size = 256
max_iters = 5000  # set the number of training iterations as you like
eval_interval = 500
learning_rate = 1e-3
device = "cuda" if torch.cuda.is_available() else "cpu"
eval_iters = 200
n_embd = 64
n_heads = 8
n_layers = 6
n_vocab = 0

if(len(argv) == 1):
    # read the dataset
    with open("../data/input.txt", "r", encoding="utf-8") as f:
        text = f.read()
    chars = sorted(list(set(text)))

    # initialize the vocabulary
    tokenizer = char_tokenizer(chars)
    encode = tokenizer.encode
    decode = tokenizer.decode
    n_vocab = tokenizer.n_vocab

    # separate the dataset into train and validation
    train_data = torch.tensor(encode(text[: -len(text) // 10]), dtype=torch.long)
    val_data = torch.tensor(encode(text[-len(text) // 10:]), dtype=torch.long)

    test_data = torch.tensor(encode("The meaning of life is "), dtype=torch.long)
    # define the model
    model = Transformer().to(device)
    train(model)
    char_tokenizer.save_vocab(tokenizer, "../model/vocab.json")
    torch.save(model.state_dict(), "../model/model.json")
    generate(model, "To be, or not to be: that is the")
else:
    to_trans = argv[1]
    tokenizer = char_tokenizer([])
    model = Transformer().to(device)
    tokenizer.load("../model/vocab.json")
    n_vocab = tokenizer.n_vocab
    model.load_state_dict(torch.load("../model/model.json", map_location=device))
    generate(model, to_trans)