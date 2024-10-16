#include "horario.h"
#include <iostream>
using namespace std;

Horario::Horario(int hr, int mn){
	hora = hr;
	min = mn;

	// cout << hora << ":" << min << endl;

	//getHora();
	//getMin();
	//setHora(5);
	//setMin(5);
	//calcularIntervalo();
}

Horario::~Horario(){

}

int Horario::getHora(){

	cout << "getHora" << endl;

	return 1;
}

int Horario::getMin(){

	cout << "getMin" << endl;

	return 1;
}

void Horario::setHora(int hr){

	if (hr<0){
		cout << "Horário Incorreto." << endl;
	}
	else{
		cout << "setHora" << endl;
		hora = hr;
		cout << hora << endl;
	}
}

void Horario::setMin(int mn){

	if (mn<0){
		cout << "Horário Incorreto." << endl;
	}
	else{
		cout << "setMin" << endl;
		min = mn;
		cout << min << endl;
	}
}

int Horario::calcularIntervalo(Horario* h){

	cout << "Calcular Intevalo" << endl;
	
	int intervalo = 60* (h->hora - hora);
	intervalo = (intervalo < 0) ? -intervalo : intervalo;
	
	int intervalo2 = h->min - min;
	intervalo2 = (intervalo2 < 0) ? -intervalo2 : intervalo2;
	
	return intervalo + intervalo2;
}
