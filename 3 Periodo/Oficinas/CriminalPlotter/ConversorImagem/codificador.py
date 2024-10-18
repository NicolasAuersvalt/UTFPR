from PIL import Image
import numpy as np

def matrix_to_image(binary_matrix, output_path):
    # Converte a matriz numpy para uma imagem de escala de cinza (0-255)
    img_np = np.array(binary_matrix) * 255  # Converte 0/1 em 0/255
    # Cria a imagem a partir da matriz
    img = Image.fromarray(np.uint8(img_np), 'L')  # 'L' para escala de cinza
    # Salva a imagem no caminho especificado
    img.save(output_path)

# Exemplo de uso
binary_matrix = np.array([[0, 1, 0], [1, 0, 1], [0, 1, 0]])  # Exemplo de matriz
output_path = 'imagem_convertida.png'
matrix_to_image(binary_matrix, output_path)
print(f'Imagem salva em: {output_path}')
