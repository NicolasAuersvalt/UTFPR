#include "Horario.hpp"

/***
 * Construtora: inicializamos as variaveis hora e min - monitores 
 * ***/

// Construtora sem parâmetros (ou equivalente*) que toda classe deve ter por boas práticas. Prof. Simao
// *Algo equivalente seria uma construtora com parâmetros default, mas aí não poderia ter a próxima construtora. Prof. Simão
Horario::Horario() : hora(0),
                     min(0)
{
}

// Construtora com parâmetros dita sobrecarregada em relação a primeira. Prof. Simão. 
Horario::Horario(const uint8_t &_hora, const uint8_t &_min) : hora(_hora), min(_min)
{
    // Validação de tempo negativo - Prof. Simão. 
    if (hora < 0) { cout << "Recuperado o módulo do valor " << endl; hora = hora * -1; }
    if (min < 0) { cout << "Recuperado o módulo do valor " << endl; min = min * -1; }
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
void Horario::setHora(const uint8_t &_hora)
{
  //this->hora = hora;
  hora = _hora;
}

void Horario::setMin(const uint8_t &_min)
{
  // this->min = min;
  this->min = _min;
}

/***
 * Getters: Retornam a referencia a os atributos privados. 
 *          NÃO modificam os atributos da classe
 * ***/
const uint8_t &Horario::getHora() const
{
  //return this->hora;
    return hora;
}

const uint8_t &Horario::getMin() const
{
  //return this->min;
    return min;
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