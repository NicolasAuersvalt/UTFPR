#include "Horario.hpp"

Horario::Horario() : mHoras{0}, mMinutos{0}  {

}

Horario::~Horario() {

}

bool Horario::SetHora(int horas) {
  if (horas >= 0 && horas <= MAX_HORA) {
    mHoras = horas;
    return true;
  }
  return false;
}

bool Horario::SetMin(int minutos) {
  if (minutos >= 0 && minutos <= MAX_MIN) {
    mMinutos = minutos;
    return true;
  }
  return false;
}

int Horario::GetHora() {
  return mHoras;
}

int Horario::GetMin() {
  return mMinutos;
}

int Horario::CalculaIntervalo(Horario horarioSaida) {
  int intervalo = (horarioSaida.GetHora() - mHoras) * MIN_POR_HORA + horarioSaida.GetMin() - mMinutos;

  return intervalo >= 0 ? intervalo : -intervalo + MIN_POR_DIA;
}
