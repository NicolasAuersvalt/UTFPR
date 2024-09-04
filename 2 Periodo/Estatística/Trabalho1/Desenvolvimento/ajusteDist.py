from sklearn.datasets import load_iris
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats import norm

# Carrega o dataset Iris
iris = load_iris()

# Selecionar a coluna da largura das sépalas (Sepal Width)
# [:,0] - Comprimento Sepala [:,1] - Largura Sepala 
# [:,2] - Comprimento Pétala | [:,3] - Largura Pétala

flor = iris.data[:, 1]

# Criar o histograma normalizado (freq = False em R equivale a density=True em Python)
plt.figure(figsize=(7, 5))
sns.histplot(flor, kde=False, bins=30 , color='skyblue', stat="density")

# Calcular a média e o desvio padrão da largura das sépalas
mean = np.mean(flor)
stnd = np.std(flor)

# Adicionar a curva de densidade normal ajustada
x_values = np.linspace(min(flor), max(flor), 100)
plt.plot(x_values, norm.pdf(x_values, mean, stnd), color='red')

# Adicionar título e rótulos
plt.title('Ajuste Normal à Largura das Sépalas')
plt.xlabel('Largura das Sépalas (cm)')
plt.ylabel('Densidade')

# Mostrar o gráfico
plt.show()
