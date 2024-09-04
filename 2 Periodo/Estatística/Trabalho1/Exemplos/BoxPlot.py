import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# Gerar um conjunto de dados aleatórios
np.random.seed(42)  # Para reprodutibilidade
data = np.random.randn(100)  # 100 pontos de dados aleatórios de uma distribuição normal

# Criar um BoxPlot usando matplotlib
plt.figure(figsize=(8, 6))
plt.boxplot(data)
plt.title('BoxPlot com Matplotlib')
plt.show()

# Criar um BoxPlot usando seaborn
plt.figure(figsize=(8, 6))
sns.boxplot(data=data)
plt.title('BoxPlot com Seaborn')
plt.show()
