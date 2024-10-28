#ifndef EMPRESARIO_H
#define EMPRESARIO_H

#include "colaborador.h"

class Empresario : public Colaborador{

	private:
		float valHora;
		int horaTrabalha;

	public:
		Empresario();
		~Empresario();
};


#endif
