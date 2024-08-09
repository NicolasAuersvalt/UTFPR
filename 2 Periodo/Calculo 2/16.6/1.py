import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a parametrização da superfície
def r(u, v):
    x = 2 * u + 3 * v
    y = 1 + 5 * u - v
    z = 2 + u + v
    return x, y, z

# Definir os valores de u e v
u = np.linspace(-2, 2, 100)
v = np.linspace(-2, 2, 100)
U, V = np.meshgrid(u, v)

# Calcular os pontos da superfície
X, Y, Z = r(U, V)

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a superfície
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.8)

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Superfície Parametrizada: r(u,v) = <2u + 3v, 1 + 5u - v, 2 + u + v>')

plt.show()
