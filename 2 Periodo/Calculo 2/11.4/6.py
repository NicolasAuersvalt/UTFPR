from sympy import Symbol, oo, summation, simplify

# Definindo a variável simbólica
n = Symbol('n')

# Definindo o termo da série
series_term = (n - 1) / (n**2 * (n**(1/2)))

# Simplificando o termo da série
simplified_term = simplify(series_term)

# Verificando a simplificação
print("Termo simplificado da série:", simplified_term)

# Teste da divergência - verificando o limite do termo geral
limit_expression = simplified_term.limit(n, oo)

if limit_expression != 0:
    print("A série diverge pelo teste da divergência.")
else:
    # Tentando usar a série p com p = 3/2 que é convergente
    comparison_series = 1/n**(3/2)
    limit_comparison = (simplified_term / comparison_series).limit(n, oo)

    if 0 < limit_comparison < oo:
        print("A série converge por comparação com a série p (p = 3/2).")
    else:
        print("A série requer outro teste para determinar convergência.")
