from sympy import Symbol, oo, ln, Limit

# Definindo a variável simbólica
n = Symbol('n')

# Definindo o termo da série alternada
series_term = (-1)**(n-1) / ln(n + 4)

# Verificando se os termos convergem para zero
limit_expression = Limit(1 / ln(n + 4), n, oo).doit()

# Verificando o limite
if limit_expression == 0:
    # A série converge pelo teste da série alternada
    print("A série converge pelo Teste da Série Alternada.")
else:
    print("A série diverge.")
