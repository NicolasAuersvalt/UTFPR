import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a função da superfície
def z_surface(x, y):
    return 1 + 3*x + 3*y**2

# Definir os valores de x e y
x = np.linspace(-1, 3, 100)
y = np.linspace(-1, 2, 100)
X, Y = np.meshgrid(x, y)

# Calcular os pontos da superfície
Z = z_surface(X, Y)

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a superfície
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.8)

# Definir os vértices do triângulo
triangle_x = [0, 0, 2, 0]
triangle_y = [0, 1, 1, 0]
triangle_z = z_surface(np.array(triangle_x), np.array(triangle_y))

# Plotar o triângulo
ax.plot(triangle_x, triangle_y, triangle_z, color='red', linewidth=3, label='Triângulo')

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Superfície z = 1 + 3x + 3y^2 com Triângulo')

# Adicionar uma legenda
ax.legend()

plt.show()
