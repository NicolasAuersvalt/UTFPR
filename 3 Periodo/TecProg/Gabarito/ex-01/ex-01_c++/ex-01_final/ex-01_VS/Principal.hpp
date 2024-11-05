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

    //Funções Set's
    void setHorarioEntrada(int h, int m);
    void setHorarioSaida(int h, int m);

    //Obtém dos valores do horário de entrada e saída pelo terminal
    void setHorarios();

    //Calcula a diferença entre horarios
    int calculaIntervalo();

    //Calcula o custo de um intervalo de horarios
    float calculaCusto();

    void executar();
};
