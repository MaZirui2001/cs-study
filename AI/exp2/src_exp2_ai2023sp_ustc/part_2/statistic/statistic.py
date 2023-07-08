import matplotlib.pyplot as plt

with open('loss.txt', 'r') as f:
    loss = f.readlines()
loss = [i.strip() for i in loss]

# strip the info
time = [i * 100 for i in range(len(loss))]
train_loss = [float(loss[i].split("train loss ")[1].split(", val loss")[0]) for i in range(len(loss))]
val_loss = [float(loss[i].split(", val loss")[1]) for i in range(len(loss))]

# plot
plt.plot(time, train_loss, label='train loss')
plt.plot(time, val_loss, label='val loss')
plt.xlabel('time')
plt.ylabel('iteration')
plt.title('Realation between iteration and loss')
plt.legend()
plt.show()
