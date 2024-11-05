
// Código com comentário e ajustes. Prof. Simão. 

// Uma primeira critica geral a solução feita por monitores (em semestre anterior - 2 Sem 2021) é   
// que o exercício pede explicitamente uma classe princial, o que (ainda) não existe. Prof. Simão.

#include "Horario.hpp"
#include <assert.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_HORA 24
#define MAX_MIN 60

int main(int argc, char **argv)
{
  Horario entrada, saida;
  int h = 0, m = 0;

  // Obtem horario de entrada - monitores do 2o Sem 2021
  cout << "Digite a entrada: HORA MIN" << endl;
  cin >> h >> m;

  // Verifica valores ingresado - monitor 
  assert(h < MAX_HORA);
  assert(m < MAX_MIN);
  entrada.setHora((uint8_t)h);
  entrada.setMin((uint8_t)m);

  // Obtem horario de saida - monitor
  cout << "Digite a saida: HORA MIN" << endl;
  cin.clear();
  cin.ignore(10000, '\n');
  cin >> h >> m;

  // Verifica valores ingresado - monitor
  assert(h < MAX_HORA);
  assert(m < MAX_MIN);
  saida.setHora((uint8_t)h);
  saida.setMin((uint8_t)m);

  // Calcula intervalo - monitor
  int intervalo = entrada.calcularIntervalo(saida);

  double preco = 0;
  // Calcula o preço - monitor
  if (intervalo < 3 * 60)
  {
    preco = 4.5;
  }
  else if (intervalo < 12 * 60)
  {
    // Calcular quantos intervalos de 15 min
    // existem no horario excedente - monitor
    int aux = (intervalo - 3 * 60) / 15;

    // Se não deu multiplo de 15 min, deve
    // cobrar um intervalo a mais - monitor
    if (((intervalo - 3 * 60) % 15) != 0)
      aux++;
    preco = 4.5 + aux * 0.75;
  }
  else
  {
    preco = 33;
  }
  cout << "Preço = " << preco << endl;
  return 0;
}
