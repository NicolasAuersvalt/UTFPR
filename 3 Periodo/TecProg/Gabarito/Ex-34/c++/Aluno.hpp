#ifndef H_ALUNO
#define H_ALUNO

#include "Pessoa.hpp"

class Aluno :
    public Pessoa
{
private:
    string curso;
    int anoIngresso;

public:
    Aluno(string nome, char genero, int diaNasc, int mesNasc, int anoNasc, string curso = "Sem Curso", int anoIngresso = 2000);
    ~Aluno();

    string obter_descricao();
};

#endif