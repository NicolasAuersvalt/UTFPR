#include "Turma.hpp"

Turma::Turma() : nomeTurma(""), codTurma(""), nVagas(0), nVagasOcupadas(0), alunos()
{
}

Turma::Turma(const string &nomeTurma, const string &codTurma, const int &nVagas) : nomeTurma(nomeTurma), codTurma(codTurma), nVagas(nVagas), nVagasOcupadas(0), alunos()
{
}

Turma::~Turma()
{
}

void Turma::matricularAluno(const Aluno &aluno)
{
  if (this->nVagasOcupadas < this->nVagas)
  {
    this->alunos.emplace_back(aluno);
    this->nVagasOcupadas++;
  }
}

void Turma::cancelarAluno(const Aluno &aluno)
{ // Buscamos o aluno
  list<Aluno>::const_iterator it = this->alunos.begin();
  bool existe = false;
  while (!existe && it != this->alunos.end())
  {
    if ((*it) == aluno)
      existe = true;
    it++;
  }
  // Removemos o aluno caso ele exista
  if (existe)
  {
    this->alunos.remove(aluno);
    this->nVagasOcupadas--;
  }
}

double Turma::getMediaTurma() const
{
  list<Aluno>::const_iterator it = this->alunos.begin();
  // Somamos todas as medias e divimos pelo nro de alunos
  // para tirar a media das medias.
  double media = 0;
  while (it != this->alunos.end())
  {
    media += it->getMedia();
    it++;
  }

  return media / this->nVagasOcupadas;
}

int Turma::getNroAlunosAprovados() const
{
  list<Aluno>::const_iterator it = this->alunos.begin();

  double nAlunos = 0;
  while (it != this->alunos.end())
  {
    if (it->getMedia() >= Turma::NOTA_MIN_APROVADO)
    {
      nAlunos++;
    }
    it++;
  }

  return nAlunos;
}

int Turma::getNroAlunosParaFinal() const
{
  list<Aluno>::const_iterator it = this->alunos.begin();

  double nAlunos = 0;
  while (it != this->alunos.end())
  {
    if (it->getMedia() < Turma::NOTA_MIN_APROVADO &&
        it->getMedia() >= Turma::NOTA_MIN_RECUPARACAO)
    {
      nAlunos++;
    }
    it++;
  }

  return nAlunos;
}

int Turma::getNroAlunosReprovados() const
{
  list<Aluno>::const_iterator it = this->alunos.begin();

  double nAlunos = 0;
  while (it != this->alunos.end())
  {
    if (it->getMedia() < Turma::NOTA_MIN_RECUPARACAO)
    {
      nAlunos++;
    }
    it++;
  }

  return nAlunos;
}

string Turma::getNomeAlunosAbaixoMedia() const
{
  list<Aluno>::const_iterator it = this->alunos.begin();

  stringstream alunos("");
  double mediaTurma = this->getMediaTurma();
  while (it != this->alunos.end())
  {
    if (it->getMedia() < mediaTurma)
      alunos << it->getNome() << " | ";
    it++;
  }

  return alunos.str();
}

string Turma::gerarRelatorio() const
{
  stringstream ss("");
  ss << "Média da Turma: " << this->getMediaTurma() << endl;
  ss << "Número alunos (Total | Aprovados | P/Final | Reprovados): " << this->nVagasOcupadas << " | " << this->getNroAlunosAprovados() << " | " << this->getNroAlunosParaFinal() << " | " << this->getNroAlunosReprovados() << endl;
  ss << "Alunos abaixo da média: " << this->getNomeAlunosAbaixoMedia() << endl;
  return ss.str();
}
