#include "C4.hpp"

namespace p2
{

  // Constructor
  C4::C4() : a4(0)
  {
  }

  // Destructors
  C4::~C4()
  {
  }

  // Getters & Setters
  void C4::setA4(const int &a4) { this->a4 = a4; }
  const int &C4::getA4() const { return this->a4; }
}