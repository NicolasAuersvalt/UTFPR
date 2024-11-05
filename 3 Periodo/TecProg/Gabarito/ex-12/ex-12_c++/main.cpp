#include "Vetor.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  // Ajusta decimais do cout
  cout.precision(5);
  // Cria vetores
  Vetor vetorA = Vetor(10.5, 10.25);
  Vetor vetorB = Vetor(2.f, 5.75);
  // Testa operadores
  Vetor vetorC = vetorA * vetorB;
  Vetor vetorD = vetorA + vetorB;
  // Imprime valor dos vetores
  cout << "Vetor A -> (" << vetorA.getX() << ", " << vetorA.getY() << ")" << endl;
  cout << "Vetor B -> (" << vetorB.getX() << ", " << vetorB.getY() << ")" << endl;
  cout << "Vetor C -> (" << vetorC.getX() << ", " << vetorC.getY() << ")" << endl;
  cout << "Vetor D -> (" << vetorD.getX() << ", " << vetorD.getY() << ")" << endl;

  return 0;
}