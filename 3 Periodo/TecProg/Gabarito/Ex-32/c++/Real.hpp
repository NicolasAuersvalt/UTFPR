#ifndef H_REAL
#define H_REAL

#include "Complexo.hpp"

class Real : 
    public Complexo
{
public:
    Real(double valor = 0.0);
    ~Real();

    int sinal() const; //Retorna 1 se o número for positivo e -1 se for negativo.
};

#endif