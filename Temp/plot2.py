import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# 构造数据
x = np.linspace(-1, 1, 100)
y = np.linspace(-1, 1, 100)
x, y = np.meshgrid(x, y)
z = x**2 + y**2

# 将超出圆的部分设为 NaN，使其不显示
z[x**2 + y**2 > 1] = np.nan

# 创建图形和 3D 坐标轴
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 绘制曲面
ax.plot_surface(x, y, z, cmap='viridis', alpha=0.8)

# 绘制圆的边界
theta = np.linspace(0, 2*np.pi, 100)
circle_x = np.cos(theta)
circle_y = np.sin(theta)
circle_z = np.ones_like(theta)  # 圆的 z 值设为 1，与曲面相切
ax.plot(circle_x, circle_y, circle_z, color='r')

# 设置图形标题和坐标轴标签
ax.set_title('Surface $z = x^2 + y^2$ bounded by $x^2 + y^2 = 1$')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

# 显示图形
plt.show()
