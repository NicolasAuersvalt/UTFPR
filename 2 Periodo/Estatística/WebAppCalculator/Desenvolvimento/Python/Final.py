from header import *

# Funções para as páginas
def calcular_intervalo_confianca():
    # Título da aplicação
    st.title('Calculadora de Intervalo de Confiança para Média')

    # Inputs do usuário com precisão maior
    media = st.number_input("Média:", min_value=-100.0, max_value=100.0, value=1.0, format="%.6f")
    confiança = st.number_input("Valor de Confiança (%) :", min_value=0.0, max_value=100.0, value=95.0, format="%.6f")
    sd = st.number_input("Desvio Padrão:", min_value=0.1, max_value=1000.0, value=1.0, format="%.6f")
    n = st.number_input("Tamanho da amostra:", min_value=1, max_value=1000, value=30)

    # Cálculos
    z = abs(norm.ppf((1 + (confiança / 100)) / 2))  # Valor z para intervalo de confiança
    LI = media - (z * sd / np.sqrt(n))  # Limite inferior
    LS = media + (z * sd / np.sqrt(n))  # Limite superior

    # Exibição dos resultados com precisão de 6 casas decimais
    st.text(f"Limite inferior: {LI:.6f}")
    st.text(f"Limite superior: {LS:.6f}")

    # Gráfico
    fig, ax = plt.subplots()
    ax.barh(['Média'], [media], xerr=[(LS - LI) / 2], color='skyblue', alpha=0.7)
    ax.set_xlim(LI - (LS - LI), LS + (LS - LI))
    ax.axvline(x=LI, color='red', linestyle='--', label=f'Limite Inferior ({LI:.6f})')
    ax.axvline(x=LS, color='green', linestyle='--', label=f'Limite Superior ({LS:.6f})')
    ax.legend()
    st.pyplot(fig)

def calculadora_proporcao():
    # Definir a interface do usuário
    st.title('Calculadora de Intervalo de Confiança para Proporção')

    # Entrada do usuário
    p = st.number_input('p :', min_value=0.0, max_value=1.0, value=0.5, format="%.6f")
    conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=95.0, format="%.6f")
    n = st.number_input('Tamanho da amostra :', min_value=1, max_value=1000, value=30)

    # Cálculos e Saída
    z = abs(norm.ppf((1 + (conf / 100)) / 2))

    if 0 <= p <= 1:
        LI = p - (z * np.sqrt((p * (1 - p)) / n))
        LS = p + (z * np.sqrt((p * (1 - p)) / n))

        st.write(f'Limite inferior: {LI:.6f}')
        st.write(f'Limite superior: {LS:.6f}')

        # Gráfico
        fig, ax = plt.subplots()
        ax.barh(['Proporção'], [p], xerr=[(LS - LI) / 2], color='skyblue', alpha=0.7)
        ax.set_xlim(LI - (LS - LI), LS + (LS - LI))
        ax.axvline(x=LI, color='red', linestyle='--', label=f'Limite Inferior ({LI:.6f})')
        ax.axvline(x=LS, color='green', linestyle='--', label=f'Limite Superior ({LS:.6f})')
        ax.legend()
        st.pyplot(fig)
    else:
        st.write('Erro: o valor de p deve estar entre 0 e 1.')

def calcular_tamanho_amostra_media():
    st.title('Calculadora do Tamanho da Amostra para a Média')

    # Entrada do usuário
    margem_erro = st.number_input('Margem de Erro :', min_value=0.1, max_value=100.0, value=1.0)
    conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=95.0)
    desvio_padrao = st.number_input('Desvio Padrão :', min_value=0.1, max_value=1000.0, value=1.0)

    # Cálculos e Saída
    z = abs(norm.ppf((1 + (conf / 100)) / 2))
    tamanho_amostra = ((z * desvio_padrao) / margem_erro) ** 2

    st.write(f'Tamanho da Amostra para Média: {tamanho_amostra:.2f}')

def calcular_tamanho_amostra_proporcao():
    st.title('Calculadora do Tamanho da Amostra para Proporção')

    # Entrada do usuário
    margem_erro = st.number_input('Margem de Erro (%) :', min_value=0.0, max_value=100.0, value=1.0)
    conf = st.number_input('Valor de Confiança (%) :', min_value=0.0, max_value=100.0, value=95.0)

    # Cálculos e Saída
    z = abs(norm.ppf((1 + (conf / 100)) / 2))
    tamanho_amostra = ((z**2 * 0.5 * 0.5) / (margem_erro / 100)**2)

    st.write(f'Tamanho da Amostra para Proporção: {tamanho_amostra:.2f}')

# Menu Principal
def main():
    st.sidebar.title("Menu")
    option = st.sidebar.selectbox("Escolha uma Calculadora:", 
                                  ["Intervalo de Confiança para Média",
                                   "Intervalo de Confiança para Proporção",
                                   "Tamanho da Amostra para a Média", 
                                   "Tamanho da Amostra para Proporção"])

    if option == "Intervalo de Confiança para Média":
        calcular_intervalo_confianca()
    elif option == "Intervalo de Confiança para Proporção":
        calculadora_proporcao()
    elif option == "Tamanho da Amostra para a Média":
        calcular_tamanho_amostra_media()
    elif option == "Tamanho da Amostra para Proporção":
        calcular_tamanho_amostra_proporcao()

if __name__ == "__main__":
    main()
