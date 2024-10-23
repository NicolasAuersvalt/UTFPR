#include"colaborador.h"

#include <iostream>

#include<string>

using namespace std;

Colaborador::Colaborador(char n, int tempo){

	strcpy(n, nome);
	tempoServico = tempo;


}


Colaborador::~Colaborador(){


}
