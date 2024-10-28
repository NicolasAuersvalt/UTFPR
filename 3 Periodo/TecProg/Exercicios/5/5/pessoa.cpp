#include "pessoa.h"
#include<cstring>

Pessoa::Pessoa(){

}
Pessoa::~Pessoa(){

}

void Pessoa::CalculaIdade(int d, int m, int a){
	int ida=-1;
	if(a>ano){
		ida = a - idade;
		if(m>mes)
			if(d>=dia)
				ida++;
	}
	idade = ida;
}

int Pessoa::getIdade(){
	return idade;
}

char* Pessoa::getNome(){
	return nome;
}

void Pessoa::setNome(const char* nome){
	strcpy(this->nome, nome);
}

void Pessoa::setDataDeNascimento(int d, int m, int a){
	dia = d;
	mes = m;
	ano = a;
}


