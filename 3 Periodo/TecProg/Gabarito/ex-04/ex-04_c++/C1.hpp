#ifndef C_C1
#define C_C1

namespace p1
{
  class C1
  {
  private:
    int a1;

  public:
    C1();
    ~C1();
    void setA1(const int &a1);
    const int &getA1() const;
  };
}
#endif