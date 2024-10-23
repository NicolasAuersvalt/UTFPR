#include<iostream>
#include<cstring>
#include"colaborador.h"

using namespace std;

Colaborador::Colaborador(const char *n, int tempo){

	strcpy(nome, this->n);
	tempoServico = tempo;

}


Colaborador::~Colaborador(){


}
