#include<iostream>
#include "Universidade.h"

class Pessoa
{

	private:

		// Definimos os atributos
		int diaP;
		int mesP;
		int anoP;
		int idadeP;
		char nomeP[30];
	public:

		// Definimos os métodos a terem acesso a private
		Pessoa(int diaNa, int mesNa, int anoNa, char* nome);
		~Pessoa();
		void Calc_Idade(int diaAT, int mesAT, int anoAT);
		int informaldade();
		void ExibeNome();
};
