#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>
using namespace std;

class Colaborador{

	protected:
		string nome;
		int tempoServico; // Em anos	

	public:

		Colaborador(string& n, int tempo);
		~Colaborador();

};



#endif
