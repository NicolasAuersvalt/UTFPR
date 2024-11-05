#include "Pessoa.hpp"
#include "Universidade.hpp"
#include "Departamento.hpp"
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

  // Criamos os departamentos
  Departamento dFisicaPrinceton("Departamento de Física", &princeton);
  Departamento dMatematicaPrinceton("Departamento de Matemática", &cambridge);

  // Associamos os departamentos as universidades
  princeton.setDepartamento(&dFisicaPrinceton);
  cambridge.setDepartamento(&dMatematicaPrinceton);

  // Criamos as pessoas
  Pessoa einstein, newton;

  // Prepara o objeto einstein
  einstein.setNome("Albert Einstein");
  einstein.setDataDeNascimento(13, 3, 1879);
  einstein.setDepartamento(&dFisicaPrinceton);

  // Prepara o objeto newton
  newton.setNome("Issac Newton");
  newton.setDataDeNascimento(4, 1, 1643);
  newton.setDepartamento(&dMatematicaPrinceton);

  // Imprime informações
  einstein.imprimeInformacao();
  newton.imprimeInformacao();
  return 0;
}