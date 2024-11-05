#ifndef C_CARRO
#define C_CARRO

class Carro
{
private:
  double consumo, capacidade, combustivel;

public:
  Carro(const double &consumo, const double &capacidade);
  ~Carro();
  double abastecer(const double &quantidade);
  double andar(const double &distancia);
  const double &getCombustivel() const;
};
#endif