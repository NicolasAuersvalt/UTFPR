#include"assunto.h"
#include <iostream>
using namespace std;

Assunto::Assunto(): texto(""){	
}

Assunto::~Assunto(){
	texto.erase();
}

void Assunto::setTexto(const string& texto){	
	cout << "Setando texto" << endl;
	this->texto = texto;
	cout << "Setado" << endl;
}

string Assunto::getTexto(){
	return texto;
}
