#pragma once

#include "Horario.hpp"

class Principal
{
private:
    Horario entrada;
    Horario saida;
public:
    //Construtora
    Principal();

    //Destrutora
    ~Principal();

    //Obtém dos valores do horário de entrada e saída pelo terminal
    void setHorarios();

    //Calcula o custo de um intervalo de horarios
    float calculaCusto();

    void executar();
};
