#include "Conta.h"

Conta::Conta(int id) :
conta(id),
saldo(0) { }

Conta::~Conta() {
}

void Conta::depositar(double quantia) {
    if (quantia <= 0.0)
        return;

    saldo += quantia;
}

double Conta::getSaldo() const {
    return saldo;
}

bool Conta::sacar(double quantia) {
    if (saldo - quantia < 0.0)
        return false;

    saldo -= quantia;
    return true;
}
