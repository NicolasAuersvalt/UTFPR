from header import *

# Carrega o dataset Iris
iris = load_iris()
iris_df = pd.DataFrame(data=iris.data, columns=iris.feature_names)

# Adicionar a coluna 'species' ao DataFrame
iris_df['species'] = iris.target

# Mapear os valores numéricos das espécies para os nomes das espécies
iris_df['species'] = iris_df['species'].map({0: 'setosa', 1: 'versicolor', 2: 'virginica'})

# Definir a paleta de cores
palette = {"setosa": "skyblue", "versicolor": "darkorange", "virginica": "tomato"}

# Criar a figura com subplots
fig, axes = plt.subplots(2, 2, figsize=(16, 12))

# BoxPlot para 'petal length (cm)'
sns.boxplot(x='species', y='petal length (cm)', data=iris_df, palette=palette, ax=axes[0, 0])
axes[0, 0].set_title('Comprimento da Pétala por Espécie')

# BoxPlot para 'petal width (cm)'
sns.boxplot(x='species', y='petal width (cm)', data=iris_df, palette=palette, ax=axes[0, 1])
axes[0, 1].set_title('Largura da Pétala por Espécie')

# BoxPlot para 'sepal length (cm)'
sns.boxplot(x='species', y='sepal length (cm)', data=iris_df, palette=palette, ax=axes[1, 0])
axes[1, 0].set_title('Comprimento da Sépala por Espécie')

# BoxPlot para 'sepal width (cm)'
sns.boxplot(x='species', y='sepal width (cm)', data=iris_df, palette=palette, ax=axes[1, 1])
axes[1, 1].set_title('Largura da Sépala por Espécie')

# Ajustar o layout para evitar sobreposição
plt.tight_layout()

# Mostrar a figura
plt.show()


