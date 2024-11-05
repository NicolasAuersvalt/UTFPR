#include "C2.hpp"

namespace p1
{

  // Constructor
  C2::C2() : a2(0)
  {
  }

  // Destructors
  C2::~C2()
  {
  }

  const void C2::accesar()
  {
    C1 c1;
    c1.setA1(this->a2);
    c1.getA1();
  }

  // Getters & Setters
  void C2::setA2(const int &a2) { this->a2 = a2; }
  const int &C2::getA2() const { return this->a2; }
}