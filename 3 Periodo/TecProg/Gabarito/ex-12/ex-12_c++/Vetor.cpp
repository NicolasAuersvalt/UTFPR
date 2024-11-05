#include "Vetor.hpp"

// Construtora & Destrutora
Vetor::Vetor(const double &dx, const double &dy) : dx(dx), dy(dy)
{
}

Vetor::~Vetor()
{
}
// Getters & Setters
const double &Vetor::getX() const
{
  return this->dx;
}
const double &Vetor::getY() const
{
  return this->dy;
}
void Vetor::setX(const double &dx)
{
  this->dx = dx;
}
void Vetor::setY(const double &dy)
{
  this->dy = dy;
}

// Operadores
Vetor Vetor::operator+(const Vetor &v)
{
  // Calcula valores do novo vetor
  double dx = this->getX() + v.getX();
  double dy = this->getY() + v.getY();
  // Cria vetor com os valores calculados e retorna
  return Vetor(dx, dy);
}

Vetor Vetor::operator*(const Vetor &v)
{
  // Calcula valores do novo vetor
  double dx = this->getX() * v.getX();
  double dy = this->getY() * v.getY();
  // Cria vetor com os valores calculados e retorna
  return Vetor(dx, dy);
}