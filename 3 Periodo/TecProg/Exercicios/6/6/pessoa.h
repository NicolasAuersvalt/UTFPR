#ifndef PESSOA_H
#define PESSOA_H


class Pessoa{
	private:
		int idade;
		int dia;
		int mes;
		int ano;
		char nome[50];

	public:
		// -1 Porque não faz sentido valores de -1
		Pessoa(const char* nome="", int d=-1, int m=-1, int a=-1);
		~Pessoa();
		void CalculaIdade(int d, int m, int a);
		int getIdade();
		char* getNome();
		void setNome(const char *vet);
		void setDataDeNascimento(int d, int m, int a);

};

#endif
