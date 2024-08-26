from sympy import Symbol, oo, sqrt, summation, Limit

# Definindo a variável simbólica
n = Symbol('n')

# Definindo o termo da série
series_term = 1 / sqrt(n**2 + 1)

# Calculando o limite do termo geral da série
limit_expression = Limit(series_term, n, oo).doit()

# Verificando o limite
if limit_expression != 0:
    print("A série diverge pelo teste da divergência.")
else:
    # Teste de Comparação com a série 1/n
    comparison_series = 1 / n
    limit_comparison = Limit(series_term / comparison_series, n, oo).doit()

    if 0 < limit_comparison < oo:
        print("A série diverge por comparação com a série harmônica (1/n).")
    else:
        print("A série requer outro teste para determinar a convergência.")
