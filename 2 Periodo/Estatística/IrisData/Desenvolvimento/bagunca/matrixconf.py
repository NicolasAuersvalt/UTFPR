from header import *

# Carregar o conjunto de dados Iris
iris = load_iris()
X = iris.data
y = iris.target

# Dividir o conjunto de dados em treino e teste
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Treinar o modelo k-NN com o conjunto de treino
knn.fit(X_train, y_train)



# Prever os rótulos do conjunto de teste
y_pred = knn.predict(X_test)

# Calcular e imprimir a matriz de confusão
conf_matrix = confusion_matrix(y_test, y_pred)
print("Matriz de Confusão:")
print(conf_matrix)

# Calcular e imprimir a acurácia
acc = accuracy_score(y_test, y_pred)
print(f"Acurácia: {acc:.2f}")
