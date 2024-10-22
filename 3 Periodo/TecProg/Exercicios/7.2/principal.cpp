#include "principal.h"
#include<iostream>
using namespace std;

Principal::Principal():
	Nicolas(),
	Quadrado(4,2),
	Pentagono(5,2)
{
	cout <<	Nicolas.calculaPerimetro() << endl;
	cout <<	Nicolas.calculaAnguloInterno() << endl;
	cout <<	Nicolas.calculaArea() << endl;

	cout <<	Quadrado.calculaPerimetro()  << "m" << endl;
	cout <<	Quadrado.calculaAnguloInterno() << "graus" <<endl;
	cout <<	Quadrado.calculaArea() << "m2"<<endl;
	
	cout <<	Pentagono.calculaPerimetro() << "m" << endl;
	cout << Pentagono.calculaAnguloInterno() << "graus" << endl;
	cout <<	Pentagono.calculaArea() << "m2" <<endl;

}

Principal::~Principal(){}
