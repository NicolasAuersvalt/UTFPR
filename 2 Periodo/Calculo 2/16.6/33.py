import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a parametrização da superfície
def r(u, v):
    x = u + v
    y = 3 * u**2
    z = u - v
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
ax.set_title('Superfície Parametrizada: x = u + v, y = 3u^2, z = u - v')

plt.show()
