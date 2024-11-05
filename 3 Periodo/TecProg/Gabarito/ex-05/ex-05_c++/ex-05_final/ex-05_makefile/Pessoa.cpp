#include "Pessoa.hpp"

//Construtora
Pessoa::Pessoa() :
idade(0), dia(0), mes(0), ano(0), nome("")
{

}

//Destrutora
Pessoa::~Pessoa()
{

}

//Funções Set's
void Pessoa::setIdade(int diaAt, int mesAt, int anoAt)
{
    idade = calculaIdade(diaAt, mesAt, anoAt);
}

bool Pessoa::setDia(int d)
{
    //Testa se o dia está correto
    if(d < 0 || d > 31)
    {
        cout << "Dia incorreto!" << endl;
        return false;
    }
    dia = d;
    return true;
}

bool Pessoa::setMes(int m)
{
    //Testa se o mês está correto
    if(m < 1 || m > 12)
    {
        cout << "Mes incorreto!" << endl;
        return false;
    }
    mes = m;
    return true;
}

bool Pessoa::setAno(int a)
{
    //Testa se o ano está correto
    if(a < 0)
    {
        cout << "Ano incorreto!" << endl;
        return false;
    }
    ano = a;
    return true;
}

void Pessoa::setNome(const char* n)
{
    strcpy(nome, n);
}


bool Pessoa::setDataNascimento(int d, int m, int a)
{
    return setDia(d) && setMes(m) && setAno(a);
}

//Funções Get's
int Pessoa::getIdade()
{
    return idade;
}

const char* Pessoa::getNome()
{
    return nome;
}

//Calcula a idade
int Pessoa::calculaIdade(int diaAt, int mesAt, int anoAt)
{
    int i = anoAt - ano;

    if(mes > mesAt)
        i--;
    else if(mes == mesAt)
    {
        if(dia > diaAt)
            i--;
    }
    return i;
}

//Imprime na tela de saída a idade e o nome
void Pessoa::printIdadeNome()
{
    cout << "A idade de " << nome << " é " << idade << endl;
}
