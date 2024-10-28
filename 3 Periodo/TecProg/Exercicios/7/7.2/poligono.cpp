#include"poligono.h"
#include<cmath>
#include<iostream>

using namespace std;
Poligono::Poligono(int qtd,int lado){
	nLados = qtd;
	tamLados = lado;
}

Poligono::~Poligono(){
}

int Poligono::calculaPerimetro(){

	if(nLados<1){
		cout << "Impossível" << endl;
		return 0;
	}

	return nLados * tamLados;
}

int Poligono::calculaAnguloInterno(){
	if(nLados<1){
		cout << "Impossível" << endl;
		return 0;
	}
	int angulo = ((nLados-2) * 180)/nLados;
	return angulo;
}

double Poligono::calculaArea(){
	if(nLados<1){
		cout << "Impossível" << endl;
		return 0;
	}
	double area = ((nLados * pow(tamLados, 2))) /(4 * tan(M_PI / nLados));
	return area;
}
