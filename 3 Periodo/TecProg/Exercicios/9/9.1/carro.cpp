#include "carro.h"
#include<iostream>

using namespace std;

Carro::Carro(float cons, float cap, float qtd, consE){

	consumo = cons;
	capacidade = cap;
	qtdTanque = qtd;
	consumoE = consE;
}

Carro::~Carro(){

	
}


void Carro::andar(float dist, bool cidade){

	if(cidade){
		qtdTanque -= consumo*dist;
	}
	else{
		qtdTanque -= consumoE*dist;
	}

}

float Carro::getCombustivel(){
	return qtdTanque;
}

void Carro::abastecer(float qtd){
	if(qtdTanque+qtd>capacidade){
		qtdTanque = capacidade;
	}
	else{
		qtdTanque += qtd;
	}
}

void Carro::distancia(float km, float litro){

	cout << "Estrada: " << litro/consumoE << endl;
	cout << "Cidade: " << litro/consumo << endl;

}
