from sympy import Symbol, Limit, oo, summation

# Definindo a variável simbólica
n = Symbol('n')

# Definindo a série
series_term = n**3 / (n**4 - 1)

# Calculando o limite da série
limit_expression = Limit(series_term, n, oo).doit()

# Verificando o limite
if limit_expression != 0:
    print("A série diverge pelo teste da divergência.")
else:
    # Tentando usar o Teste da Comparação com 1/n
    comparison_series = 1/n
    limit_comparison = Limit(series_term / comparison_series, n, oo).doit()

    if limit_comparison > 0 and limit_comparison < oo:
        print("A série diverge por comparação com a série harmônica (1/n).")
    else:
        # Se o teste de comparação falhar, podemos tentar outro teste, por exemplo, a soma parcial
        try:
            summation_result = summation(series_term, (n, 1, oo))
            print("A série converge. Soma:", summation_result)
        except:
            print("A série diverge.")
