#ifndef ESTRELA_H
#define ESTRELA_H
#include "Astro.h"

class Planeta;

class Estrela: public Astro{

	private:
		int tempo_existencia;
		Planeta* pPlaneta;

	public:

		Estrela();
		~Estrela();

		void setTempoExistencia(int te){tempo_existencia = te;}
		int getTempoExistencia(){return tempo_existencia;}
		
};


#endif
