import pandas as pd 
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt 
import seaborn as sns
import numpy as np
from sklearn.datasets import make_blobs
from scipy.stats import norm
from sklearn.cluster import KMeans
# from scipy.cluster.hierarchy import dendrogram, linkage
from scipy.spatial.distance import pdist
from sklearn.model_selection import KFold
from sklearn.metrics import silhouette_score
from sklearn.decomposition import PCA
from scipy.cluster.hierarchy import linkage, fcluster, dendrogram
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.model_selection import cross_val_score
