#include "stdinc.hpp"

#include "CalcControle.hpp"
#include "CalcDados.hpp"
#include "CalcInterface.hpp"

int main()
{
  // Instanciamos a interface e memoria da calculadora
  CalcInterface interface = CalcInterface();
  CalcDados dados = CalcDados();
  // Criamos o controle da calculadora utilizando a interface e memoria
  CalcControle controle(interface, dados);
  // Executamos
  controle.executar();
  return 0;
}