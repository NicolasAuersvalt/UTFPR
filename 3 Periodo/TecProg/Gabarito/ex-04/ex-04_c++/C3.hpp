#ifndef C_C3
#define C_C3
#include "C1.hpp"
#include "C2.hpp"
#include "C4.hpp"

namespace p2
{
  class C3
  {
  private:
    int a3;

  public:
    C3();
    ~C3();
    void setA3(const int &a3);
    const int &getA3() const;
    void executar();
  };
}
#endif