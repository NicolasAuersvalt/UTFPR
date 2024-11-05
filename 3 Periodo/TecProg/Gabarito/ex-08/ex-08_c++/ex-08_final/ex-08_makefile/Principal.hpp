#pragma once

#include "Carro.hpp"

class Principal
{
private:
    Carro gol, uno;
public:
    //Construtora
    Principal();

    //Destrutora
    ~Principal();

    void executar();
};
