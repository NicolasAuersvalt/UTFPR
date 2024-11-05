#include "Principal.hpp"

Principal::Principal() {

}

Principal::~Principal() {

}

void Principal::PerguntaHorarios() {
  int horas, minutos;

  std::cout << "Escreva o horário de entrada {hh} {mm}: ";
  std::cin >> horas >> minutos;

  mHorarioEntrada = Horario{horas, minutos};
  if (!mHorarioEntrada.GetValidade())
    return;

  std::cout << "Escreve o horário de saída {hh} {mm}: ";
  std::cin >> horas >> minutos;

  mHorarioSaida = Horario{horas, minutos};
  if (!mHorarioSaida.GetValidade())
    return;
  
}

float Principal::CalculaCusto() {
  float custo;
  int intervalo = mHorarioEntrada.CalculaIntervalo(mHorarioSaida);

  if (intervalo < 3 * MIN_POR_HORA)
    custo = 4.5; 
  else if (intervalo >= 3 * MIN_POR_HORA && intervalo <= 12 * MIN_POR_HORA)
    custo = 4.5 + ((intervalo - 3 * MIN_POR_HORA) / 15) * 0.75;
  else
    custo = 33.0; 

  return custo;
}

void Principal::Executar() {
  PerguntaHorarios();

  std::cout << "O custo foi de R$" << CalculaCusto() << std::endl;
}
