#include "PolReg.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  int l = 0;
  double tam = 0.f;

  cout << "Digite as dimensoes do polígono: <Nro. Lados> <Tam. Lados>" << endl;
  // Pergunta para o usuario as medidas da caixa
  cin >> l >> tam;

  PolReg poligono = PolReg(l, tam);

  cout << "Perímetro: " << poligono.getPerimetro() << endl;
  cout << "Ângulo interno: " << poligono.getAnguloInterno() << endl;
  cout << "Área: " << poligono.getArea() << endl;

  return 0;
}