#include <iostream>

#include "ContaCorrente.hpp"
#include "ContaEspecial.hpp"

int main()
{
    ContaCorrente contaCorrente;
    ContaEspecial contaEspecial;
    double valor;

    valor = 1000.0;
    cout << "Valor depositado em ambas contas: R$ " << valor << endl;
    contaCorrente.depositar(valor);
    contaEspecial.depositar(valor);

    valor = 100.0;
    cout << "Valor sacado em ambas contas: R$ " << valor << endl;  
    contaEspecial.sacar(valor);
    contaCorrente.sacar(valor);

    cout << "Saldo conta corrente apos o saque: R$: " << contaCorrente.getSaldo() << endl;
    cout << "Saldo conta especial apos o saque: R$: " << contaEspecial.getSaldo() << endl;

    return 0;
}