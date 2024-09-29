from header import *

# Função para criar um gráfico 3D do cubo
def plot_matriz_3d(matriz):
    arestas = [
        [0, 1], [1, 2], [2, 3], [3, 0],  # Base
        [4, 5], [5, 6], [6, 7], [7, 4],  # Topo
        [0, 4], [1, 5], [2, 6], [3, 7]   # Conexões
    ]
    
    x = matriz[:, 0]
    y = matriz[:, 1]
    z = matriz[:, 2]

    fig = go.Figure()

    for aresta in arestas:
        fig.add_trace(go.Scatter3d(
            x=[x[aresta[0]], x[aresta[1]]],
            y=[y[aresta[0]], y[aresta[1]]],
            z=[z[aresta[0]], z[aresta[1]]],
            mode='lines',
            line=dict(color='blue', width=5)
        ))

    # Definir os limites dos eixos manualmente para 10x10x10
    fig.update_layout(title="Visualização 3D do Cubo", autosize=True,
                      scene=dict(
                          xaxis=dict(range=[-3, 3]),
                          yaxis=dict(range=[-3, 3]),
                          zaxis=dict(range=[-3, 3])
                      ),
                      margin=dict(l=65, r=50, b=65, t=90))
    return fig