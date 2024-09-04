import seaborn as sns
from sklearn.datasets import load_iris

"""

Equivalência para data()

A função data() em R é usada para carregar conjuntos de dados embutidos nos pacotes.

"""


# Carregar o conjunto de dados Iris usando scikit-learn
iris = load_iris()

# Carregar o conjunto de dados Iris usando seaborn
iris_df = sns.load_dataset('iris')

"""

Equivalência para name()

A função names() em R é usada para obter ou definir os nomes
das colunas de um DataFrame ou elementos de uma lista.

"""


import pandas as pd

# Criar um DataFrame
df = pd.DataFrame({
    'A': [1, 2, 3],
    'B': [4, 5, 6],
    'C': [7, 8, 9]
})

# Obter os nomes das colunas
print(df.columns)


"""

Equivalência para help()

A função help() em R é usada para acessar a documentação de funções, pacotes ou objetos.

"""

# Obter ajuda sobre a função print
help(print)

# No Jupyter Notebook, você pode usar:
# print?


"""

Equivalência de Summary()

A função summary() em R é utilizada para fornecer um
resumo estatístico descritivo de um vetor, fator, data frame ou modelo
estatístico. Ela retorna informações como a média, mediana, quartis,
valores mínimos e máximos, entre outras estatísticas.

"""

import pandas as pd

# Criar um DataFrame
data = {'A': [1, 2, 3, 4, 5],
        'B': [5, 4, 3, 2, 1],
        'C': [2, 3, 4, 5, 6]}

df = pd.DataFrame(data)

# Obter um resumo estatístico
summary = df.describe()
print(summary)
