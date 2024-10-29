#ifndef SISTEMA_H
#define SISTEMA_H

#include "Estrela.h"
#include "Planeta.h"

class SistemaSolar{

	private:
		Estrela sol;
		Planeta jupiter;

	public:
		SistemaSolar();
		~SistemaSolar();

		void executar();


};


#endif
