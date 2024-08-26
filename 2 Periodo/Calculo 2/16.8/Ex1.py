import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

# Definir a parametrização da curva
def r(t):
    x = np.cos(t)
    y = np.sin(t)
    z = 2 - np.sin(t)
    return x, y, z

# Derivada da parametrização da curva (dr/dt)
def dr_dt(t):
    dx_dt = -np.sin(t)
    dy_dt = np.cos(t)
    dz_dt = -np.cos(t)
    return dx_dt, dy_dt, dz_dt

# Definir o campo vetorial F(x, y, z) = -y^2 i + x j + z^2 k
def F(x, y, z):
    Fx = -y**2
    Fy = x
    Fz = z**2
    return Fx, Fy, Fz

# Integrando F(r(t)) . r'(t) ao longo da curva
def integrand(t):
    x, y, z = r(t)
    Fx, Fy, Fz = F(x, y, z)
    dx_dt, dy_dt, dz_dt = dr_dt(t)
    return Fx * dx_dt + Fy * dy_dt + Fz * dz_dt

# Calcular a integral de linha
integral, error = quad(integrand, 0, 2 * np.pi)

print(f'Valor da integral de linha: {integral:.4f}')

# Visualizar a curva e o campo vetorial
t = np.linspace(0, 2 * np.pi, 100)
x, y, z = r(t)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a curva
ax.plot(x, y, z, 'r', label='Curva de Interseção')

# Plotar o campo vetorial ao longo da curva
Fx, Fy, Fz = F(x, y, z)
ax.quiver(x, y, z, Fx, Fy, Fz, length=0.1, color='blue')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Integral de Linha do Campo F(x,y,z) sobre a Curva de Interseção')

plt.show()
