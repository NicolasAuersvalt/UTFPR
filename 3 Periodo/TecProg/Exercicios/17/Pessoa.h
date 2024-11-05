#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include "Universidade.h"
using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;
        Universidade *Univ;

    public:
        Pessoa();
        ~Pessoa();

        void setNome(string nomePessoa);
        string getNome();
        
        void setIdade(int idade);
        int getIdade();
        
        void setUniversidade(Universidade* uni);
        string getUniversidade();
};

#endif
