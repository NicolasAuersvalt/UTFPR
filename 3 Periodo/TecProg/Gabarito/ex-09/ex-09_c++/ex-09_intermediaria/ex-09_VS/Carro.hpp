#ifndef C_CARRO
#define C_CARRO

class Carro
{
private:
  double consumo, capacidade, combustivel;

public:
  Carro(const double &consumo, const double &capacidade);
  ~Carro();
  void abastecer(const double &quantidade);
  void andar(const double &distancia);
  const double &getCombustivel() const;
};
#endif