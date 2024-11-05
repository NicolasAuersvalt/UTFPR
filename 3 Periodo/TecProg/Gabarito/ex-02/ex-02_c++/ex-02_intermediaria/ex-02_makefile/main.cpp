#include "Horario.hpp"
#include <iostream>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;

#define MAX_HORA 24
#define MAX_MIN 60
int main(int argc, char **argv)
{
  Horario *entrada = NULL, *saida = NULL;
  int h = 0, m = 0;

  // Obtem horario de entrada
  cout << "Digite a entrada: HORA MIN" << endl;
  cin >> h >> m;
  // Verifica valores ingresado
  assert(h < MAX_HORA);
  assert(m < MAX_MIN);
  entrada = new Horario(h, m);
  // Obtem horario de saida
  cout << "Digite a saida: HORA MIN" << endl;
  cin >> h >> m;

  // Verifica valores ingresado
  assert(h < MAX_HORA);
  assert(m < MAX_MIN);
  saida = new Horario(h, m);

  // Calcula intervalo
  int intervalo = entrada->calcularIntervalo(*saida);

  // Libera memoria
  delete entrada;
  delete saida;

  double preco = 0;
  // Calcula o preço
  if (intervalo < 3 * 60)
  {
    preco = 4.5;
  }
  else if (intervalo < 12 * 60)
  {
    // Calcular quantos intervalos de 15 min
    // existem no horario excedente
    int aux = (intervalo - 3 * 60) / 15;
    // Se não deu multiplo de 15 min, deve
    // cobrar um intervalo a mais
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