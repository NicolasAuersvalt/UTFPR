#include <iostream>
#include <assert.h>
#include "C1.hpp"
#include "C3.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  // Cria objetos
  p1::C1 c1; // Deve-se usar p1:: para aceder à classe por causa que ela encontra-se nesse namespace
  p2::C3 c3;
  // Utiliza Setters
  c1.setA1(1);
  c3.setA3(1);
  // Utiloza Getters
  c1.getA1();
  c3.getA3();
  // Chama executar do objeto c3
  c3.executar();
  return 0;
}