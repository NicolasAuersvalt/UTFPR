from header import *

# Carregar o conjunto de dados Iris
iris = load_iris()
X = iris.data
y = iris.target

# Criar um classificador KNN
knn = KNeighborsClassifier(n_neighbors=3)

# Realizar validação cruzada de 10 vezes para o KNN e calcular a média e o desvio padrão das pontuações de acurácia
kf = KFold(n_splits=10, shuffle=True, random_state=42)
knn_scores = []
for train_index, test_index in kf.split(X):
    X_train, X_test = X[train_index], X[test_index]
    y_train, y_test = y[train_index], y[test_index]
    knn.fit(X_train, y_train)
    score = knn.score(X_test, y_test)
    knn_scores.append(score)

mean_knn_accuracy = np.mean(knn_scores)
std_dev_knn_accuracy = np.std(knn_scores)

# Criar um modelo de K-Means
n_clusters = len(np.unique(y))  # Usar o número de classes como o número de clusters
kmeans = KMeans(n_clusters=n_clusters, random_state=42, n_init='auto')

# Calcular a Silhouette Score para cada dobra da validação cruzada
silhouette_scores = []
for train_index, test_index in kf.split(X):
    X_train, X_test = X[train_index], X[test_index]
    kmeans.fit(X_train)
    labels = kmeans.predict(X_test)
    if len(np.unique(labels)) > 1:  # Verificar se há mais de um cluster
        score = silhouette_score(X_test, labels)
        silhouette_scores.append(score)
    else:
        silhouette_scores.append(np.nan)  # Se houver apenas um cluster, o Silhouette Score não é definido

mean_silhouette = np.nanmean(silhouette_scores)

std_dev_silhouette = np.nanstd(silhouette_scores)

# Imprimir os resultados
print(f"Média da acurácia do KNN (validação cruzada 10 vezes): {mean_knn_accuracy:.2f}")

print(f"Desvio padrão da acurácia do KNN (validação cruzada 10 vezes): {std_dev_knn_accuracy:.2f}")

print(f"Média da Silhouette Score do K-Means (validação cruzada 10 vezes): {mean_silhouette:.2f}")

print(f"Desvio padrão da Silhouette Score do K-Means (validação cruzada 10 vezes): {std_dev_silhouette:.2f}")