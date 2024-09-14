import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Criando uma série de cosseno
index = pd.date_range("2023-01-01", periods=100, freq="D")
data = pd.Series(np.cos(np.linspace(0, 20, 100)), index=index)

# Plotando a série
plt.figure(figsize=(10, 6))
data.plot(color='red')
plt.title('Gráfico da Série de Cosseno')
plt.xlabel('Data')
plt.ylabel('Cos(x)')
plt.grid(True)
plt.show()
