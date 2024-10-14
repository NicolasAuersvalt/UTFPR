#include"Pessoa.h"
#include<string.h>
using namespace std;

Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, char* nome)
{
	// Método Construtor
	diaP = diaNa;
	mesP = mesNa;
	anoP = anoNa;
	strcpy(nomeP, nome);
	idadeP = 0;

}
Pessoa::Pessoa(){
	Inicializa(0,0,0);
}

void Pessoa::Calc_Idade(int diaAT, int mesAT, int anoAT)
{
	idadeP = anoAT - anoP;
	if(mesP < mesAT)
	{
		idadeP = idadeP - 1;	
	}
	else
	{
		if(mesP == mesAT)
		{
			if(diaP<diaAT)
			{
				idadeP = idadeP-1;		
			}		
		}
	}
}

void Pessoa::ExibeNome()
{
	cout << "A idade da Pessoa " << nomeP << " seria " << idadeP << endl;

}

int Pessoa::informaldade()
{
	return idadeP;
}

void Pessoa::setUni(Universidade *p){
	Uni = p;
}

void Pessoa::getUni(){
	cout << nome << " estuda em " << Uni->getNome() << endl;

}
