import serial
import os
import time

char portaArduino = 'COM9'

# Configura a porta serial (ajuste a porta conforme seu sistema)
ser = serial.Serial(portaArduino, 9600)  # Substitua 'COM9' pela sua porta serial

time.sleep(2)  # Aguarda o Arduino inicializar

# Espera ler duas entradas do arduino
def principal():
    while(True):
        char1 = 'L'
        char2 = 'L'
        pronto = 'L'
        while pronto != 'Pronto' :
            char1 = ser.read()
            char2 = ser.read()
            pronto = ser.read()

        # Acessa a matriz char1char2.txt 
        file_name = f"{char1.decode()}{char2.decode()}.txt"
        file_path = os.path.join("/matrizes",file_name)

        # Verifica se o arquivo existe
        if os.path.exists(file_path):
            print(f"Lendo a matriz de {file_path}...")

            # Lê o arquivo e armazena a matriz
            with open(file_path, "r") as a file:
                matriz = []
                for line in file:
                    # Converte cada linha do arquivo em uma linha de inteiros
                    row = list(map(int, line.split()))
                    matriz.append(row)
            
            # Exibe a matriz lida
            print("Matriz lida:")
            for row in matriz:
                print(row)
        else:
            print(f"Arquivo {file_name} não encontrado no diretório /matrizes")

        for i in range(matriz.size())
            for j in range(matriz.size())
                if matriz[i][j] == 1
                    # Envia para o arduino i e j

                    ser.write(f"{int1} {int2}\n".encode())

                    ok = 'L'
                    # Espera receber OK do arduino (TERMINOU DE IMPRIMIR)
                    while(ok!='OK'):
                        ok = ser.read();

principal()
ser.close()  # Fecha a conexão serial

