#include"stdafx.h"

#include "Sistema.h"

SistemaSolar::SistemaSolar(): sol() {

	cout << "oi" << endl;
	jupiter.setTempoOrbita(30);
	sol.setTempoExistencia(300000);
	jupiter.setSol(&sol);
	executar();
}

SistemaSolar::~SistemaSolar(){

	cout << "tchau" << endl;

}

void SistemaSolar::executar(){

	float q_jupiter = 0.0;
	q_jupiter = jupiter.calcQuantOrbita();
	cout << "A quantidade de orbitas de Jupiter é" << q_jupiter << endl;
	cout << "Numero astronomico de Sol: "<< sol.getNA();
}