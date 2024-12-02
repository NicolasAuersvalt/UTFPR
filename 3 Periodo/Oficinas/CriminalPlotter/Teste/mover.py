import serial
import time

tamanho = 1000

# Configuração da porta serial (altere conforme sua necessidade)
arduino = serial.Serial('COM9', 9600)  # Substitua 'COM3' pela porta correta do seu Arduino
time.sleep(2)  # Aguarda o Arduino inicializar

# Função para gerar uma matriz diagonal
def gerar_matriz_diagonal(tamanho):
    matriz = []  # Inicializa a matriz como uma lista vazia
    for i in range(tamanho):
        linha = [0] * tamanho  # Cria uma linha cheia de 0s
        linha[i] = 1  # Preenche a diagonal com 1
        matriz.append(linha)  # Adiciona a linha à matriz
    return matriz


def enviar_valores_para_arduino(matriz):
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j] == 1:
                print(f"Enviando valores i={i} e j={j}")
                # Envia i e j como dois bytes separados
                arduino.write(bytes([i & 0xFF, j & 0xFF]))  # i e j convertidos para o intervalo 0-255
                time.sleep(0.1)  # Aguarda um curto intervalo antes de enviar o próximo par

# Gerar e enviar a matriz diagonal
matriz_diagonal = gerar_matriz_diagonal(tamanho)  # Aqui definimos o tamanho da matriz
enviar_valores_para_arduino(matriz_diagonal)

# Fechar a conexão serial após o envio
arduino.close()

