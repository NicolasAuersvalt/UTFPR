import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# Definição da EDO: y' = 2y + 3e^t
def edo(t, y):
    return 2 * y + 3 * np.exp(t)

# Função para a solução exata
def solucao_exata(t, C):
    return C * np.exp(2*t) - np.exp(t)

# Intervalo de tempo
t_start = 0
t_end = 5
t_points = 100

t_eval = np.linspace(t_start, t_end, t_points)

# Condição inicial
y0 = 0  # Você pode alterar para outro valor se desejar

# Resolver a EDO numericamente
sol = solve_ivp(edo, [t_start, t_end], [y0], t_eval=t_eval)

# Verificar se a solução foi bem-sucedida
if not sol.success:
    raise RuntimeError('A resolução da EDO falhou.')

# Função para plotar o campo de direções
def plot_campo_direcoes(ax, edo, t_range, y_range, density=20):
    # Gerar uma grade de pontos no intervalo dado
    t = np.linspace(t_range[0], t_range[1], density)
    y = np.linspace(y_range[0], y_range[1], density)
    T, Y = np.meshgrid(t, y)
    
    # Calcular a derivada em cada ponto da grade
    dYdt = edo(T, Y)
    
    # Normalizar os vetores para melhor visualização
    N = np.sqrt(1 + dYdt**2)
    dT = 1 / N
    dY = dYdt / N
    
    # Plotar as direções (campo de inclinação)
    ax.quiver(T, Y, dT, dY, color='lightgray', alpha=0.7)
    ax.set_xlabel('t')
    ax.set_ylabel('y')
    ax.set_title("Solução da EDO y' - 2y = 3e^t com Campo de Direções")

# Configurar o plot
fig, ax = plt.subplots(figsize=(10, 6))

# Definir os limites para o campo de direções
y_min = min(sol.y[0]) - 1
y_max = max(sol.y[0]) + 1

# Plotar o campo de direções
plot_campo_direcoes(ax, edo, [t_start, t_end], [y_min, y_max])

# Plotar a solução numérica
ax.plot(sol.t, sol.y[0], 'b-', label='Solução Numérica')

# Plotar a solução exata
C = (y0 + 1)  # Constante para ajustar a solução exata à condição inicial
ax.plot(t_eval, solucao_exata(t_eval, C), 'r--', label='Solução Exata')

# Legenda e grade
ax.legend()
ax.grid(True)

plt.show()

