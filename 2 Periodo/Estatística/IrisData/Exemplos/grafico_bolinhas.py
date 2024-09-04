import seaborn as sns
import matplotlib.pyplot as plt

# Carregar o conjunto de dados Iris
df = sns.load_dataset('iris')

# Calcular a média do comprimento e largura das pétalas
mean_petal_length = df['petal_length'].mean()
mean_petal_width = df['petal_width'].mean()

# Criar um gráfico de dispersão para comprimento e largura das pétalas
plt.figure(figsize=(10, 6))
sns.scatterplot(data=df, x='petal_length', y='petal_width', hue='species', palette='deep')

# Adicionar linha horizontal e vertical para a média
plt.axhline(mean_petal_width, color='red', linestyle='--', label=f'Média Largura: {mean_petal_width:.2f}')
plt.axvline(mean_petal_length, color='blue', linestyle='--', label=f'Média Comprimento: {mean_petal_length:.2f}')

# Adicionar legendas e título
plt.title('Comprimento e Largura das Pétalas com Médias')
plt.xlabel('Comprimento da Pétala (cm)')
plt.ylabel('Largura da Pétala (cm)')
plt.legend()

# Mostrar o gráfico
plt.show()
