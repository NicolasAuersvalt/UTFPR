#include "Pessoa.hpp"

class Aluno:public Pessoa{
    private:
        string curso;
    public:
    Aluno(const string nome="",const int idade=-1,const string curso="");
    ~Aluno();

    void Mostradados();
};