#include<iostream>
#include"principal.h"
using namespace std;
Principal::Principal():
	Chevette(1, 50, 50)
{
	float distancia=0;

	cout << "Digite uma distância" << endl;
	cin >> distancia;

	cout << "Capacidade: " << Chevette.getCombustivel() << endl;
	
	Chevette.andar(distancia);

	cout << "Capacidade: " << Chevette.getCombustivel() << endl;
	float abs;
	cout << "Digite um valor para abastecer" << endl;
	cin >> abs;

	Chevette.abastecer(abs);	
	cout << "Capacidade: " << Chevette.getCombustivel() << endl;
}

Principal::~Principal(){


}
