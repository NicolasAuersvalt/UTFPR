import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a função f(x, y, z) = yz
def f(x, y, z):
    return y * z

# Criar uma grade de pontos (x, y)
x = np.linspace(0, 1, 100)
y = np.linspace(0, 1, 100)
X, Y = np.meshgrid(x, y)

# Calcular z a partir da equação da superfície x + y + z = 1
Z = 1 - X - Y

# Calcular os valores da função f(x, y, z)
F = f(X, Y, Z)

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a superfície colorida de acordo com os valores de f(x, y, z)
surf = ax.plot_surface(X, Y, Z, facecolors=plt.cm.viridis(F), rstride=1, cstride=1, linewidth=0, antialiased=False)

# Adicionar uma barra de cores para indicar os valores de f(x, y, z)
m = plt.cm.ScalarMappable(cmap=plt.cm.viridis)
m.set_array(F)
fig.colorbar(m, ax=ax, shrink=0.5, aspect=5)

# Definir os limites dos eixos
ax.set_xlim([0, 1])
ax.set_ylim([0, 1])
ax.set_zlim([0, 1])

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Superfície x + y + z = 1 com f(x, y, z) = yz')

plt.show()
