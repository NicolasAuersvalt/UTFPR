#ifndef _UNIVERSIDADE_H
#include _UNIVERSIDADE_H
#include<iostream>

class Universidade
{
	private:
		char nome[30];


	public:
		// Construtor
		Universidade();
		~Universidade();
		void setNome(char* n);
		char* getNome();

};

#endif
