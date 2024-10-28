#ifndef EMPREGADO_H
#define EMPREGADO_H

#include "colaborador.h"

class Empregado : public Colaborador{

	private:
		float valHora;
		int horaTrabalha;

	public:
		Empregado();
		~Empregado();


};




#endif
