import streamlit as st
from scipy.stats import norm
import numpy as np

# Título da aplicação
st.title('Calculadora de Intervalo de Confiança para Média)

# Inputs do usuário com precisão maior
media = st.number_input("Média:", min_value=-100.0, max_value=100.0, value=1.0, format="%.6f")
confiança = st.number_input("Valor de Confiança (%) :", min_value=0.0, max_value=100.0, value=95.0, format="%.6f")
sd = st.number_input("Desvio Padrão:", min_value=0.1, max_value=1000.0, value=1.0, format="%.6f")
n = st.number_input("Tamanho da amostra:", min_value=1, max_value=1000, value=1)

z = st.number_input("Z :", min_value=0.0, max_value=100.0, value=95.0, format="%.6f")

# Cálculos
# Calcula o valor z com maior precisão
# z_value = abs(norm.ppf((1 - (confiança / 100)) / 2))  # Valor z para intervalo de confiança
LI = media - (z * sd / np.sqrt(n))  # Limite inferior
LS = media + (z * sd / np.sqrt(n))  # Limite superior

# Exibição dos resultados com precisão de 6 casas decimais
st.text(f"Limite inferior: {LI:.6f}")
st.text(f"Limite superior: {LS:.6f}")
  