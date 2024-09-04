from header import *

# Configurar a semente aleatória
np.random.seed(123)

# Carregar o dataset Iris
iris = load_iris()
data = iris.data  # Usando todas as quatro features (colunas) como em R

# Executar o algoritmo K-means com 3 clusters
kmeans = KMeans(n_clusters=3, random_state=123)
kmeans_result = kmeans.fit(data)

# Resultados
print("Centróides:\n", kmeans.cluster_centers_)
print("Rótulos:\n", kmeans.labels_)

# Visualização dos clusters
plt.figure(figsize=(6, 4))

# Scatter plot

# [:,0] - Comprimento Sépala [:,1] - Largura Sépala 
# [:,2] - Comprimento Pétala | [:,3] - Largura Pétala

plt.scatter(data[:, 0], data[:, 1], c=kmeans.labels_, cmap='viridis', marker='o')

plt.title('Clustering K-means do Dataset Iris')
plt.xlabel('Comprimento da Sépala (cm)')
plt.ylabel('Largura da Sépala (cm)')
plt.show()
