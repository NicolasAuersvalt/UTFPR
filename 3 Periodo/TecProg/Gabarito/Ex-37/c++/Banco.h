#pragma once

#include <vector>
using namespace std;

class Conta;

class Banco {
private:
    vector<Conta*> contas;
    static int idConta;

public:
    Banco();
    ~Banco();

    void criarNovaConta();
    void exec();
    void lerSaldo();
    void depositarEmConta();
    void sacar();
    void aplicarJuros();
    int MenuPrincipal() const;
    Conta* encontraConta();
};