#include "ContaEspecial.hpp"

ContaEspecial::ContaEspecial():
    ContaCorrente() {

}

ContaEspecial::~ContaEspecial() {

}

void ContaEspecial::sacar(const double valor) {
    double taxa = valor * 0.01; // 1% de taxa sobre o valor sacado

    if(valor < 0.0) {
        cout << "Valor de saque invalido" << endl;
    }
    else if(valor + taxa > saldo) {
        cout << "Saldo insuficiente para saque!" << endl;
    }
    else {
        saldo -= valor + taxa;
    }
}