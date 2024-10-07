import numpy as np
import matplotlib.pyplot as plt

# Parâmetros do MHS
A = 1.0  # Amplitude (m)
w = 2 * np.pi  # Frequência angular (rad/s)
phi = 0.0  # Fase inicial (rad)
t = np.linspace(0, 10, 1000)  # Tempo (s)

# Função para o MHS
def MHS(A, w, phi, t):
    return A * np.cos(w * t + phi)

# Posição em função do tempo
x = MHS(A, w, phi, t)

# Plotar o gráfico do MHS
plt.figure(figsize=(8, 4))
plt.plot(t, x, label='Posição (x)')

# Configurações do gráfico
plt.title('Movimento Harmônico Simples')
plt.xlabel('Tempo (s)')
plt.ylabel('Posição (m)')
plt.grid(True)
plt.legend()
plt.show()

