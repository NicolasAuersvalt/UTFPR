import serial
import time

# Configura a porta serial (ajuste conforme necessário)
arduino = serial.Serial('COM9', 9600, timeout=1)  # Em sistemas Unix, pode ser algo como '/dev/ttyUSB0'
time.sleep(2)  # Espera para garantir que a conexão seja estabelecida

def enviar_comando(comando):
    arduino.write(comando.encode())  # Envia o comando como bytes
    time.sleep(0.1)

def ler_retorno():
    while arduino.in_waiting > 0:
        resposta = arduino.readline().decode('utf-8').strip()  # Lê e decodifica a resposta do Arduino
        print(f"Arduino: {resposta}")

try:
    while True:
        if arduino.in_waiting > 0:  # Verifica se o Arduino está enviando algo
            retorno = arduino.readline().decode('utf-8').strip()
            print(f"Arduino: {retorno}")
            
            if retorno == "Digite 0 ou 1":  # Verifica se é o momento de enviar o comando
                comando = input("Digite '0' para Anti-Horário ou '1' para Horário (ou 'q' para sair): ")
                
                if comando == 'q':  # Permite sair do loop
                    print("Encerrando o programa.")
                    break

                elif comando in ['0', '1']:  # Envia apenas comandos válidos
                    enviar_comando(comando)
                else:
                    print("Comando inválido. Tente novamente.")
            else:
                ler_retorno()  # Ler o retorno do Arduino, se houver

except KeyboardInterrupt:
    print("Programa encerrado.")

finally:
    arduino.close()

