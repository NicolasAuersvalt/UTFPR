#pragma once

#include "Inteiro.h"
#include "Caracter.h"

#define TAM_MAX_PILHA_INTEIROS 5
#define TAM_MAX_PILHA_CARACTERES 5

class Principal {
    private:
        Inteiro pilha_de_inteiros;
        Caracter pilha_de_caracter;
        int num;
    public:
        Principal();
        ~Principal();
        void executarInteiro();
        void executarCaracter();

};