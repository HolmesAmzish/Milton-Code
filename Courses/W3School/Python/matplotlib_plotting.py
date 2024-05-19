import matplotlib.pyplot as plt
import numpy as np

# Draw a line from (1, 3) to (8, 10)
xpoints = np.array([1, 8])
ypoints = np.array([3, 10])

plt.plot(xpoints, ypoints)
plt.show()

# Draw multiple points of a line
xpoints = np.array([1, 2, 6, 8])
ypoints = np.array([3, 8, 1, 10])

plt.plot(xpoints, ypoints)
plt.show()