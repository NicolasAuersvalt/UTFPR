from PIL import Image
import numpy as np

def load_matrix_from_file(filename):
    # Carrega a matriz salva no arquivo .npy
    return np.load(filename)

def matrix_to_image(binary_matrix, output_path):
    # Converte a matriz de 0 e 1 em uma imagem de escala de cinza (0 para branco, 255 para preto)
    img_np = np.array(binary_matrix) * 255  # Converte 0/1 em 0/255
    img = Image.fromarray(np.uint8(img_np), 'L')  # Cria a imagem a partir da matriz
    img.save(output_path)

# Exemplo de uso
filename = 'in.npy'  # Nome do arquivo onde a matriz foi salva
binary_matrix = load_matrix_from_file(filename)
output_path = 'imagem_convertida.png'  # Nome do arquivo da imagem de saída
matrix_to_image(binary_matrix, output_path)
print(f'Imagem salva em: {output_path}')
