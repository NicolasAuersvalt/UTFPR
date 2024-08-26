import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import dblquad

# Definir o campo vetorial F(x, y, z) = x i - z j + y k
def F(theta, phi):
    x = 2 * np.sin(theta) * np.cos(phi)
    y = 2 * np.sin(theta) * np.sin(phi)
    z = 2 * np.cos(theta)
    Fx = x
    Fy = -z
    Fz = y
    return Fx, Fy, Fz

# Produto escalar de F com o vetor normal (Jacobiano da esfera)
def integrand(theta, phi):
    Fx, Fy, Fz = F(theta, phi)
    # Área diferencial da esfera: |r_theta x r_phi| = 4 * sin(theta)
    return (Fx * 2 * np.sin(theta) * np.cos(phi) +
            Fy * 2 * np.sin(theta) * np.sin(phi) +
            Fz * 2 * np.cos(theta)) * (4 * np.sin(theta))

# Calcular a integral de superfície
integral, error = dblquad(integrand, 0, 2 * np.pi, lambda x: 0, lambda x: np.pi)

print(f'Valor da integral de superfície: {integral:.4f}')

# Visualizar a esfera e o campo vetorial
theta = np.linspace(0, np.pi, 30)
phi = np.linspace(0, 2 * np.pi, 30)
Theta, Phi = np.meshgrid(theta, phi)
X = 2 * np.sin(Theta) * np.cos(Phi)
Y = 2 * np.sin(Theta) * np.sin(Phi)
Z = 2 * np.cos(Theta)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Plotar a esfera
ax.plot_surface(X, Y, Z, color='cyan', alpha=0.5)

# Plotar o campo vetorial na superfície da esfera
u = X
v = -Z
w = Y
ax.quiver(X, Y, Z, u, v, w, length=0.5, color='blue')

ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.set_title('Campo Vetorial F(x,y,z) = xi - zj + yk sobre a Esfera x^2 + y^2 + z^2 = 4')

plt.show()
