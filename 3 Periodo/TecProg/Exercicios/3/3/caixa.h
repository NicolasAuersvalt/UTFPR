#pragma once
#include "caixa.cpp"
#include "testador.h"

class Caixa{

	private:
		int largura, altura, profundidade;


	public:
		// Construtor por parmetros
		Caixa(int largura=0, int altura=0, int profundidade=0);
		
		// Destrutor
		~Caixa();
		
		// Métodos
		setLargura();
		setAltura();
		setProfundidade();
		calcularAreaExt();
		calcularVolume();

};
