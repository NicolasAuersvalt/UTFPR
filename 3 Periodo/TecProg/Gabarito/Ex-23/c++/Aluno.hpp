#ifndef C_ALUNO
#define C_ALUNO

#include "stdinc.hpp"

class Aluno
{
private:
  string nome;
  int nota1, nota2;

public:
  Aluno(const string &nome, const int &nota1, const int &nota2);
  ~Aluno();
  void setNome(const string &nome);
  const string &getNome() const;
  void setNota1(const int &nota1);
  const int &getNota1() const;
  void setNota2(const int &nota2);
  const int &getNota2() const;
  double getMedia() const;
  // Sobrecarregamos o operador == para facilitar a comparação entre alunos
  bool operator==(const Aluno &aluno) const;
};
#endif