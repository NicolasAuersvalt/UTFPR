#ifndef POLIGONO_H
#define POLIGONO_H


class Poligono{

	private:
		int nLados;
		int tamLados;

	public:
		Poligono();
		~Poligono();
		int calculaPerimetro();
		int calculaAnguloInterno();
		double calculaArea();
};

#endif
