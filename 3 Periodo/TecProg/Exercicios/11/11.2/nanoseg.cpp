#include <iostream>
#include "nanoseg.h"

using namespace std;


Nano::Nano(int ano, int mes, int dia, int hora, int min, int seg){
	this->ano = ano;
	this->mes = mes;
	this->dia = dia;
	this->hora = hora;
	this->min = min;
	this->seg = seg;
	this->nano = 0;
}

Nano::~Nano(){
}

void Nano::setNano(int nano){
	this->nano = nano;
}

void Nano::getHora(){

	cout << "Dia " << dia << " de " << mes << " de " << ano << endl;
	cout << "Hora: " << hora << " e " << min << " minutos e " << seg << " segundos e " << nano << " nanosegundos." << endl;
	
}
