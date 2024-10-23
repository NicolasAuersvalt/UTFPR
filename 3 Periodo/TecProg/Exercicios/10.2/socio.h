#ifndef SOCIO_H
#define SOCIO_H

#include "colaborador.h"

// Classe Socio herda Colaborador
class Socio : public Colaborador{

	private:
		float valHora;
		int horasTrabalha;
		

	public:
		Socio(const string& n, int tempo, float valorHora, int horas);
		~Socio();

};


#endif
