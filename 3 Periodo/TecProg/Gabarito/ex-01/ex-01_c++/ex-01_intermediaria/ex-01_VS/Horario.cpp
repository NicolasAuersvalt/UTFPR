#include "Horario.hpp"

// Código com comentário e ajustes. Prof. Simão. 

/***
 * Construtora: inicializamos as variaveis hora e min - monitor
 * ***/

Horario::Horario() : hora(0),
                     min(0)
{
    // Acima, a forma mais OO de inicializar atributos, chamando suas construtoras. 
    // Também há quem prefira fazer do formato mais "usual", cf. comentado abaixo. Prof. Simão

    // hora = 0;
    // min  = 0;

    // Caso se descomente as duas linhas acima, funciona. 
    // Só iria se inicializar redundantemente os atributos duas vezes, entretanto. Prof. Simão. 
}

/***
 * Destrutora - Monitor
 * ***/
Horario ::~Horario()
{
}

/***
 * Setters: Atualizam os atributos privados - monitor 
 * ***/
void Horario::setHora(const uint8_t &_hora)  // Aqui o parâmetro poderia ser só o valor mesmo, sem referência (&). Mas tudo bem enfim. 
{
    // this->hora = _hora; // Eu evito este tipo de construção porque não agrega muito. A explicação para tal é antes o parâmetro estava com o mesmo nome do atributo, entretanto.
    hora = _hora;
}

void Horario::setMin(const uint8_t &_min) // Aqui o parâmetro poderia ser só o valor mesmo, sem referência (&). Mas tudo bem enfim. 
{
    // this->min = min; // Eu evito este tipo de construção porque não agrega muito. A explicação para tal é antes o parâmetro estava com o mesmo nome do atributo, entretanto.
    min = _min;
}

/***
 * Getters: Retornam a referencia a os atributos privados. 
 *          NÃO modificam os atributos da classe
 * ***/
const uint8_t &Horario::getHora() const // Aqui o retorno poderia ser só o valor mesmo, sem referência (&). Mas tudo bem enfim. 

{
    // return this->hora;
    return hora;
}

const uint8_t &Horario::getMin() const // Aqui o retorno poderia ser só o valor mesmo, sem referência (&). Mas tudo bem enfim. 

{
    //return this->min;
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