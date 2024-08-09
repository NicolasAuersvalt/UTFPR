import numpy as np
import matplotlib.pyplot as plt

# Definir o campo vetorial F(x, y)
def F(x, y):
    return x**4, x*y

# Definir a parametrização dos segmentos
def r1(t):
    return t, 0

def r2(t):
    return 1 - t, t

def r3(t):
    return 0, 1 - t

# Derivadas das parametrizações
def dr1_dt():
    return 1, 0

def dr2_dt():
    return -1, 1

def dr3_dt():
    return 0, -1

# Intervalo de t
t = np.linspace(0, 1, 100)

# Calcular a integral de linha para cada segmento

# Segmento 1: (0,0) a (1,0)
x1, y1 = r1(t)
F1_x, F1_y = F(x1, y1)
dr1_x, dr1_y = dr1_dt()
integral1 = np.trapz(F1_x * dr1_x + F1_y * dr1_y, t)

# Segmento 2: (1,0) a (0,1)
x2, y2 = r2(t)
F2_x, F2_y = F(x2, y2)
dr2_x, dr2_y = dr2_dt()
integral2 = np.trapz(F2_x * dr2_x + F2_y * dr2_y, t)

# Segmento 3: (0,1) a (0,0)
x3, y3 = r3(t)
F3_x, F3_y = F(x3, y3)
dr3_x, dr3_y = dr3_dt()
integral3 = np.trapz(F3_x * dr3_x + F3_y * dr3_y, t)

# Soma das integrais
total_integral = integral1 + integral2 + integral3

print(f"Integral de linha total: {total_integral}")

# Plotar os segmentos de reta e o campo vetorial
fig, ax = plt.subplots()

# Plotar o campo vetorial
x_grid, y_grid = np.meshgrid(np.linspace(-0.5, 1.5, 20), np.linspace(-0.5, 1.5, 20))
F_x, F_y = F(x_grid, y_grid)
ax.quiver(x_grid, y_grid, F_x, F_y, color='blue', alpha=0.5, scale=10)

# Plotar os segmentos de reta
ax.plot(*zip(*[r1(ti) for ti in np.linspace(0, 1, 100)]), 'r', label='Segmento (0,0) a (1,0)')
ax.plot(*zip(*[r2(ti) for ti in np.linspace(0, 1, 100)]), 'g', label='Segmento (1,0) a (0,1)')
ax.plot(*zip(*[r3(ti) for ti in np.linspace(0, 1, 100)]), 'b', label='Segmento (0,1) a (0,0)')

# Adicionar etiquetas e título
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('Integral de Linha do Campo Vetorial')
ax.legend()
ax.grid(True)

plt.show()
