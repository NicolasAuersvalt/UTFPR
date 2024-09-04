import streamlit as st
import numpy as np
from scipy.stats import norm

# Definir a interface do usuário
st.title('Calculadora de Intervalo de Confiança para Proporção)

# Entrada do usuário
p = st.number_input('p :', min_value=-100.0, max_value=100.0, value=1.0)
conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=1.0)
n = st.number_input('Tamanho da amostra :', min_value=1, max_value=1000, value=1)

# Cálculos e Saída
z = abs(norm.ppf((1 + (conf / 100)) / 2))

# Verificar se os valores inseridos são válidos para o cálculo
if 0 <= p <= 1:
    LI = p - (z * np.sqrt((p * (1 - p)) / n))
    LS = p + (z * np.sqrt((p * (1 - p)) / n))

    st.write(f'Limite inferior: {LI}')
    st.write(f'Limite superior: {LS}')
else:
    st.write('Erro: o valor de p deve estar entre 0 e 1.')
