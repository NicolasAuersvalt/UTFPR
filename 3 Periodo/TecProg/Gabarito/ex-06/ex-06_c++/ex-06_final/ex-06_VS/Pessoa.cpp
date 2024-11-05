#include "Pessoa.hpp"

Pessoa::Pessoa(int diaNas, int mesNas, int anoNas, const char* n)
{
    if(!setDataNascimento(diaNas, mesNas, anoNas))
        exit(0);
    strcpy(nome, n);

    time_t tSac = time(NULL);
    tm tms = *localtime(&tSac);

    setIdade(tms.tm_mday, tms.tm_mon, tms.tm_year + 1900);
}

Pessoa::Pessoa() :
idade(0), dia(0), mes(0), ano(0), nome("")
{

}

Pessoa::~Pessoa()
{

}

void Pessoa::setIdade(int diaAt, int mesAt, int anoAt)
{
    idade = calculaIdade(diaAt, mesAt, anoAt);
}

bool Pessoa::setDia(int d)
{
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

int Pessoa::getIdade()
{
    return idade;
}

const char* Pessoa::getNome()
{
    return nome;
}

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

void Pessoa::printIdadeNome()
{
    cout << "A idade de " << getNome() << " é " << getIdade() << endl;
}
