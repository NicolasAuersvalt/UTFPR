#ifndef RELOGIO_H
#define RELOGIO_H

class Relogio{

	protected:
		int ano;
		int mes;
		int dia;
		int hora;
		int min;
		int seg;

	public:
		Relogio();
		Relogio(int ano, int mes, int dia, int hora, int min, int seg);
		~Relogio();
		void setHora(int ano, int mes, int dia, int hora, int min, int seg);
};


#endif
