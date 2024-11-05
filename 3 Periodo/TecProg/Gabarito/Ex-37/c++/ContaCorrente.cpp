#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(int id) :
Conta(id) {
}

ContaCorrente::~ContaCorrente() {
}

void ContaCorrente::aplicarJurosDiarios(int dias) {
    double excedente;

    for (int i = 0; i < dias; i++) {
        excedente = saldo - LIMITE;
        if (excedente > 0)
            saldo -= JUROS_CC * excedente;
    }
}