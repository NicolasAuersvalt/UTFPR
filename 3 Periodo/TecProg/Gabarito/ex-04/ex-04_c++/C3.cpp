#include "C3.hpp"

namespace p2
{

  // Constructor
  C3::C3() : a3(0)
  {
  }

  // Destructors
  C3::~C3()
  {
  }

  void C3::executar()
  {
    p1::C1 c1;
    p1::C2 c2;
    C4 c4;

    c1.setA1(1);
    c2.setA2(1);
    c4.setA4(1);

    c1.getA1();
    c2.getA2();
    c4.getA4();
  }

  // Getters & Setters
  void C3::setA3(const int &a3) { this->a3 = a3; }
  const int &C3::getA3() const { return this->a3; }
}