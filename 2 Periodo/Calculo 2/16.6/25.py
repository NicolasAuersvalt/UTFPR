import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir os valores de t e x
t = np.linspace(0, 2 * np.pi, 100)
x = np.linspace(0, 5, 100)
T, X = np.meshgrid(t, x)

# Parametrizar a superfície
Z = 4 * np.cos(T)
Y = 4 * np.sin(T)
X = X

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a superfície
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.8)

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Superfície Parametrizada: z = 4 cos(t), y = 4 sen(t), x = x')

plt.show()
