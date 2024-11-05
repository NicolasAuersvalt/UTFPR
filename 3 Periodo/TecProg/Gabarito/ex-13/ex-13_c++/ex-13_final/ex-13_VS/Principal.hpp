#pragma once

#include "Vetor.hpp"

class Principal
{
private:
    Vetor v1, v2;
public:
    //Construtora
    Principal();

    //Destrutora
    ~Principal();

    void executar();

    void getEntradas();
};
