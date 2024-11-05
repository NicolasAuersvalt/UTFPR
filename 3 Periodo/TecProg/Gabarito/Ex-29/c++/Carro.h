#ifndef C_CARRO
#define C_CARRO

class Carro
{
protected: // Necessário para que a classe CarroEsporte derive de Carro
  double consumo, capacidade, combustivel;

public:
  Carro(const double &consumo, const double &capacidade);
  ~Carro();
  double abastecer(const double &quantidade);
  virtual double andar(const double &distancia);
  const double &getCombustivel() const;
};
#endif