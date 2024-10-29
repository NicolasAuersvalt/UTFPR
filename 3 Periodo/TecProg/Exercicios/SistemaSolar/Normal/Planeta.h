#ifndef PLANETA_H
#define PLANETA_H

#include "Estrela.h"

class Planeta: public Astro{

	private:
		int tempo_orbita;
		Estrela* pSol;

	public:

		Planeta();
		~Planeta();

		float calcQuantOrbita();
		void setTempoOrbita(int to) {tempo_orbita = to;}
		void setSol (Estrela* pS) {pSol = pS;}

};


#endif
