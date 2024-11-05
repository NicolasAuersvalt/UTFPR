
#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

class Universidade;
class Disciplina;

class Departamento
{
  private:
     char nome[130];

     // Associação para com uma Universidade.
     Universidade* pUniv;
     // Associação para com várias Disciplinas.
     Disciplina *pDisciplPrim;
     Disciplina *pDisciplAtual;

  public:
     Departamento();
     ~Departamento();

     void setNome(char* n);
     char* getNome();

     void setUniversidade(Universidade* pu);
     Universidade* getUniversidade();

     void setDisciplina ( Disciplina* pd );
     void listeDisciplinas();
     void listeDisciplinas2();
};

#endif
