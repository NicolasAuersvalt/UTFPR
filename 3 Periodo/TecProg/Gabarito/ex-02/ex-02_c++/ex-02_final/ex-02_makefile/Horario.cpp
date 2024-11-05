#include "Horario.hpp"

Horario::Horario(int horas, int minutos) {
  if (horas < 0 || horas > MAX_HORA || minutos < 0 || minutos > MAX_MIN) {
    std::cerr << "Erro de Execução: Horário com valores incorretos." << std::endl;
    mValidade = false;
  }
}

Horario::Horario() : mHoras{0}, mMinutos{0}, mValidade{true}{

}

Horario::~Horario() {

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

bool Horario::GetValidade() {
  return mValidade;
}
