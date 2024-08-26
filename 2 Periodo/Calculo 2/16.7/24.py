import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a grade de pontos para o campo vetorial
x = np.linspace(-2, 2, 10)
y = np.linspace(-2, 2, 10)
z = np.linspace(1, 3, 10)
X, Y, Z = np.meshgrid(x, y, z)

# Definir o campo vetorial F(x,y,z) = -x i - y j + z^3 k
u = -X
v = -Y
w = Z**3

# Definir o cone z = sqrt(x^2 + y^2)
theta = np.linspace(0, 2 * np.pi, 100)
r = np.linspace(0, 2, 50)
R, Theta = np.meshgrid(r, theta)
X_cone = R * np.cos(Theta)
Y_cone = R * np.sin(Theta)
Z_cone = np.sqrt(X_cone**2 + Y_cone**2)

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar o campo vetorial
ax.quiver(X, Y, Z, u, v, w, length=0.2, normalize=True, color='blue')

# Plotar o cone
ax.plot_surface(X_cone, Y_cone, Z_cone, color='orange', alpha=0.5)

# Plotar os planos z = 1 e z = 3
X_plane, Y_plane = np.meshgrid(np.linspace(-2, 2, 100), np.linspace(-2, 2, 100))
Z_plane1 = np.ones_like(X_plane)
Z_plane3 = 3 * np.ones_like(X_plane)
ax.plot_surface(X_plane, Y_plane, Z_plane1, color='green', alpha=0.3)
ax.plot_surface(X_plane, Y_plane, Z_plane3, color='red', alpha=0.3)

# Definir os limites dos eixos
ax.set_xlim([-2, 2])
ax.set_ylim([-2, 2])
ax.set_zlim([0, 4])

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Campo Vetorial F(x,y,z) = -xi - yj + z^3k com Cone e Planos')

plt.show()
