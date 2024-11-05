#ifndef C_CONTROLE
#define C_CONTROLE

#include "stdinc.hpp"
#include "Turma.hpp"

class Controle
{
private:
  Turma turma;
  int op;

public:
  Controle();
  ~Controle();
  void run();
  void iniciarTurma();
  void matricularAluno();
  void cancelarAluno();
  void imprimirRelatorio();
  void imprimirMenu() const;
};
#endif