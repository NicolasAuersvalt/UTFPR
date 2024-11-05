#pragma once

#include "Horario.hpp"

class Principal {
  public:
    Principal();
    ~Principal();

    void PerguntaHorarios();

    int CalculaIntervalo();

    float CalculaCusto();

    void Executar();

  private:
    Horario mHorarioEntrada;
    Horario mHorarioSaida;
};
