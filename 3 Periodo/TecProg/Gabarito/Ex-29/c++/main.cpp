#include "CarroEsporte.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  int sobra;

  CarroEsporte ferrari = CarroEsporte(16, 60, 100, 15, 80);
  /*
    Consumo: 16 quilômetros por litro de combustível (+ 50% do consumo)
    Capacidade: 60 litros
    Tamanho do Spoiler: 100
    Número de Adesivos Tuning: 15
    Potência Extra do Turbo: 80
  */
  ferrari.abastecer(50); // Abastece com 50 litros
  ferrari.andar(320); // Anda 320 quilômetros
  
  sobra = ferrari.getCombustivel();
  cout << "Litros restantes na Ferrari: " << sobra << endl;

  // Informando os atributos do exercício
  cout << "Tamanho do Spoiler na Ferrari: " << ferrari.getTamSpoiler() << endl
       << "Número de Adesivos Tuning na Ferrari: " << ferrari.getNumAdesivosTuning() << endl
       << "Potência Extra do Turbo na Ferrari: " << ferrari.getPotExtTurbo() << endl;
        
  // Acelerando para verificar quanto de combustível é perdido
  ferrari.acelerar();
  cout << "Litros restantes na Ferrari: " << ferrari.getCombustivel() << endl;

  return 0;
}