#ifndef H_PROFESSOR
#define H_PROFESSOR

#include "Pessoa.hpp"

class Professor : 
    public Pessoa
{
private:
    string universidade;
    int anoIngresso;

public:
    Professor(string nome, char genero, int diaNasc, int mesNasc, int anoNasc, string universidade = "Sem Universidade", int anoIngresso = 2000);
    ~Professor();

    string obter_descricao();
};

#endif
