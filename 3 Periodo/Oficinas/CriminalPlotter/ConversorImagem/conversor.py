from PIL import Image
import numpy as np

def image_to_matrix(image_path):
    # Abre a imagem e a converte para preto e branco
    img = Image.open(image_path).convert('L')  # Converte para escala de cinza
    # Define um limiar para converter a imagem em preto e branco
    threshold = 128
    # Converte a imagem para uma matriz numpy
    img_np = np.array(img)
    # Aplica o limiar: 0 para branco (acima do limiar) e 1 para preto (abaixo do limiar)
    binary_matrix = np.where(img_np < threshold, 0, 1)
    
    return binary_matrix

# Exemplo de uso
image_path = 'Integral.png'  # Substitua pelo caminho da sua imagem
binary_matrix = image_to_matrix(image_path)
print(binary_matrix)  # Imprime a matriz de 0 e 1

def save_matrix_to_file(matrix, filename):
    np.save(filename, matrix)  # Salva a matriz no arquivo

# Exemplo de uso
matrix = np.array([[0, 1, 0], [1, 0, 1], [0, 1, 0]])  # Substitua pela matriz gerada
filename = 'in.npy'
save_matrix_to_file(matrix, filename)
