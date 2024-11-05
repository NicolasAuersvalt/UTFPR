#pragma once

#include <iostream>

#define MIN_POR_HORA 60
#define MIN_POR_DIA 1440
#define MAX_MIN 59
#define MAX_HORA 23

class Horario {
  public:
    Horario();
    ~Horario();

    bool SetHora(int horas);
    bool SetMin(int minutos);

    int GetHora();
    int GetMin();

    int CalculaIntervalo(Horario horarioSaida);

  private:
    int mHoras, mMinutos;
};
