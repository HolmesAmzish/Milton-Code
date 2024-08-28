import numpy as np
import matplotlib.pyplot as plt

# 定义损失函数
def loss_function(x):
    return -np.log(x)


x = np.linspace(0.002, 1, 400)  # 从 0.01 开始以避免 log(0)

y = loss_function(x)

plt.plot(x, y)
plt.title('Loss Function')
plt.xlabel('x')
plt.ylabel('L(x)')

plt.show()