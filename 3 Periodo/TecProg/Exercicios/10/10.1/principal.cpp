#include "principal.h"
#include<iostream>

using namespace std;

Principal::Principal(){
	Socio Nicolas;
	Nicolas.setNome("Nicolas");
	cout << Nicolas.getNome() << endl;
	Nicolas.setValores(30, 5);
	Nicolas.setHorasTrabalhadas(30);
        cout << Nicolas.getHorasTrabalhadas() << endl;
	cout << Nicolas.calculaPagamento() << endl;
}

Principal::~Principal(){


}

