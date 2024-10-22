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
		Pessoa();
		~Pessoa();
		void CalculaIdade(int d, int m, int a);
		int getIdade();
		char* getNome();
		void setNome(const char *vet);
		void setDataDeNascimento(int d, int m, int a);

};

#endif
