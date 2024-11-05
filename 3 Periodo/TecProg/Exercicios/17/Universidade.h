#ifndef UNIVERSIDADE_H
#define UNIVERSIDADE_H

#include <string>
using namespace std;

class Universidade {
    private:
        string nome;

    public:
        Universidade();
        ~Universidade();
        
        void setNome(string nome);
        string getNome();
};

#endif
