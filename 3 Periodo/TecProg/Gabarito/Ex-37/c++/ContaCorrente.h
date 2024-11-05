#pragma once

#include "Conta.h"

#define LIMITE 1000.00
#define JUROS_CC 0.1/100

class ContaCorrente : public Conta {
public:
    ContaCorrente(int id = 0);
    ~ContaCorrente();

    void aplicarJurosDiarios(int dias);
};
