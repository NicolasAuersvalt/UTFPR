#include <iostream>
#include "Quadrado.h"
#include "TrianguloEq.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
     // Declarada uma referência p para PolReg
     PolReg *pPolReg;

     // Perguntado ao usuário que tipo de objeto ele quer criar
     cout << "Digite qual tipo de objeto você quer criar:" << endl
          << "[P] Polígono Regular Genérico\t [T] Triângulo\t [Q] Quadrado"
          << endl;
     char opcao;
     cin >> opcao;

     // Perguntado tamanho dos lados
     double tamanho;
     cout << "Digite o tamanho de cada lado: ";
     cin >> tamanho;

     if (opcao == 'Q' || opcao == 'q')
          // Instanciado o objeto alocado como quadrado
          pPolReg = new Quadrado(tamanho);
     
     else if (opcao == 'T' || opcao == 't')
          // Instanciado o objeto alocado como triângulo
          pPolReg = new TrianguloEq(tamanho);
     
     else {
          int lados;
          // Perguntado número de lados (se for polígono regular)
          cout << "Digite quantos lados: ";
          cin >> lados;

          // Instanciado o objeto alocado como polígono genérico
          pPolReg = new PolReg(lados, tamanho);
     }

     // Cria variável area que chama polimorficamente o polígono de acordo com sua classe
     double area = pPolReg->calculaArea();
     // Caso a área não for nula, utiliza o operador ternário para imprimir seu valor
     cout << (area ? "Area, " : "") << "Perimetro e Angulo interno do poligono respectivamente: ";
     area ? (cout << area << ", ") : (cout << "");
     // Imprime os outros métodos exercitados na questão 30
     cout << pPolReg->calculaPerimetro() << ", "
          << pPolReg->calculaAnguloInterno() << endl;


     return 0;
}