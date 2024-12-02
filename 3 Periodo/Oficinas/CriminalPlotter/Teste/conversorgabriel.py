from PIL import Image
import numpy as np

def resize_image_to_height(image_path, target_height):
    """
    Redimensiona uma imagem para que a altura seja igual ao valor especificado, mantendo a proporção.

    :param image_path: Caminho da imagem.
    :param target_height: Altura desejada (em pixels).
    :return: Objeto Image redimensionado.
    """
    img = Image.open(image_path)

    # Obter dimensões originais
    original_width, original_height = img.size

    # Calcular a nova largura proporcional à altura desejada
    new_width = int((target_height / original_height) * original_width)

    # Redimensionar a imagem
    resized_img = img.resize((new_width, target_height))
    return resized_img

def image_to_matrix(image_path, threshold=128):
    """
    Converte uma imagem em uma matriz de 0 e 1.

    :param image_path: Caminho da imagem.
    :param threshold: Limiar para definir 0 ou 1 (valor entre 0 e 255).
    :return: Matriz de 0 e 1.
    """
    # Carregar a imagem
    img = Image.open(image_path).convert('L')  # Converter para escala de cinza

    # Converter a imagem em um array numpy
    img_array = np.array(img)

    # Aplicar o limiar para gerar 0s e 1s
    binary_matrix = (img_array > threshold).astype(int)

    return binary_matrix

def save_matrix_to_file(matrix, output_path):
    """
    Salva a matriz em um arquivo de texto.

    :param matrix: Matriz de 0 e 1.
    :param output_path: Caminho para salvar o arquivo.
    """
    np.savetxt(output_path, matrix, fmt='%d', delimiter='')

# Caminho da imagem original
image_path = "in.png"

# Configuração
target_height = 312  # Altura desejada
output_image_path = "redimensionada.png"  # Caminho para salvar a imagem redimensionada
output_matrix_path = "m.txt"  # Caminho para salvar a matriz

# Redimensionar a imagem para a altura desejada
resized_image = resize_image_to_height(image_path, target_height)

# Salvar a imagem redimensionada
resized_image.save(output_image_path)
print(f"Imagem redimensionada salva em {output_image_path}")

# Converter a imagem redimensionada para matriz de 0s e 1s
matrix = image_to_matrix(output_image_path)

# Salvar a matriz em um arquivo
save_matrix_to_file(matrix, output_matrix_path)
print(f"Matriz salva em {output_matrix_path}")

# Exibir dimensões e um exemplo da matriz
print(f"Dimensões da matriz: {matrix.shape}")
print("Exemplo da matriz:")
print(matrix[:10, :10])  # Mostra os primeiros 10x10 elementos
