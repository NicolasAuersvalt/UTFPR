#include "Cliente.hpp"
#include "Conta.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main()
{
  // Criamos os clientes
  Cliente clienteA = Cliente("Ned Stark", "000.000.000-00");
  Cliente clienteB = Cliente("John Snow", "111.000.000-00");
  // Criamos as contas
  Conta contaA = Conta(0);
  Conta contaB = Conta(1);
  Conta contaC = Conta(2);
  // Adicionamos um valor inicial as contas
  contaA.depositar(10.f);
  contaB.depositar(20.f);
  contaC.depositar(50.f);
  // Associamos a contaA com o clienteA
  contaA.setTitular(&clienteA);
  clienteA.adicionarConta(&contaA);
  // Adicionamos a contaC para o clienteA
  clienteA.adicionarConta(&contaC);
  // Associamos a contaB com o clienteB
  contaB.setTitular(&clienteB);
  clienteB.adicionarConta(&contaB);
  // Adicionamos a contaC para o clienteB
  clienteB.adicionarConta(&contaC);
  // Depositamos nas contas por meio dos clientes
  clienteA.aplicarRecursos(100.f);
  clienteB.aplicarRecursos(100.f);
  // Geramos os relatorios dos clientes
  cout << clienteA.gerarRelatorio() << endl;
  cout << clienteB.gerarRelatorio() << endl;
  return 0;
}