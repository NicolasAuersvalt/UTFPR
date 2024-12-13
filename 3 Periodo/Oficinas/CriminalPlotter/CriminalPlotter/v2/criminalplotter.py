import serial
import os
import time

portaArduino = '/dev/ttyUSB0'

# Configura a porta serial (ajuste a porta conforme seu sistema)
ser = serial.Serial(portaArduino, 9600)  # Substitua 'COM9' pela sua porta serial
print(f"Conectado à porta {portaArduino} com baudrate 9600")
#ser.timeout = 1  # Timeout de 1 segundo para leitura

time.sleep(2)  # Aguarda o Arduino inicializar

# Espera ler duas entradas do Arduino
def principal():
    while True:
        char1 = 'L'
        char2 = 'L'
        pronto = 'L'

        print("Esperando a mensagem 'Pronto' do Arduino...")
        # Aguarda a mensagem "Pronto" do Arduino
        while pronto != 'Pronto':
            try:
                # Lê os caracteres e imprime para debug
                char1 = ser.read(1).decode('ascii', errors='ignore').strip()
                char2 = ser.read(1).decode('ascii', errors='ignore').strip()
                print(f"Lido do Arduino: char1 = {char1}, char2 = {char2}")

                pronto = ser.readline().decode('ascii', errors='ignore').strip()  # Espera a linha completa de "Pronto"
                print(f"Mensagem 'Pronto' lida: {pronto}")
            except Exception as e:
                print(f"Erro ao ler dados do Arduino: {e}")
        
        print(f"Recebido 'Pronto' do Arduino: {pronto}")

        # Acessa a matriz correspondente ao arquivo char1char2.txt
        file_name = f"{char1}{char2}.txt"
        file_path = os.path.join("matrizes", file_name)

        print(f"Verificando se o arquivo {file_name} existe...")
        # Verifica se o arquivo existe
        if os.path.exists(file_path):
            print(f"Lendo a matriz de {file_path}...")

            # Lê o arquivo e armazena a matriz
            matriz = []
            try:
                with open(file_path, "r") as file:
                    for line in file:
                        # Converte cada linha em uma lista de inteiros, separando cada caractere
                        row = [int(char) for char in line.strip()]  # Cada caractere se torna um inteiro
                        matriz.append(row)
                print(f"Matriz lida com sucesso.")
            except Exception as e:
                print(f"Erro ao ler o arquivo: {e}")

            # Exibe a matriz lida
            print("Matriz lida:")
            for row in matriz:
               print(row)

            print("Conteúdo atual da matriz para depuração:")
            for idx, row in enumerate(matriz):
                print(f"Linha {idx}: {row}")


            stack_x = []  # Stack para coordenadas x
            stack_y = []  # Stack para coordenadas y

            for i in range(len(matriz)):  # Itera sobre as linhas
                for j in range(len(matriz[i])):  # Itera sobre as colunas da linha atual
                    if matriz[i][j] == 0:
                        stack_x.append(i)  # Adiciona o índice da linha (x) na stack_x
                        stack_y.append(j)  # Adiciona o índice da coluna (y) na stack_y


            print(f"Coordenadas na stack_x: {stack_x}")
            print(f"Coordenadas na stack_y: {stack_y}")

            # Envia os pares da stack para o Arduino
            while stack_x and stack_y:
                x = stack_x.pop()
                y = stack_y.pop()
                comando = f"{x} {y}\n"
                print(f"Enviando coordenadas para o Arduino: {comando.strip()}")
                ser.write(comando.encode())
                time.sleep(0.1)  # Pequeno delay

                # Espera receber "OK" do Arduino (indica que terminou de imprimir)
                ok = 'L'
                while ok != 'OK':
                    ok = ser.readline().decode('ascii', errors='ignore').strip()  # Espera a linha completa de "OK"
                    print(f"Recebido do Arduino: {ok}")
        else:
            print(f"Arquivo {file_name} não encontrado no diretório matrizes.")

if __name__ == "__main__":
    try:
        principal()
    except KeyboardInterrupt:
        print("Encerrando...")
    finally:
        ser.close()  # Fecha a conexão serial
        print("Conexão serial fechada.")
