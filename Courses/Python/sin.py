
import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-10, 10, 400)
y_1 = np.sin(x)
y_2 = np.cos(x)

plt.plot(x, y_1)
plt.plot(x, y_2)

plt.title('Sin Cos')
plt.xlabel('x')
plt.ylabel('y')

plt.grid(True)

plt.show()