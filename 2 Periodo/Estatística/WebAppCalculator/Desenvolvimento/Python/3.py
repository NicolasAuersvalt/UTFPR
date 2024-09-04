import streamlit as st
from scipy.stats import norm

# Definir a interface do usuário
st.title('Calculadora do Tamanho da Amostra para a Média')

# Entrada do usuário
margem_erro = st.number_input('Margem de Erro :', min_value=-100.0, max_value=100.0, value=1.0)
conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=1.0)
desvio_padrao = st.number_input('Desvio Padrão :', min_value=0.1, max_value=1000.0, value=1.0)

# Cálculos e Saída
if margem_erro != 0:
    z = abs(norm.ppf((1 + (conf / 100)) / 2))
    tamanho_amostra = ((z * desvio_padrao) / margem_erro) ** 2

    st.write(f'Tamanho da Amostra para Média: {tamanho_amostra:.2f}')
else:
    st.write('Erro: A margem de erro não pode ser zero.')
