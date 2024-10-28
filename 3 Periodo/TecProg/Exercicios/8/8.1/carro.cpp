#include "carro.h"
#include<iostream>

using namespace std;

Carro::Carro(float cons, float cap, float qtd){

	consumo = cons;
	capacidade = cap;
	qtdTanque = qtd;
}

Carro::~Carro(){

	
}


void Carro::andar(float dist){
	qtdTanque -= consumo*dist;

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
