import numpy as np
import matplotlib.pyplot as plt

# Definir o campo vetorial F(x, y)
def F(x, y):
    return (3 * y - np.exp(np.sin(x)), 7 * x + np.sqrt(y**4 + 1))

# Parametrização do círculo
def x(t):
    return 3 * np.cos(t)

def y(t):
    return 3 * np.sin(t)

# Derivadas da parametrização
def dx(t):
    return -3 * np.sin(t)

def dy(t):
    return 3 * np.cos(t)

# Intervalo de t
t = np.linspace(0, 2 * np.pi, 100)

# Calcular os pontos da curva
x_curve = x(t)
y_curve = y(t)

# Calcular a função F ao longo da curva
F_x, F_y = F(x_curve, y_curve)
dr_x = dx(t)
dr_y = dy(t)

# Calcular a integral de linha
integral = np.trapz(F_x * dr_x + F_y * dr_y, t)

print(f"Integral de linha: {integral}")

# Plotar o círculo e o campo vetorial
fig, ax = plt.subplots()

# Plotar o campo vetorial
x_grid, y_grid = np.meshgrid(np.linspace(-4, 4, 20), np.linspace(-4, 4, 20))
F_x_grid, F_y_grid = F(x_grid, y_grid)
ax.quiver(x_grid, y_grid, F_x_grid, F_y_grid, color='blue', alpha=0.5, scale=10)

# Plotar o círculo
circle = plt.Circle((0, 0), 3, color='r', fill=False, linestyle='--', linewidth=2, label='Círculo: x^2 + y^2 = 9')
ax.add_patch(circle)

# Adicionar etiquetas e título
ax.set_xlim(-4, 4)
ax.set_ylim(-4, 4)
ax.set_aspect('equal')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('Integral de Linha sobre o Círculo')
ax.legend()
ax.grid(True)

plt.show()
