from header import *

# Função para exibir estatísticas do dataset Iris
def display_iris_statistics():
    st.header("Iris Dataset Statistics")

    iris_df = sns.load_dataset('iris')

    st.write("**Descrição estatística (média, desvio padrão, mediana):**")
    st.write(iris_df.describe())

    st.write("**Moda:**")
    st.write(iris_df.mode())

# Função para plotar o histograma da largura das pétalas
def plot_iris_histogram():
    st.header("Histograma da Largura das Pétalas")

    iris_df = sns.load_dataset('iris')

    plt.figure(figsize=(8, 6))
    sns.histplot(iris_df['petal_width'], kde=False, bins=20, color='skyblue')
    plt.title('Histograma da Largura das Pétalas')
    plt.xlabel('Largura da Pétala (cm)')
    plt.ylabel('Frequência')

    st.pyplot(plt)

# Função para criar BoxPlots para as variáveis do Iris Dataset
def plot_iris_boxplots():
    st.header("BoxPlots do Dataset Iris")

    iris = load_iris()
    iris_df = pd.DataFrame(data=iris.data, columns=iris.feature_names)
    iris_df['species'] = iris.target
    iris_df['species'] = iris_df['species'].map({0: 'setosa', 1: 'versicolor', 2: 'virginica'})

    palette = {"setosa": "skyblue", "versicolor": "darkorange", "virginica": "tomato"}

    fig, axes = plt.subplots(2, 2, figsize=(16, 12))

    sns.boxplot(x='species', y='petal length (cm)', data=iris_df, palette=palette, ax=axes[0, 0])
    axes[0, 0].set_title('Comprimento da Pétala por Espécie')

    sns.boxplot(x='species', y='petal width (cm)', data=iris_df, palette=palette, ax=axes[0, 1])
    axes[0, 1].set_title('Largura da Pétala por Espécie')

    sns.boxplot(x='species', y='sepal length (cm)', data=iris_df, palette=palette, ax=axes[1, 0])
    axes[1, 0].set_title('Comprimento da Sépala por Espécie')

    sns.boxplot(x='species', y='sepal width (cm)', data=iris_df, palette=palette, ax=axes[1, 1])
    axes[1, 1].set_title('Largura da Sépala por Espécie')

    plt.tight_layout()

    st.pyplot(fig)

# Função para ajustar a distribuição normal na largura das sépalas
def plot_normal_fit_sepal_width():
    st.header("Ajuste Normal à Largura das Sépalas")

    iris = load_iris()
    flor = iris.data[:, 1]

    plt.figure(figsize=(7, 5))
    sns.histplot(flor, kde=False, bins=12, color='skyblue', stat="density")

    mean = np.mean(flor)
    stnd = np.std(flor)

    x_values = np.linspace(min(flor), max(flor), 100)
    plt.plot(x_values, norm.pdf(x_values, mean, stnd), color='red')

    plt.title('Ajuste Normal à Largura das Sépalas')
    plt.xlabel('Largura das Sépalas (cm)')
    plt.ylabel('Densidade')
    st.pyplot(plt)

# Função para criar histogramas com ajuste normal para todas as variáveis
def plot_all_normal_fits():
    st.header("Ajuste Normal para Todas as Variáveis")

    iris = load_iris(as_frame=True)
    df = iris.frame

    fig, axs = plt.subplots(2, 2, figsize=(12, 10))

    # Petal Width
    sns.histplot(df['petal width (cm)'], kde=False, stat='density', ax=axs[0, 0])
    mu, std = df['petal width (cm)'].mean(), df['petal width (cm)'].std()
    xmin, xmax = axs[0, 0].get_xlim()
    x = np.linspace(xmin, xmax, 100)
    p = norm.pdf(x, mu, std)
    axs[0, 0].plot(x, p, 'r', lw=2)
    axs[0, 0].set_title('Ajuste Normal - Petal Width')

    # Petal Length
    sns.histplot(df['petal length (cm)'], kde=False, stat='density', ax=axs[0, 1])
    mu, std = df['petal length (cm)'].mean(), df['petal length (cm)'].std()
    xmin, xmax = axs[0, 1].get_xlim()
    x = np.linspace(xmin, xmax, 100)
    p = norm.pdf(x, mu, std)
    axs[0, 1].plot(x, p, 'r', lw=2)
    axs[0, 1].set_title('Ajuste Normal - Petal Length')

    # Sepal Width
    sns.histplot(df['sepal width (cm)'], kde=False, stat='density', ax=axs[1, 0])
    mu, std = df['sepal width (cm)'].mean(), df['sepal width (cm)'].std()
    xmin, xmax = axs[1, 0].get_xlim()
    x = np.linspace(xmin, xmax, 100)
    p = norm.pdf(x, mu, std)
    axs[1, 0].plot(x, p, 'r', lw=2)
    axs[1, 0].set_title('Ajuste Normal - Sepal Width')

    # Sepal Length
    sns.histplot(df['sepal length (cm)'], kde=False, stat='density', ax=axs[1, 1])
    mu, std = df['sepal length (cm)'].mean(), df['sepal length (cm)'].std()
    xmin, xmax = axs[1, 1].get_xlim()
    x = np.linspace(xmin, xmax, 100)
    p = norm.pdf(x, mu, std)
    axs[1, 1].plot(x, p, 'r', lw=2)
    axs[1, 1].set_title('Ajuste Normal - Sepal Length')

    plt.tight_layout()
    st.pyplot(fig)

# Função para realizar o clustering K-means
def run_kmeans_clustering():
    st.header("Clustering K-means do Dataset Iris")

    iris = load_iris()
    data = iris.data

    kmeans = KMeans(n_clusters=3, random_state=123)
    kmeans_result = kmeans.fit(data)

    st.write("**Centróides:**")
    st.write(kmeans.cluster_centers_)

    st.write("**Rótulos:**")
    st.write(kmeans.labels_)

    plt.figure(figsize=(6, 4))
    plt.scatter(data[:, 0], data[:, 1], c=kmeans.labels_, cmap='viridis', marker='o')
    plt.title('Clustering K-means do Dataset Iris')
    plt.xlabel('Comprimento da Sépala (cm)')
    plt.ylabel('Largura da Sépala (cm)')
    st.pyplot(plt)

# Função para criar o dendrograma do clustering hierárquico
def plot_hierarchical_clustering():
    st.header("Clustering Hierárquico do Dataset Iris")

    iris = load_iris()
    data = iris.data

    distance_matrix = pdist(data, metric='euclidean')
    hc_result = linkage(distance_matrix, method='ward')

    plt.figure(figsize=(10, 7))
    dendrogram(hc_result)
    plt.title('Dendrograma do Clustering Hierárquico - Dataset Iris')
    plt.xlabel('Índice das Amostras')
    plt.ylabel('Distância')
    st.pyplot(plt)

# Função para treinar e avaliar o modelo KNN
def run_knn_classification():
    st.header("Classificação KNN do Dataset Iris")

    iris = load_iris()
    X = iris.data
    y = iris.target

    np.random.seed(123)
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, stratify=y)

    scaler = MinMaxScaler()
    X_train_normalized = scaler.fit_transform(X_train)
    X_test_normalized = scaler.transform(X_test)

    k = 3
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train_normalized, y_train)

    y_pred = knn.predict(X_test_normalized)

    conf_matrix = confusion_matrix(y_test, y_pred)
    accuracy = accuracy_score(y_test, y_pred)

    st.write("**Matriz de Confusão:**")
    st.write(conf_matrix)
    st.write(f"**Acurácia:** {accuracy:.4f}")

    cv_scores = cross_val_score(knn, X, y, cv=10)
    mean_accuracy = np.mean(cv_scores)
    std_accuracy = np.std(cv_scores)

    st.write(f"**Média da Acurácia do Cross-Validation:** {mean_accuracy:.4f}")
    st.write(f"**Desvio Padrão da Acurácia do Cross-Validation:** {std_accuracy:.4f}")

# Configuração do menu lateral
st.sidebar.title("Menu")
options = st.sidebar.radio("Escolha uma opção", [
    "Estatísticas do Iris Dataset",
    "Histograma da Largura das Pétalas",
    "BoxPlots do Dataset Iris",
    "Ajuste Normal à Largura das Sépalas",
    "Ajuste Normal para Todas as Variáveis",
    "Clustering K-means",
    "Clustering Hierárquico",
    "Classificação KNN"
])

if options == "Estatísticas do Iris Dataset":
    display_iris_statistics()
elif options == "Histograma da Largura das Pétalas":
    plot_iris_histogram()
elif options == "BoxPlots do Dataset Iris":
    plot_iris_boxplots()
elif options == "Ajuste Normal à Largura das Sépalas":
    plot_normal_fit_sepal_width()
elif options == "Ajuste Normal para Todas as Variáveis":
    plot_all_normal_fits()
elif options == "Clustering K-means":
    run_kmeans_clustering()
elif options == "Clustering Hierárquico":
    plot_hierarchical_clustering()
elif options == "Classificação KNN":
    run_knn_classification()
