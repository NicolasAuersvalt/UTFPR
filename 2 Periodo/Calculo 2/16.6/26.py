import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir os valores de t
t = np.linspace(0, 2 * np.pi, 100)

# Parametrizar a curva
x = np.cos(t)
y = np.sin(t)
z = np.cos(t) + 3

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a curva
ax.plot(x, y, z, color='blue', linewidth=2)

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Curva Parametrizada: x = cos(t), y = sen(t), z = cos(t) + 3')

plt.show()
