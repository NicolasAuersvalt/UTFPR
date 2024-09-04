from header import *
''' 
Importamos o conjunto de dados iris e armazenamos
em uma estrutura bidimensional do tipo Data Frame (df),
como um array de duas dimensões
'''
# iris_df = pd.read_csv('ibovespa.csv')
# iris = load_iris()

# Exibe informações de média, desvio padrão, mediana (50%) 
print(iris_df.describe())

#print(iris_df.mode())

# Criar um BoxPlot usando seaborn
plt.figure(figsize=(8, 6))
sns.boxplot(iris_df)
plt.title('BoxPlot com Seaborn')
plt.show()


