#ifndef NANOSEG_H
#define NANOSEG_H
#include "relogio.h"

class Nano : public Relogio{

	private:
		int nano;

	public:
		Nano();
		~Nano();
		void setNano(int nano);
};	


#endif
