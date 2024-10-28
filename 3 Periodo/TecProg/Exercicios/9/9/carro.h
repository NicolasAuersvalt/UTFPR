#ifndef CARRO_H
#define CARRO_H

class Carro{

	private:
		float consumo;
		float capacidade;
		float qtdTanque;
		float consumoEst;

	public:
		Carro(float cons = 0, float cap = 0, float qtd = 0, float consE);
		~Carro();
		void andar(float dis, bool cidade);
		float getCombustivel();
		void abastecer(float qtd);
		void distancia(float km, float litro);
};


#endif
