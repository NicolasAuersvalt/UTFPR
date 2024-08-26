import numpy as np
import matplotlib.pyplot as plt

# Definir a parametrização do hemisfério
def r(u, v):
    x = 3 * np.sin(u) * np.cos(v)
    y = 3 * np.sin(u) * np.sin(v)
    z = 3 * np.cos(u)
    return x, y, z

# Definir o campo vetorial F(x, y, z)
def F(x, y, z):
    Fx = 2 * y * np.cos(z)
    Fy = np.exp(x) * np.sin(z)
    Fz = x * np.exp(y)
    return Fx, Fy, Fz

# Parâmetros
u = np.linspace(0, np.pi / 2, 30)
v = np.linspace(0, 2 * np.pi, 30)
U, V = np.meshgrid(u, v)
X, Y, Z = r(U, V)

# Campo vetorial sobre a superfície
Fx, Fy, Fz = F(X, Y, Z)

# Visualizar o hemisfério e o campo vetorial
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar o hemisfério
ax.plot_surface(X, Y, Z, color='cyan', alpha=0.5)

# Plotar o campo vetorial na superfície
ax.quiver(X, Y, Z, Fx, Fy, Fz, length=0.5, color='blue')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Campo Vetorial sobre o Hemisfério x^2 + y^2 + z^2 = 9, z >= 0')

plt.show()
