#include <iostream>
#include "Quadrado.h"
#include "TrianguloEq.h"

using std::cout;
using std::endl;

int main()
{
  // Cria polígonos regulares de 7 e 8 lados com 5 e 10 de tamanhos respectivos 
  PolReg poligono_1(7, 5),
         poligono_2(8, 10);
  
  // Cria quadrados de tamanhos de lados 2 e 4 de 
  Quadrado quadrado_1(2),
           quadrado_2(4);

  // Cria triângulos equiláteros de tamanhos de lados 3 e 6
  TrianguloEq triangulo_1(3),
              triangulo_2(6);

  // Informa dados do polígono de lado 7
  cout << "Poligono de lado = " << poligono_1.getNumLados()
       << ", tamanho de cada lado = " << poligono_1.getTamLados()
       << ": Perimetro = " << poligono_1.calculaPerimetro()
       << ", Angulo Interno = " << poligono_1.calculaAnguloInterno()
       << endl << endl;

  // Informa dados do polígono de lado 8
  cout << "Poligono de lado = " << poligono_2.getNumLados()
       << ", tamanho de cada lado = " << poligono_2.getTamLados()
       << ": Perimetro = " << poligono_2.calculaPerimetro()
       << ", Angulo Interno = " << poligono_2.calculaAnguloInterno()
       << endl << endl;

  // Informa dados do quadrado de tamanho de lado 2
  cout << "Poligono de lado = " << quadrado_1.getNumLados()
       << ", tamanho de cada lado = " << quadrado_1.getTamLados()
       << ": Perimetro = " << quadrado_1.calculaPerimetro()
       << ", Angulo Interno = " << quadrado_1.calculaAnguloInterno()
       << ", Area = " << quadrado_1.calculaArea()
       << endl << endl;
  
  // Informa dados do quadrado de tamanho de lado 4
  cout << "Poligono de lado = " << quadrado_2.getNumLados()
       << ", tamanho de cada lado = " << quadrado_2.getTamLados()
       << ": Perimetro = " << quadrado_2.calculaPerimetro()
       << ", Angulo Interno = " << quadrado_2.calculaAnguloInterno()
       << ", Area = " << quadrado_2.calculaArea()
       << endl << endl;

  // Informa dados do triângulo de tamanho de lado 3
  cout << "Poligono de lado = " << triangulo_1.getNumLados()
       << ", tamanho de cada lado = " << triangulo_1.getTamLados()
       << ": Perimetro = " << triangulo_1.calculaPerimetro()
       << ", Angulo Interno = " << triangulo_1.calculaAnguloInterno()
       << ", Area = " << triangulo_1.calculaArea()
       << endl << endl;

  // Informa dados do triângulo de tamanho de lado 6
  cout << "Poligono de lado = " << triangulo_2.getNumLados()
       << ", tamanho de cada lado = " << triangulo_2.getTamLados()
       << ": Perimetro = " << triangulo_2.calculaPerimetro()
       << ", Angulo Interno = " << triangulo_2.calculaAnguloInterno()
       << ", Area = " << triangulo_2.calculaArea()
       << endl;

  return 0;
}