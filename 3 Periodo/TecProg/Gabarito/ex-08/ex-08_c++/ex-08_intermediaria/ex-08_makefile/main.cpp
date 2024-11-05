#include "Carro.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  /* 
    Consumo: 12 quilômetros por litro de combustível 
    Capacidade: 45 litros
  */
  Carro gol = Carro(12, 45);
  gol.abastecer(20); // Abastece com 20 litros de combustível.
  /* 
    Consumo: 14 quilômetros por litro de combustível 
    Capacidade: 40 litros
  */
  Carro uno = Carro(14, 40);
  // Abastece com 250 litros de combustível.
  // Para verificar que carrega unicamente até sua capacidade máxima
  uno.abastecer(250);

  uno.andar(150);                   // Anda 150 quilômetros.
  int sobra = uno.getCombustivel(); // Exibe o combustível que resta
  cout << "Litros restantes no Uno: " << sobra << endl;

  gol.andar(80); // Anda 80 quilômetros.
  sobra = gol.getCombustivel();
  cout << "Litros restantes no Gol: " << sobra << endl;

  return 0;
}