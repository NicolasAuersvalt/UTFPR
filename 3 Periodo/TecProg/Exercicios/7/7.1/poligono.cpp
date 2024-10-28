#include"poligono.h"
#include<cmath>

Poligono::Poligono(int qtd,int lado){
	nLados = qtd;
	tamLados = lado;
}

Poligono::~Poligono(){
}

int Poligono::calculaPerimetro(){

	return nLados * tamLados;
}

int Poligono::calculaAnguloInterno(){
	int angulo = ((nLados-2) * 180)/nLados;

	return angulo;
}

double Poligono::calculaArea(){
	double area = ((nLados * pow(tamLados, 2))) /(4 * tan(M_PI / nLados));
	return area;
}
