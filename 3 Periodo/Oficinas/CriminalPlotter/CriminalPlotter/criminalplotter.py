import serial
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

