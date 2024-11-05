#ifndef _LALUNO_H_
#define _LALUNO_H_

#include "Aluno.h"

class ElAluno
{
 private:
    Aluno* pAluno;
 public:
    ElAluno( );
    ~ElAluno( );
    ElAluno *pProx;
    ElAluno *pAnte;
    void setAluno(Aluno* pa);
    Aluno* getAluno ( );
    char* getNome();
};

#endif
