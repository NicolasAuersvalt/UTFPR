#ifndef SOCIO_H
#define SOCIO_H

#include "colaborador.h"

// Classe Socio herda Colaborador
class Socio : public Colaborador{

	private:
		float valHora;
		int horasTrabalha;
		

	public:
		Socio();
		~Socio();

};


#endif
