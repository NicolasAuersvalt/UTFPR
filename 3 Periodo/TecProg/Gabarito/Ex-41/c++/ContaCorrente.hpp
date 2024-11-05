#pragma once

#include <iostream>
using std::cout;
using std::endl;

class ContaCorrente
{
protected:
    double saldo;

public:
    ContaCorrente();
    ~ContaCorrente();

    void depositar(const double valor);
    virtual void sacar(const double valor);
    double getSaldo() const;
};