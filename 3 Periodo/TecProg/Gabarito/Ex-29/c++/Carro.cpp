#include "Carro.h"

Carro::Carro(const double &consumo, const double &capacidade) : consumo(consumo),
                                                                capacidade(capacidade),
                                                                combustivel(0)
{
}

Carro::~Carro()
{
}

double Carro::abastecer(const double &quantidade)
{
  // Verifica que não sobrepase a capacidade de combustível do carro.
  if (this->combustivel + quantidade <= this->capacidade)
  {
    // Caso não ultrapasse a capacidade do carro.
    this->combustivel += quantidade;
    return quantidade;
  }
  else
  {
    // Caso ultrapasse a capacidade do carro. Calculamos a quantidade para encher o tanque.
    double quantidadeAbastecida = this->capacidade - this->combustivel;
    this->combustivel += this->capacidade;
    return quantidadeAbastecida;
  }
}

double Carro::andar(const double &distancia)
{
  // Resta o combustível consumido para andar a distância solicitada.
  double consumo = distancia / this->consumo; // km / (km/litro) = litros consumidos
  if (consumo <= this->combustivel)
  {
    // Caso tenha suficiente combustível.
    this->combustivel -= consumo;
    return distancia;
  }
  else
  {
    // Caso NÃO tenha suficiente combustível calcula quantos km conseguiu andar.
    double distanciaPercorrida = this->combustivel * this->consumo; // litros * (km/litros) = km percorridos
    this->combustivel = 0;                                          // Deixa o tanque de combustível vazio.
    return distanciaPercorrida;
  }
}

const double &Carro::getCombustivel() const
{
  return this->combustivel;
}