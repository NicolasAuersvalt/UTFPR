#ifndef RELOGIO_H
#define RELOGIO_H

class Relogio{

	private:
		int ano;
		int mes;
		int dia;
		int hora;
		int min;
		int seg;

	public:
		Relogio();
		Relogio(int ano = -1, int mes = -1, int dia = -1, int hora = -1, int min = -1, int seg = -1);
		~Relogio();
};


#endif
