#pragma once

#include "Pilha.h"

class Inteiro {
private:
    Pilha<int> pilha_de_inteiros;
    const int tamMax;
public:
    Inteiro(int tamMax);
    ~Inteiro();
    void add_na_pilha();
    void remove_da_pilha();
    void imprimir();
};