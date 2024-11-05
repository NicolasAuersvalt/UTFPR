#include "C1.hpp"

namespace p1
{

  // Constructor
  C1::C1() : a1(0)
  {
  }

  // Destructors
  C1::~C1()
  {
  }

  // Getters & Setters
  void C1::setA1(const int &a1) { this->a1 = a1; }
  const int &C1::getA1() const { return this->a1; }
}