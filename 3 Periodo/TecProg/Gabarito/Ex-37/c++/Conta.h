#pragma once

class Conta {
protected:
    double saldo;
    int conta;

public:
    Conta(int id = -1);
    ~Conta();

    void depositar(double quantia);
    double getSaldo() const;
    bool sacar(double quantia);
    virtual void aplicarJurosDiarios(int dias) = 0;
    int getNumeroConta() const { return conta; }
};
