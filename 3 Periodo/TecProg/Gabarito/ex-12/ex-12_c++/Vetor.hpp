#ifndef C_VETOR
#define C_VETOR

class Vetor
{
private:
  double dx, dy;

public:
  // Construtora & Destrutora
  Vetor(const double &dx, const double &dy);
  ~Vetor();
  // Getters & Setters
  const double &getX() const;
  const double &getY() const;
  void setX(const double &dx);
  void setY(const double &dy);
  // Operadores
  Vetor operator+(const Vetor &vetorB);
  Vetor operator*(const Vetor &vetor);
};

#endif