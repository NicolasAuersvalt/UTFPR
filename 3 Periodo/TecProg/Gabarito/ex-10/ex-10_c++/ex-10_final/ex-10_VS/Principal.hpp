#pragma once

#include "Colaborador.hpp"

class Principal
{
private:
    Colaborador colaboradores[3];
public:
    //Construtora
    Principal();

    //Destrutora
    ~Principal();

    //Obtém colaborador com maior rendimento
    Colaborador getMaiorRendimento();

    //Obtém colaborador com maior custo
    Colaborador getMaiorCusto();

    //Obtém dos valores de entrada dos colaboradores
    void getColaboradores();

    void executar();
};
