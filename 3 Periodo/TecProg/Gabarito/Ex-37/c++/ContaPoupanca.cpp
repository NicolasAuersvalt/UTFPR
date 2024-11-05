#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(int id) :
Conta(id) {
}

ContaPoupanca::~ContaPoupanca() {
}

void ContaPoupanca::aplicarJurosDiarios(int dias) {
    for (int i = 0; i < dias; i++) {
        saldo += JUROS_CP * saldo;
    }
}
