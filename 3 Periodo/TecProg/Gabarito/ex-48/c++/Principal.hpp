#pragma once

#include "Inteiro.hpp"
#include "Caracter.hpp"
#include "Real.hpp"

#define TAM_MAX_VETOR 15

class Principal {
private:
    Inteiro inteiro;
    Caracter caracter;
    Real real;
public:
    Principal();
    ~Principal();
    void executar();
};