#include <iostream>
#include "relogio.h"

using namespace std;


Relogio::Relogio(){
	
}

Relogio::Relogio(int ano, int mes, int dia, int hora, int min, int seg) : ano(ano), mes(mes), dia(dia), hora(hora), min(min), seg(seg){
	
}

Relogio::~Relogio(){


}

void Relogio::setHora(int ano, int mes, int dia, int hora, int min, int seg){
	ano = this->ano;
	mes = this->mes;
	dia = this->dia;
	hora = this->hora;
	min = this->min;
	seg = this->seg;

}
