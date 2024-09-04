import seaborn as sns
import matplotlib.pyplot as plt

# Carregar o conjunto de dados Iris
df = sns.load_dataset('iris')

# Criar um histograma para a largura das pétalas
plt.figure(figsize=(8, 6))
sns.histplot(df['petal_width'], kde=False, bins=20, color='skyblue')

# Adicionar título e rótulos
plt.title('Histograma da Largura das Pétalas')
plt.xlabel('Largura da Pétala (cm)')
plt.ylabel('Frequência')

# Mostrar o gráfico
plt.show()
