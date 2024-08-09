import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a função f(x, y, z)
def f(x, y, z):
    return x * y * z**2

# Definir a parametrização da curva
def x(t):
    return -1 + 2 * t

def y(t):
    return 5 + t

def z(t):
    return 4 * t

# Definir a derivada da parametrização da curva
def dx(t):
    return 2

def dy(t):
    return 1

def dz(t):
    return 4

# Definir o intervalo de t
t = np.linspace(0, 1, 100)

# Calcular os pontos da curva
x_curve = x(t)
y_curve = y(t)
z_curve = z(t)

# Calcular a função f ao longo da curva
f_curve = f(x_curve, y_curve, z_curve)

# Calcular a norma da derivada da parametrização da curva
r_prime_norm = np.sqrt(dx(t)**2 + dy(t)**2 + dz(t)**2)

# Calcular a integral de linha
integral = np.trapz(f_curve * r_prime_norm, t)

print(f"Integral de linha: {integral}")

# Criar a figura 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Definir o domínio para a visualização da superfície
u = np.linspace(-1, 1, 30)
v = np.linspace(5, 6, 30)
U, V = np.meshgrid(u, v)

# Calcular Z para a função f(x, y, z) = xyz^2
X = U
Y = V
Z = np.zeros_like(X)

for i in range(X.shape[0]):
    for j in range(X.shape[1]):
        Z[i, j] = f(X[i, j], Y[i, j], 4 * (Y[i, j] - 5))  # Z = 4 * (Y - 5)

# Plotar a superfície da função f(x, y, z)
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.6)

# Plotar a curva
ax.plot(x_curve, y_curve, z_curve, color='r', label='Curva Parametrizada')

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('f(x, y, z)')
ax.set_title('Integral de Linha da Função f(x, y, z) = xyz^2')
ax.legend()

plt.show()
