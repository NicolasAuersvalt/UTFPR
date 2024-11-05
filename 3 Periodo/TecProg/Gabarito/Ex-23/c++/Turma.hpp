#ifndef C_TURMA
#define C_TURMA

#include "stdinc.hpp"
#include "Aluno.hpp"

class Turma
{
private:
  static const int NOTA_MIN_APROVADO = 60;
  static const int NOTA_MIN_RECUPARACAO = 20;

  string nomeTurma;
  string codTurma;
  int nVagas, nVagasOcupadas;
  list<Aluno> alunos;

public:
  Turma();
  Turma(const string &nomeTurma, const string &codTurma, const int &nVagas);
  ~Turma();
  void matricularAluno(const Aluno &aluno);
  void cancelarAluno(const Aluno &aluno);
  string gerarRelatorio() const;
  double getMediaTurma() const;
  int getNroAlunosAprovados() const;
  int getNroAlunosParaFinal() const;
  int getNroAlunosReprovados() const;
  string getNomeAlunosAbaixoMedia() const;
};
#endif