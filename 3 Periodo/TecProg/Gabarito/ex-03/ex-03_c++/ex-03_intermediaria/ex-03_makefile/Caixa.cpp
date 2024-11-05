#include "Caixa.hpp"

// Construtora & Destrutora
Caixa::Caixa() : largura(0),
                 altura(0),
                 profundidade(0)
{
}

Caixa::Caixa(const double &largura,
             const double &altura,
             const double &profundidade) : largura(largura),
                                           altura(altura),
                                           profundidade(profundidade)
{
}

Caixa::~Caixa()
{
}

// Setters
void Caixa::setLargura(const double &largura)
{
  this->largura = largura;
}

void Caixa::setAltura(const double &altura)
{
  this->altura = altura;
}

void Caixa::setProfundidade(const double &profundidade)
{
  this->profundidade = profundidade;
}

// Getters
const double &Caixa::getLargura() const
{
  return this->largura;
}

const double &Caixa::getAltura() const
{
  return this->altura;
}

const double &Caixa::getProfundidade() const
{
  return this->profundidade;
}

// Funções
double Caixa::calcularAreaExt() const
{
  return 2 * (this->altura * this->largura +
              this->altura * this->profundidade +
              this->largura * this->profundidade);
}
double Caixa::calcularVolume() const
{
  return this->profundidade * this->largura * this->altura;
}