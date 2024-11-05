#include "Pessoa.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  Pessoa einstein, newton;

  // Prepara o objeto einstein
  einstein.setNome("Albert Einstein");
  einstein.setDataDeNascimento(13, 3, 1879);
  einstein.caculaIdade(); // Calcula a idade da pessoa

  // Prepara o objeto newton
  newton.setNome("Issac Newton");
  newton.setDataDeNascimento(4, 1, 1643);
  newton.caculaIdade(); // Calcula a idade da pessoa

  // Imprime idade das pessoas
  cout << einstein.getNome() << " Idade: " << einstein.getIdade() << " anos." << endl;
  cout << newton.getNome() << " Idade: " << newton.getIdade() << " anos." << endl;

  return 0;
}