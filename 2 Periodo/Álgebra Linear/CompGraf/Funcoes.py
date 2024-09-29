from header import *

# Rotação

def rotacionar(matriz):

    angulo_x = st.slider("Ângulo de Rotação de X (graus)", min_value=0, max_value=360, value=45)
    angulo_y = st.slider("Ângulo de Rotação de Y (graus)", min_value=0, max_value=360, value=45)
    angulo_z = st.slider("Ângulo de Rotação de Z (graus)", min_value=0, max_value=360, value=45)

    angulo_radX = np.radians(angulo_x)
    angulo_radY = np.radians(angulo_y)
    angulo_radZ = np.radians(angulo_z)

        
    matriz_rotacaoX = np.array([[1, 0, 0],
                                [0, np.cos(angulo_radX), -np.sin(angulo_radX)],
                                [0, np.sin(angulo_radX), np.cos(angulo_radX)]])
        
    matriz_rotacaoY = np.array([[np.cos(angulo_radY), 0, np.sin(angulo_radY)],
                                [0, 1, 0],
                                [-np.sin(angulo_radY), 0, np.cos(angulo_radY)]])
        
    matriz_rotacaoZ = np.array([[np.cos(angulo_radZ), -np.sin(angulo_radZ), 0],
                                [np.sin(angulo_radZ), np.cos(angulo_radZ), 0],
                                [0, 0, 1]])

    # R = R1 * R2 * R3 => R = R1 * (R2*R3) => R = R1 * Rr, Rr = (R2*R3)
    matriz_Rr = multiplicar_matrizes(matriz_rotacaoZ, matriz_rotacaoY)
    matriz_R = multiplicar_matrizes(matriz_rotacaoX, matriz_Rr)

    # Aplicar a matriz de rotação à matriz original (P' = R * P)
    resultado = multiplicar_matrizes(matriz_R, matriz.T).T

    return resultado

# Ampliação

def ampliar(matriz):

    coef = st.number_input("Coeficiente de Ampliação:", value=1.0, min_value=0.0)

    # Multiplicando a matriz pelos coeficientes de ampliação
    resultado = matriz * coef

    return resultado

# Translação

def transladar(matriz):

    # Sliders para descolamento
    deslocamento_x = st.slider("Deslocamento X", min_value=-10.0, max_value=10.0, value=0.0)
    deslocamento_y = st.slider("Deslocamento Y", min_value=-10.0, max_value=10.0, value=0.0)
    deslocamento_z = st.slider("Deslocamento Z", min_value=-10.0, max_value=10.0, value=0.0)

        # Criar a matriz de deslocamento
    matriz_deslocamento = np.array([
        [deslocamento_x] * matriz.shape[0],
        [deslocamento_y] * matriz.shape[0],
        [deslocamento_z] * matriz.shape[0]
    ]).T

    # Somar as matrizes
    resultado = matriz + matriz_deslocamento

        
    return resultado

# Multiplicação

def multiplicar_matrizes(matriz1, matriz2):
    return np.dot(matriz1, matriz2)

# Soma

def somar_matrizes(matriz1, matriz2):
    return np.add(matriz1, matriz2)