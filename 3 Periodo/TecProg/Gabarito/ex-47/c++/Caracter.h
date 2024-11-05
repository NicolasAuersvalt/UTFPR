#pragma once

#include "Pilha.h"

class Caracter {
private:
    Pilha<char> pilha_de_caracteres;
    const int tamMax;
public:
    Caracter(int tamMax);
    ~Caracter();
    void add_na_pilha();
    void remove_da_pilha();
    void imprimir();
};