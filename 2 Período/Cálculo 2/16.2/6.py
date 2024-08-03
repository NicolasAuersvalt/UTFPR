import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Definir a função f(x, y, z)
def f(x, y, z):
    return x * y * z

# Definir a parametrização da curva
def x(t):
    return 2 * np.sin(t)

def y(t):
    return t

def z(t):
    return -2 * np.cos(t)

# Definir a derivada da parametrização da curva
def dx(t):
    return 2 * np.cos(t)

def dy(t):
    return 1

def dz(t):
    return 2 * np.sin(t)

# Definir o intervalo de t
t = np.linspace(0, np.pi, 100)

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
t_vals = np.linspace(0, np.pi, 30)
x_vals = 2 * np.sin(t_vals)
y_vals = t_vals
z_vals = -2 * np.cos(t_vals)

# Criar a malha para a visualização
X, Y = np.meshgrid(x_vals, y_vals)
Z = np.zeros_like(X)

for i in range(X.shape[0]):
    for j in range(X.shape[1]):
        Z[i, j] = f(X[i, j], Y[i, j], -2 * np.cos(Y[i, j]))

# Plotar a superfície da função f(x, y, z)
ax.plot_surface(X, Y, Z, cmap='viridis', alpha=0.6)

# Plotar a curva
ax.plot(x_curve, y_curve, z_curve, color='r', label='Curva Parametrizada')

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('f(x, y, z)')
ax.set_title('Integral de Linha da Função f(x, y, z) = xyz')
ax.legend()

plt.show()
