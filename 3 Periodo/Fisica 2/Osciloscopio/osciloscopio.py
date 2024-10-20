import serial
import matplotlib.pyplot as plt
from collections import deque
import time

# Configuração da porta serial (ajuste conforme necessário)
arduino_port = 'COM9'  # Porta serial no Windows
baud_rate = 9600 # Deve ser o mesmo que no código do Arduino

# Inicializa a conexão serial
arduino = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # Aguarda a inicialização da comunicação

# Configuração do gráfico
plt.ion()  # Ativa o modo interativo para plotar em tempo real
fig, ax = plt.subplots()
window_size = 100  # Número de pontos a serem exibidos no gráfico
data = deque([0]*window_size, maxlen=window_size)
line, = ax.plot(data)
ax.set_ylim(0, 1023)  # Limites de leitura analógica do Arduino (0 a 1023)
ax.set_title("Osciloscópio Digital Simples")
ax.set_xlabel("Amostras")
ax.set_ylabel("Valor Analógico")

try:
    while True:
        if arduino.in_waiting:  # Se houver dados disponíveis na porta serial
            line_str = arduino.readline().decode('utf-8').strip()  # Lê a linha enviada pelo Arduino
            try:
                value = int(line_str)  # Converte para inteiro
                data.append(value)  # Adiciona o valor à fila de dados
                line.set_ydata(data)  # Atualiza os dados da linha do gráfico
                fig.canvas.draw()  # Atualiza o gráfico
                fig.canvas.flush_events()  # Garante que o gráfico seja redesenhado
            except ValueError:
                pass  # Ignora leituras inválidas
except KeyboardInterrupt:
    print("Finalizando o programa.")
finally:
    arduino.close()  # Fecha a conexão serial ao encerrar o programa

