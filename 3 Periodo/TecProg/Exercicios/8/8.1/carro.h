#ifndef CARRO_H
#define CARRO_H

class Carro{

	private:
		float consumo;
		float capacidade;
		float qtdTanque;

	public:
		Carro(float cons = 0, float cap = 0, float qtd = 0);
		~Carro();
		void andar(float dis);
		float getCombustivel();
		void abastecer(float qtd);
};


#endif
