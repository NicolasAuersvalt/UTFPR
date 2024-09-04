from header import *

# Funções para o projeto Iris
def kmeans_clustering():
    st.title('Clustering K-means do Dataset Iris')

    iris = load_iris()
    data = iris.data
    kmeans = KMeans(n_clusters=3, random_state=123)
    kmeans_result = kmeans.fit(data)

    st.write("Centróides:\n", kmeans.cluster_centers_)
    st.write("Rótulos:\n", kmeans.labels_)

    plt.figure(figsize=(6, 4))
    plt.scatter(data[:, 0], data[:, 1], c=kmeans.labels_, cmap='viridis', marker='o')
    plt.title('Clustering K-means do Dataset Iris')
    plt.xlabel('Comprimento da Sépala (cm)')
    plt.ylabel('Largura da Sépala (cm)')
    st.pyplot(plt)

def hierarchical_clustering():
    st.title('Clustering Hierárquico do Dataset Iris')

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

def scatter_with_hc_clusters():
    st.title('Gráfico de Dispersão com Clustering Hierárquico')

    iris = load_iris()
    data = iris.data
    data1 = data[:, 2]
    data2 = data[:, 3]
    distance_matrix = pdist(data, metric='euclidean')
    hc_result = linkage(distance_matrix, method='ward')
    num_clusters = 3
    clusters = fcluster(hc_result, num_clusters, criterion='maxclust')

    plt.figure(figsize=(10, 7))
    scatter = plt.scatter(data1, data2, c=clusters, cmap='viridis', edgecolor='k', s=50)
    plt.title('Gráfico de Dispersão com Clustering Hierárquico - Dataset Iris')
    plt.xlabel('Comprimento da Pétala')
    plt.ylabel('Largura da Pétala')
    st.pyplot(plt)

def iris_histograms():
    st.title('Histogramas com Ajuste Normal do Dataset Iris')

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
    st.pyplot(plt)

def knn_classifier():
    st.title('Classificador KNN do Dataset Iris')

    iris = datasets.load_iris()
    X = iris.data
    y = iris.target
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

    st.write(f"Confusion Matrix:\n{conf_matrix}")
    st.write(f"Acurácia: {accuracy:.4f}")

    cv_scores = cross_val_score(knn, X, y, cv=10)
    mean_accuracy = np.mean(cv_scores)
    std_accuracy = np.std(cv_scores)

    st.write(f"Média da Acurácia do Cross-Validation): {mean_accuracy:.4f}")
    st.write(f"Desvio Padrão do Cross-Validation): {std_accuracy:.4f}")

# Funções para a calculadora
def calcular_intervalo_confianca():
    st.title('Calculadora de Intervalo de Confiança para Média')

    media = st.number_input("Média:", min_value=-100.0, max_value=100.0, value=1.0, format="%.6f")
    confiança = st.number_input("Valor de Confiança (%) :", min_value=0.0, max_value=100.0, value=95.0, format="%.6f")
    sd = st.number_input("Desvio Padrão:", min_value=0.1, max_value=1000.0, value=1.0, format="%.6f")
    n = st.number_input("Tamanho da amostra:", min_value=1, max_value=1000, value=30)

    z = abs(norm.ppf((1 + (confiança / 100)) / 2))
    LI = media - (z * sd / np.sqrt(n))
    LS = media + (z * sd / np.sqrt(n))

    st.text(f"Limite inferior: {LI:.6f}")
    st.text(f"Limite superior: {LS:.6f}")

    fig, ax = plt.subplots()
    ax.barh(['Média'], [media], xerr=[(LS - LI) / 2], color='skyblue', alpha=0.7)
    ax.set_xlim(LI - (LS - LI), LS + (LS - LI))
    ax.axvline(x=LI, color='red', linestyle='--', label=f'Limite Inferior ({LI:.6f})')
    ax.axvline(x=LS, color='green', linestyle='--', label=f'Limite Superior ({LS:.6f})')
    ax.legend()
    st.pyplot(fig)

def calculadora_proporcao():
    st.title('Calculadora de Intervalo de Confiança para Proporção')

    p = st.number_input('p :', min_value=0.0, max_value=1.0, value=0.5, format="%.6f")
    conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=95.0, format="%.6f")
    n = st.number_input('Tamanho da amostra :', min_value=1, max_value=1000, value=30)

    z = abs(norm.ppf((1 + (conf / 100)) / 2))

    if 0 <= p <= 1:
        LI = p - (z * np.sqrt((p * (1 - p)) / n))
        LS = p + (z * np.sqrt((p * (1 - p)) / n))

        st.write(f'Limite inferior: {LI:.6f}')
        st.write(f'Limite superior: {LS:.6f}')

        fig, ax = plt.subplots()
        ax.barh(['Proporção'], [p], xerr=[(LS - LI) / 2], color='skyblue', alpha=0.7)
        ax.set_xlim(LI - (LS - LI), LS + (LS - LI))
        ax.axvline(x=LI, color='red', linestyle='--', label=f'Limite Inferior ({LI:.6f})')
        ax.axvline(x=LS, color='green', linestyle='--', label=f'Limite Superior ({LS:.6f})')
        ax.legend()
        st.pyplot(fig)
    else:
        st.write('Erro: o valor de p deve estar entre 0 e 1.')

def calcular_tamanho_amostra_media():
    st.title('Calculadora do Tamanho da Amostra para a Média')

    margem_erro = st.number_input('Margem de Erro :', min_value=0.1, max_value=100.0, value=1.0)
    conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=95.0)
    desvio_padrao = st.number_input('Desvio Padrão :', min_value=0.1, max_value=1000.0, value=1.0)

    z = abs(norm.ppf((1 + (conf / 100)) / 2))
    tamanho_amostra = ((z * desvio_padrao) / margem_erro) ** 2

    st.write(f'Tamanho da Amostra para Média: {tamanho_amostra:.2f}')

def calcular_tamanho_amostra_proporcao():
    st.title('Calculadora do Tamanho da Amostra para Proporção')

    margem_erro = st.number_input('Margem de Erro (%) :', min_value=0.0, max_value=100.0, value=1.0)
    conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=95.0)

    z = abs(norm.ppf((1 + (conf / 100)) / 2))
    tamanho_amostra = ((z**2 * 0.5 * 0.5) / (margem_erro / 100)**2)

    st.write(f'Tamanho da Amostra para Proporção: {tamanho_amostra:.2f}')

# Menu Principal
def main():
    st.sidebar.title("Menu")
    project = st.sidebar.selectbox("Escolha o Projeto:", 
                                   ["Projeto Iris", "Calculadoras"])

    if project == "Projeto Iris":
        iris_option = st.sidebar.selectbox("Escolha uma Opção:", 
                                           ["K-means Clustering",
                                            "Hierarchical Clustering",
                                            "Scatter with HC Clusters",
                                            "Histograms with Normal Fit",
                                            "KNN Classifier"])

        if iris_option == "K-means Clustering":
            kmeans_clustering()
        elif iris_option == "Hierarchical Clustering":
            hierarchical_clustering()
        elif iris_option == "Scatter with HC Clusters":
            scatter_with_hc_clusters()
        elif iris_option == "Histograms with Normal Fit":
            iris_histograms()
        elif iris_option == "KNN Classifier":
            knn_classifier()

    elif project == "Calculadoras":
        calc_option = st.sidebar.selectbox("Escolha uma Calculadora:", 
                                           ["Intervalo de Confiança para Média",
                                            "Intervalo de Confiança para Proporção",
                                            "Tamanho da Amostra para a Média", 
                                            "Tamanho da Amostra para Proporção"])

        if calc_option == "Intervalo de Confiança para Média":
            calcular_intervalo_confianca()
        elif calc_option == "Intervalo de Confiança para Proporção":
            calculadora_proporcao()
        elif calc_option == "Tamanho da Amostra para a Média":
            calcular_tamanho_amostra_media()
        elif calc_option == "Tamanho da Amostra para Proporção":
            calcular_tamanho_amostra_proporcao()

if __name__ == "__main__":
    main()
