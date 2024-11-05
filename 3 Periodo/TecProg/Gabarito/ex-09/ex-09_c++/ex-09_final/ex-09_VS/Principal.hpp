#pragma once

#include "Carro.hpp"

class Principal
{
private:
    Carro gol;
public:
    //Construtora
    Principal();

    //Destrutora
    ~Principal();

    void setViajem();

    void executar();
};
