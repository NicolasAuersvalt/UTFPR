# Importar pacotes
import pandas as pd
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, accuracy_score
import numpy as np

# Carregar o conjunto de dados Iris
iris = datasets.load_iris()
X = iris.data
y = iris.target

# Dividir os dados em treinamento e teste
np.random.seed(123)  # Para reprodutibilidade
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, stratify=y)

# Normalizar os dados
scaler = MinMaxScaler()
X_train_normalized = scaler.fit_transform(X_train)
X_test_normalized = scaler.transform(X_test)

# Treinar o modelo KNN
k = 3
knn = KNeighborsClassifier(n_neighbors=k)
knn.fit(X_train_normalized, y_train)

# Fazer previsões
y_pred = knn.predict(X_test_normalized)

# Avaliar o modelo
conf_matrix = confusion_matrix(y_test, y_pred)
accuracy = accuracy_score(y_test, y_pred)

print(f"Confusion Matrix:\n{conf_matrix}")
print(f"Acurácia: {accuracy:.4f}")

# Para obter o desvio padrão e a média da acurácia com validação cruzada
from sklearn.model_selection import cross_val_score

# Executar validação cruzada
cv_scores = cross_val_score(knn, X, y, cv=10)  # 10-fold cross-validation

# Calcular média e desvio padrão da acurácia
mean_accuracy = np.mean(cv_scores)
std_accuracy = np.std(cv_scores)

print(f"Média da Acurácia do Cross-Validation): {mean_accuracy:.4f}")
print(f"Desvio Padrão do Cross-Validation): {std_accuracy:.4f}")
