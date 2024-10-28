#ifndef NANOSEG_H
#define NANOSEG_H
#include "relogio.h"

class Nano : protected Relogio{

	private:
		int nano;

	public:
		Nano(int ano, int mes, int dia, int hora, int min, int seg);
		~Nano();
		void setNano(int nano);
		void getHora();
};	


#endif
