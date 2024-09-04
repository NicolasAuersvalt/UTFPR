import streamlit as st
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.model_selection import cross_val_score
from scipy.spatial.distance import pdist
from scipy.cluster.hierarchy import linkage, fcluster, dendrogram
from sklearn.datasets import load_iris
from sklearn.cluster import KMeans
import seaborn as sns
import pandas as pd