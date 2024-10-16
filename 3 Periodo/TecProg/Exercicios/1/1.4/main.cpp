#include<iostream>
#include "horario.h"
using namespace std;


int main(){
	
	Horario Hoje;

	int h, m;
	cout << "Digite a Hora e o Minuto: " << endl;
	cin >> h >> m;

	Hoje.setHora(h);
	Hoje.setMin(m);


	return 0;
}
