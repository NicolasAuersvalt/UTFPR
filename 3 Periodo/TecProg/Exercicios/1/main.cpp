#include<iostream>
#include "hora.h"

using namespace std;

int main(){

	Horario hr1, hr2;
	int hr, min;	
	
	cout << "Digite o primeiro horario(hora minuto): " << endl;
	cin >> hr >> min;
	hr1(hr,min);

	cout << "Digite o primeiro horario(hora minuto): " << endl;
	cin >> hr >> min;
	hr2(hr,min);
	
	// Calcula o intervalo entre eles
	cout << "O intervalo entre eles é: " << endl;
	int intervalo = calcularIntervalo(hr1, hr2);
	cout << intervalo << endl;
	
	if(intervalo < 3){
		cout << "4,50" << endl;
	}
	else if(intervalo > 12){
		cout << "0.75" << endl;
	}
	else{
		cout << ""33.00" << endl;
	}

	return 0;
}
