import streamlit as st
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

def main():
    # Título da Aplicação
    st.title("Busca de Caminhos em Grafo")

    # Entradas do usuário
    camI = st.number_input("Valor de partida (nó inicial)", min_value=1, step=1)
    camJ = st.number_input("Valor de destino (nó final)", min_value=1, step=1)
    
    # Entrada do grafo
    grafo_input = st.text_area("Insira o grafo (ex: '1 2\\n1 3\\n3 2')", "1 2\n1 3\n3 2\n2 5\n5 6\n6 7\n5 9\n9 7\n2 4\n4 8\n8 11\n8 10\n8 9\n3 10\n4 5")

    # Processar a entrada do grafo
    edges = [list(map(int, line.split())) for line in grafo_input.strip().split('\n')]

    if not edges:
        st.error("Por favor, insira pelo menos uma aresta no grafo.")
        return
    
    # Determinar o tamanho da matriz
    max_node = max(max(edge) for edge in edges)
    len_mat = max_node

    # Inicialização das matrizes
    mat = np.zeros((len_mat + 1, len_mat + 1), dtype=int)
    apoio = np.zeros((len_mat + 1, len_mat + 1), dtype=int)
    final = np.zeros((len_mat + 1, len_mat + 1), dtype=int)

    # Preencher a matriz de adjacência
    for a, b in edges:
        mat[a][b] = 1
        final[a][b] = 1
        apoio[a][b] = 1

    # Verificar se camI e camJ estão dentro dos limites
    if camI > len_mat or camJ > len_mat or camI < 1 or camJ < 1:
        st.error("Os valores de partida e destino devem estar entre 1 e {}".format(len_mat))
        return

    # Variável que controla se o caminho foi encontrado
    achou = True
    tamCaminho = 0

    # Calcula as potências da matriz de adjacência até encontrar um caminho
    for tamCaminho in range(1, len_mat):
        if mat[camI][camJ]:
            achou = False
            break

        # Multiplica as matrizes mat e apoio
        final = np.dot(mat, apoio)

        # Copia a matriz final para a matriz original
        mat = final.copy()

    # Exibir o resultado
    if achou:
        st.error("Não há caminho válido.")
    else:
        st.success(f"O menor número de caminhos de {camI} até {camJ} é: {tamCaminho}")

    # Visualizar o grafo
    G = nx.DiGraph()  # Grafo direcionado
    G.add_edges_from(edges)

    plt.figure(figsize=(10, 6))
    pos = nx.spring_layout(G)  # Posição dos nós
    nx.draw(G, pos, with_labels=True, node_size=700, node_color='lightblue', font_size=10, font_weight='bold', arrows=True)
    plt.title("Grafo")
    plt.axis('off')  # Ocultar os eixos

    # Exibir o grafo no Streamlit
    st.pyplot(plt)

if __name__ == "__main__":
    main()
