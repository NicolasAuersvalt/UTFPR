#pragma once

#include "Pessoa.h"
#include "Universidade.h"

class Principal{

	private:
		Pessoa Nicolas;
		Pessoa Albert;
		Pessoa Newton;

		int diaAtual;
		int mesAtual;
		int anoAtual;

		// Agregando Universidade a todos os objetos dessa classe
		Universidade Uni;


	public:

		Principal();
		~Principal();
		void Executar();


};



