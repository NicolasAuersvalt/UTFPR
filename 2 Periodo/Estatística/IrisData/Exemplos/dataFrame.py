import pandas as pd

# Cria um dicionário (chave:valor)
data = {
  "Nome": [ "Luiz", "João", "Carlos","Marcos"],
  "Idade": [25, 35,45, 28],
  "Time": ["Flamengo", "Santos", "Vasco",
  "Fluminense"]}

# Cria uma tabela bidimensional (DataFrame)
df = pd.DataFrame(data)

# Exibe o DataFrame
print(df)

# Pandas use the loc attribute to return one or more specified row(s)

print(df.loc[0])

#use a list of indexes:
print(df.loc[[0, 1]])

# Nomeia cada linha do dataFrame em vez de enumerar

df = pd.DataFrame(data, index = ["day1", "day2", "day3"])

# Se o conjunto de dados estiver em um arquivo:

df = pd.read_csv('data.csv')


# Se o DataFrame for muito grande, podemos printar:

print(df.to_string()) 

# Para reajustar a quantidade máxima de linhas do sistema:

pd.options.display.max_rows = 9999

# Informações sobre o conjunto de dados:
print(df.info()) 
