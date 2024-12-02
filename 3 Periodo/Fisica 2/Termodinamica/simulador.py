import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.widgets import Slider

# Configurações iniciais
N_PARTICLES = 50
INIT_PRESSURE = 5
INIT_TEMPERATURE = 5
INIT_VOLUME = 10

velocidade_inicial = 0.5

class ParticleSimulator:
    def __init__(self, n, volume, pressure, temperature):
        self.n = n
        self.volume = volume
        self.pressure = pressure
        self.temperature = temperature
        self.init_particles()

    def init_particles(self):
        """Inicializa partículas com posições e velocidades aleatórias."""
        self.positions = np.random.rand(self.n, 2) * self.volume
        self.velocities = ((np.random.rand(self.n, 2) - velocidade_inicial) * self.pressure)/100
        self.velocities *= self.temperature

    def update(self):
        """Atualiza as posições das partículas, refletindo-as nas bordas."""
        self.positions += self.velocities
        # Reflexão nas bordas
        for i in range(2):  # X e Y
            mask = (self.positions[:, i] < 0) | (self.positions[:, i] > self.volume)
            self.velocities[mask, i] *= -1

# Inicialização do simulador
sim = ParticleSimulator(N_PARTICLES, INIT_VOLUME, INIT_PRESSURE, INIT_TEMPERATURE)

# Configuração da figura do Matplotlib
fig, ax = plt.subplots()
plt.subplots_adjust(bottom=0.25)

sc = ax.scatter(sim.positions[:, 0], sim.positions[:, 1], s=10)
ax.set_xlim(0, INIT_VOLUME)
ax.set_ylim(0, INIT_VOLUME)
ax.set_aspect('equal')

# Função de atualização do gráfico
def update(frame):
    sim.update()
    sc.set_offsets(sim.positions)
    return sc,

# Animação
ani = FuncAnimation(fig, update, interval=50)

# Adicionando sliders
ax_pressure = plt.axes([0.15, 0.1, 0.65, 0.03])
ax_temperature = plt.axes([0.15, 0.05, 0.65, 0.03])
ax_volume = plt.axes([0.15, 0.15, 0.65, 0.03])

slider_pressure = Slider(ax_pressure, 'Pressão', 1, 20, valinit=INIT_PRESSURE)
slider_temperature = Slider(ax_temperature, 'Temperatura', 1, 20, valinit=INIT_TEMPERATURE)
slider_volume = Slider(ax_volume, 'Volume', 5, 30, valinit=INIT_VOLUME)

# Callback para os sliders
def update_sim(val):
    sim.pressure = slider_pressure.val
    sim.temperature = slider_temperature.val
    sim.volume = slider_volume.val
    sim.init_particles()
    ax.set_xlim(0, sim.volume)
    ax.set_ylim(0, sim.volume)

slider_pressure.on_changed(update_sim)
slider_temperature.on_changed(update_sim)
slider_volume.on_changed(update_sim)
plt.show()

