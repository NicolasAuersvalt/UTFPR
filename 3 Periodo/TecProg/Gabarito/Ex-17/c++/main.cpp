#include "Pessoa.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  // Criamos as universidades
  Universidade princeton, cambridge;

  // Colocamos seus nomes correspondentes
  princeton.setNome("Princeton");
  cambridge.setNome("Cambridge");

  // Criamos as pessoas
  Pessoa einstein, newton;

  // Prepara o objeto einstein
  einstein.setNome("Albert Einstein");
  einstein.setDataDeNascimento(13, 3, 1879);
  einstein.setUniversidade(&princeton);

  // Prepara o objeto newton
  newton.setNome("Issac Newton");
  newton.setDataDeNascimento(4, 1, 1643);
  newton.setUniversidade(&cambridge);

  // Imprime informações
  einstein.imprimeInformacao();
  newton.imprimeInformacao();
  return 0;
}