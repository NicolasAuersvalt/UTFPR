#pragma once

#include "Conta.h"

#define JUROS_CP 0.2/100

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(int id = 0);
    ~ContaPoupanca();

    void aplicarJurosDiarios(int dias);
};
