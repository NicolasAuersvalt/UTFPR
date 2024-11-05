#include "ContaCorrente.hpp"

ContaCorrente::ContaCorrente() {
    this->saldo = 0.0;
}

ContaCorrente::~ContaCorrente() {

}

void ContaCorrente::depositar(const double valor) {
    if(valor > 0.) {
        this->saldo += valor;
    }
    else {
        cout << "Valor de deposito invalido!" << endl;
    }
}

void ContaCorrente::sacar(const double valor) {
    double taxa = valor * 0.05; // 5% de taxa sobre o valor sacado

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

double ContaCorrente::getSaldo() const {
    return this->saldo;
}