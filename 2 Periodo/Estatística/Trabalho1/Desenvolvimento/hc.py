from header import *
'''
# Carregar o dataset Iris
iris = load_iris()
data = iris.data  # Usando todas as quatro features (colunas) como em R

# Calcular a matriz de distância
distance_matrix = pdist(data, metric='euclidean')

# Executar o algoritmo de clustering hierárquico
hc_result = linkage(distance_matrix, method='ward')

# Plotar o dendrograma
plt.figure(figsize=(10, 7))
dendrogram(hc_result)

# Adicionar título e rótulos
plt.title('Dendrograma do Clustering Hierárquico - Dataset Iris')
plt.xlabel('Índice das Amostras')
plt.ylabel('Distância')

# Mostrar o gráfico
plt.show()
'''
# Carregar o dataset Iris
iris = load_iris()
data = iris.data  # Usando todas as quatro features (colunas)
feature_names = iris.feature_names

# Usar apenas as duas primeiras colunas para o gráfico
data1 = data[:, 2]  # Comprimento do sépala (Sepal Length)
data2 = data[:, 3]  # Largura do sépala (Sepal Width)

# Calcular a matriz de distância
distance_matrix = pdist(data, metric='euclidean')

# Executar o algoritmo de clustering hierárquico
hc_result = linkage(distance_matrix, method='ward')

# Determinar o número de clusters
num_clusters = 3  # O dataset Iris tem 3 espécies
clusters = fcluster(hc_result, num_clusters, criterion='maxclust')

# Plotar o gráfico de dispersão
plt.figure(figsize=(10, 7))
scatter = plt.scatter(data1, data2, c=clusters, cmap='viridis', edgecolor='k', s=50)

# Adicionar título e rótulos
plt.title('Gráfico de Dispersão com Clustering Hierárquico - Dataset Iris')
plt.xlabel('Comprimento da Pétala')  # Sepal Length
plt.ylabel('Largura da Pétala') # Sepal Width


# Mostrar o gráfico
plt.show()

