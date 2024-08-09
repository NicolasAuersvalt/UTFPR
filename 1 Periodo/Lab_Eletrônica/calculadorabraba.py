# Testar em: https://www.programiz.com/python-programming/online-compiler/
print("====/====/====/====/====/==== \n")

print("Calculadorazinha da atividade 7 de eletrônica \n")

print("Atenção nas unidades!\n")

print("====/====/====/====/====/==== \n")

print("Digite a capacitância (F): \n")
c = float(input())

print("Digite 1° resistência (Ω): \n")
ra = float(input())

print("Digite 2° resistência (Ω): \n")
rb = float(input())


th = float(((0.6931) * (ra+rb) * c)) # TESTADO

tl = float(((0.6931)  * rb * c)) #  TESTADO

t = float(th+tl) #  TESTADO

f = float(1/t) #  TESTADO

d = float(th/t) #  TESTADO

print("====/====/====/====/====/==== \n")

print("O valor do TH é de aproximadamente: {:.3f}s\n".format(th))

print("O valor de TL é de aproximadamente: {:.3f}s\n".format(tl))

print("O valor da f é de aproximadamente: {:.3f}Hz\n".format(f))

print("O valor de T é de aproximadamente: {:.3f}v\n".format(t))

print("O valor de D é de aproximadamente: {:.3f}% \n".format(d))

print("====/====/====/====/====/==== \n")

print("Digite BÃO para sair: ")
a = input()
