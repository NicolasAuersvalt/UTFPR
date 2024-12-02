from PIL import Image
import numpy as np

def image_to_matrix(image_path):
    # Abre a imagem e a converte para preto e branco (escala de cinza)
    img = Image.open(image_path).convert('L')  # Converte para escala de cinza
    # Define um limiar para converter a imagem em preto e branco
    threshold = 128
    # Converte a imagem para uma matriz numpy
    img_np = np.array(img)
    # Aplica o limiar: 0 para branco (acima do limiar) e 1 para preto (abaixo do limiar)
    binary_matrix = np.where(img_np < threshold, 1, 0)
    
    return binary_matrix

def save_matrix_to_file(matrix, filename):
    # Salva a matriz no formato .npy
    np.save(filename, matrix)

# Exemplo de uso
image_path = 'teste.png'  # Substitua pelo caminho da sua imagem
binary_matrix = image_to_matrix(image_path)
filename = 'in'  # Nome do arquivo onde a matriz será salva
save_matrix_to_file(binary_matrix, filename)
print(f'Matriz salva em: {filename}')
