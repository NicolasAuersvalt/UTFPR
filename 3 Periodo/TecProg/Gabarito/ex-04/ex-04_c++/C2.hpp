#ifndef C_C2
#define C_C2
#include "C1.hpp"

namespace p1
{
  class C2
  {
  private:
    int a2;

  public:
    C2();
    ~C2();
    void setA2(const int &a2);
    const int &getA2() const;
    const void accesar();
  };
}
#endif