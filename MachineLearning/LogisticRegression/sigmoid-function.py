import numpy as np
import matplotlib.pyplot as plt


def sigmoid(x):
    return 1 / (1 + np.exp(-x))


x = np.linspace(-10, 10, 400)
y = sigmoid(x)
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='sigmoid', color='blue')
plt.title("Sigmoid Function")
plt.xlabel("x")
plt.ylabel("sigmoid(x)")
plt.grid(True)
plt.show()