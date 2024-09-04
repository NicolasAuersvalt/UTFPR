import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from scipy.stats import norm
from sklearn.datasets import load_iris

# Load the iris dataset
iris = load_iris(as_frame=True)
df = iris.frame

# Plot settings
sns.set(style="whitegrid")

# Histograms with normal distribution curves
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
plt.show()
