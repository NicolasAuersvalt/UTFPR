#include<iostream>
#include "horario.h"
using namespace std;


int main(){
	
	Horario Hoje;
	Horario Depois;

	Depois.setHora(5);
	Depois.setMin(30);

	int h, m;
	cout << "Digite a Hora e o Minuto: " << endl;
	cin >> h >> m;

	Hoje.setHora(h);
	Hoje.setMin(m);
	
	cout << "Intervalo de " << Hoje.calcularIntervalo(&Depois) << endl;

	return 0;
}
