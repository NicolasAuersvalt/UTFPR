#include "pessoa.h"
#include<cstring>
#include <iostream>

using namespace std;

Pessoa::Pessoa(const char* nome, int d, int m, int a){
	strcpy(this->nome, nome);
	dia = d;
	mes = m;
	ano = a;
	idade = -1;
}
Pessoa::~Pessoa(){

}

void Pessoa::CalculaIdade(int d, int m, int a){
	int ida=-1;
	if(a>ano){
		ida = a - ano-1;
		if(m>=mes)
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
	CalculaIdade(22,10,2024);
}


