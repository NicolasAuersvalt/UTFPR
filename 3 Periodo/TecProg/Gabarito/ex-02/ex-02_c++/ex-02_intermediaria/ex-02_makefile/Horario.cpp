#include "Horario.hpp"

/***
 * Construtora: inicializamos as variaveis hora e min
 * ***/
Horario::Horario() : hora(0),
                     min(0)
{
}

Horario::Horario(const uint8_t &hora, const uint8_t &min) : hora(hora), min(min)
{
}
/***
 * Destrutora
 * ***/
Horario ::~Horario()
{
}

/***
 * Setters: Atualizam os atributos privados
 * ***/
void Horario::setHora(const uint8_t &hora)
{
  this->hora = hora;
}

void Horario::setMin(const uint8_t &min)
{
  this->min = min;
}

/***
 * Getters: Retornam a referencia a os atributos privados. 
 *          NÃO modificam os atributos da classe
 * ***/
const uint8_t &Horario::getHora() const
{
  return this->hora;
}

const uint8_t &Horario::getMin() const
{
  return this->min;
}

/***
 * Calcula a diferença entre os horarios
 * ***/
int Horario::calcularIntervalo(const Horario &h) const
{
  // Calcula deferença entre horarios
  int intervalo = (h.getHora() * 60 + h.getMin()) -
                  (hora * 60 + min);
  // Se for negativo quer dizer que mudou de dia
  if (intervalo < 0)
    // Soma o tempo de 1 dia
    intervalo = intervalo + 1440;

  return intervalo;
}