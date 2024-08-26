import numpy as np
import matplotlib.pyplot as plt

# Definir a parametrização do cone
def r(x, theta):
    y = np.sqrt(x**2 + 1) * np.cos(theta)
    z = np.sqrt(x**2 + 1) * np.sin(theta)
    return x, y, z

# Definir o campo vetorial F(x, y, z)
def F(x, y, z):
    Fx = np.arctan(x**2 * y * z**2)
    Fy = x**2 * y
    Fz = x**2 * z**2
    return Fx, Fy, Fz

# Parâmetros
x = np.linspace(0, 2, 30)
theta = np.linspace(0, 2 * np.pi, 30)
X, Theta = np.meshgrid(x, theta)
Y = np.sqrt(X**2 + 1) * np.cos(Theta)
Z = np.sqrt(X**2 + 1) * np.sin(Theta)

# Campo vetorial sobre a superfície
Fx, Fy, Fz = F(X, Y, Z)

# Visualizar o cone e o campo vetorial
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar o cone
ax.plot_surface(X, Y, Z, color='cyan', alpha=0.5)

# Plotar o campo vetorial na superfície
ax.quiver(X, Y, Z, Fx, Fy, Fz, length=0.1, color='blue')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Campo Vetorial sobre o Cone x = sqrt(y^2 - z^2), 0 <= x <= 2')

plt.show()
