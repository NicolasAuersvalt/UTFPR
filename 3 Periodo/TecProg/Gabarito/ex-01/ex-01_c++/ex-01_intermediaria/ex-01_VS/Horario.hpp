
// Código com comentário e ajustes. Prof. Simão. 
// Arquivo de cabeçalho em C++ podem ser .h ou .hpp - Prof. Simão

#ifndef C_HORARIO
#define C_HORARIO

#include <cmath>
#include <cstdint>

class Horario
{
private:
  // Foi utilizado uint8_t porque são mais adequados para este caso (o seu valor máximo é 255) - monitor
  uint8_t hora, min;
  
  // Acima, nota do autor/monitor, que ok procede em dados contextos, como o de economia efetiva de memória. 
  // Entretanto, também poderia ser short int ou int caso não se este com apego a economia efetiva de memória. Prof. Simão
  // https://en.cppreference.com/w/cpp/types/integer  

public:
  Horario(); // Construtora.
  ~Horario(); // Destrutora. 

  const uint8_t &getHora() const; // Aqui o retorno poderia ser só o valor mesmo, sem referência (&). Mas tudo bem enfim. 
  const uint8_t &getMin() const;  // Idem. 
  
  void setHora(const uint8_t &_hora); // Aqui o parâmetro poderia ser só o valor mesmo, sem referência (&). Mas tudo bem enfim. 
  void setMin(const uint8_t &_min); // Idem.
  
  int calcularIntervalo(const Horario &horario) const;
};

#endif