#ifndef POLIGONO_H
#define POLIGONO_H


class Poligono{

	private:
		int nLados;
		int tamLados;

	public:
		Poligono(int qtd = -1, int lado = -1);
		~Poligono();
		int calculaPerimetro();
		int calculaAnguloInterno();
		double calculaArea();
};

#endif
