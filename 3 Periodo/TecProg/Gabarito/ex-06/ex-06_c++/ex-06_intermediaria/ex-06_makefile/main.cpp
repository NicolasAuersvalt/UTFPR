#include "Pessoa.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  // Inicializa objetos de pessoa diretamente com a construtora.
  Pessoa
      einstein = Pessoa("Albert Einstein", 13, 3, 1879),
      newton = Pessoa("Issac Newton", 4, 1, 1643);

  // Calculamos as idades.
  // Note-se que não precisamos chamar o método setDataNascimento,
  // já que pasamos a data diretamente na contrutora.
  einstein.caculaIdade(); // Calcula a idade da pessoa
  newton.caculaIdade();   // Calcula a idade da pessoa

  // Imprime idade das pessoas
  cout << einstein.getNome() << " Idade: " << einstein.getIdade() << " anos." << endl;
  cout << newton.getNome() << " Idade: " << newton.getIdade() << " anos." << endl;

  return 0;
}