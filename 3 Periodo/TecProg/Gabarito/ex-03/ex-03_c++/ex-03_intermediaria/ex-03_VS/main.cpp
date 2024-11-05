#include "Caixa.hpp"

#include <assert.h>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// A solução abaixo, feita por monitor, não atende perfeitamente o enunciado... 
// Primeiramente, no contéudo da disciplina ainda não se viu alocação de memória dinâmica, 
// ainda que não haja obste relativo a aprender de antemão, isto. 
// Ademais, o exercício pede uma classe ExTestadorDeCaixa, classe esta que não existe na solução abaixo dada. 
// Prof. Simão 

/**
 * Essa função pergunta ao usuario as dimensoes da 
 * caixa, e aloca memoria para um novo objeto caixa 
 * com as dimensões é retorna este ponteiro.
 * **/

Caixa *getNovaCaixa()
{
  double l = 0, a = 0, p = 0;
  cout << "Digite as dimensoes da caixa: L A P" << endl;
  // Pergunta para o usuario as medidas da caixa
  cin >> l >> a >> p;

  // OPÇÃO-1: Utilizando os getters e setters
  // Cria um novo objeto caixa
  /*
  Caixa *caixaAux = new Caixa();
  // Atualiza suas dimensões
  caixaAux->setLargura(l);
  caixaAux->setAltura(a);
  caixaAux->setProfundidade(p);
  // Retorna ponteiro
  return caixaAux;
  */

  // OPÇÃO-2: Utilizando a construtora (mais compacta)
  // Aloca e rotorna nova caixa com as medidas e retorna
  return new Caixa(l, a, p);
}

int main(int argc, char **argv)
{
  Caixa *c1 = NULL, *c2 = NULL;
  // Pergunta dimensoes das caixas
  c1 = getNovaCaixa();
  c2 = getNovaCaixa();

  // Imprime Area e Volume das caixas
  cout << "CAIXA 01 -> "
       << "Area:" << c1->calcularAreaExt() << " Volume:" << c1->calcularVolume() << endl;
  cout << "CAIXA 02 -> "
       << "Area:" << c2->calcularAreaExt() << " Volume:" << c2->calcularVolume() << endl;

  // Desaloca memoria
  delete c1;
  delete c2;
  return 0;
}  