#ifndef COLABORADOR_H
#define COLABORADOR_H

class Colaborador{

	protected:
		char nome[100];
		int tempoServico; // Em anos	

	public:

		Colaborador(const char *n, int tempo);
		~Colaborador();

};



#endif
