import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

# Criar um conjunto de dados exemplo
dados = np.random.randint(1, 7, size=1000)  # 1000 lançamentos de um dado

# Criar gráfico de distribuição de frequência (histograma)
sns.histplot(dados, kde=False, bins=6)

# Adicionar títulos e rótulos
plt.title('Distribuição de Frequência dos Resultados do Dado')
plt.xlabel('Valor do Dado')
plt.ylabel('Frequência')

# Mostrar o gráfico
plt.show()
