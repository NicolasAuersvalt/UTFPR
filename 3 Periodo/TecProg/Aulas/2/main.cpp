#include<stdio.h>
#include "Pessoa.h"

int main(){

	Pessoa Nicolas(23, 11, 2003, "Nicolas Auersvalt");
	Pessoa Newton(4, 1, 1643, "Isaac Newton");
	Pessoa Einstein(14, 3, 1879, "Albert Einstein");

	Nicolas.Calc_Idade(25,02,2007);
	Newton.Calc_Idade(25,02,2007);
	Einstein.Calc_Idade(25,02,2007);
	Nicolas.ExibeNome();
	Newton.ExibeNome();
	Einstein.ExibeNome();

	getchar();
	return 0;

}