#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Pessoa
{
private:
    int idade, dia, mes, ano;
    char nome[30];
public:
    //Construtoras
    Pessoa(int diaNas, int mesNas, int anoNas, const char* n);
    Pessoa();

    //Destrutora
    ~Pessoa();

    void setIdade(int diaAt, int mesAt, int anoAt);
    bool setDia(int d);
    bool setMes(int m);
    bool setAno(int a);
    void setNome(const char* n);
    bool setDataNascimento(int i, int d, int a);

    int getIdade();
    const char* getNome();

    int calculaIdade(int diaAt, int mesAt, int anoAt);

    void printIdadeNome();
};
