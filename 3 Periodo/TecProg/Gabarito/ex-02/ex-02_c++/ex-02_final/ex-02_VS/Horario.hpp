#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define HORA_PARA_MIN 60
#define MIN_POR_DIA 1440
#define MAX_MIN 59
#define MAX_HORA 23

class Horario
{
private:
    int hora, min;

public:
    //Construtoras
    Horario(int h, int m);
    Horario();

    //Destrutora
    ~Horario();

    //Funções Set's
    bool setHora(int h);
    bool setMin(int m);

    //Funções Get's
    int getHora();
    int getMin();

    //Calcula o intervalo de tempo com um horário dado
    int calculaIntervalo(Horario horario);
};
