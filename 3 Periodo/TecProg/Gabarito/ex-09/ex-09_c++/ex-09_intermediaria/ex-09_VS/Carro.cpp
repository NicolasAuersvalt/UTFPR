#include "Carro.hpp"

Carro::Carro(const double &consumo, const double &capacidade) : consumo(consumo),
                                                                capacidade(capacidade),
                                                                combustivel(0)
{
}

Carro::~Carro()
{
}

void Carro::abastecer(const double &quantidade)
{
  // Verifica que não sobrepase a capacidade de combustível do carro. - Monitores 2 Sem 2021
  if (this->combustivel + quantidade <= this->capacidade)
    this->combustivel += quantidade;
  else
    this->combustivel += this->capacidade - this->combustivel;
}

void Carro::andar(const double &distancia)
{
  // Resta o combustível consumido para andar a distância solicitada. - Monitores 2 Sem 2021
  this->combustivel -= distancia / this->consumo; // km / (km/litro) = litros consumidos - Monitores 2 Sem 2021
}

const double &Carro::getCombustivel() const
{
  return this->combustivel;
}