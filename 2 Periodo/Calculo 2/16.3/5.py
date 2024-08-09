import numpy as np
import matplotlib.pyplot as plt

# Definir o campo vetorial
def F(x, y):
    u = 2 * x * y
    v = x**2
    return u, v

# Criar uma grade de pontos (x, y)
x = np.linspace(-2, 2, 20)
y = np.linspace(-2, 2, 20)
X, Y = np.meshgrid(x, y)

# Calcular os componentes do campo vetorial em cada ponto da grade
U, V = F(X, Y)

# Plotar o campo vetorial
plt.figure()
plt.quiver(X, Y, U, V, color='b')
plt.title('Campo Vetorial: F(x,y) = <2xy, x^2>')
plt.xlabel('x')
plt.ylabel('y')
plt.grid()
plt.axis('equal')
plt.show()
