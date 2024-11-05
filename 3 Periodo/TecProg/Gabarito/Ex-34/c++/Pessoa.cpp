#include "Pessoa.hpp"

Pessoa::Pessoa(string nome, char genero, int diaNasc, int mesNasc, int anoNasc)
{
    this->nome = nome;
    setGenero(genero);
    setDataNascimento(diaNasc, mesNasc, anoNasc);
}

Pessoa::~Pessoa()
{

}

string Pessoa::obter_descricao()
{
    string descricao = "";
    
    //Nome
    descricao += nome + ", ";

    //Genero
    if(genero == 'f' || genero == 'F')
        descricao += "Mulher, ";
    else
        descricao += "Homem, ";

    //Nascimento
    descricao += "nasceu em ";
    descricao += std::to_string(diaNasc) + "/" + std::to_string(mesNasc) + "/" + std::to_string(anoNasc);

    return descricao;
}

void Pessoa::setDataNascimento(int d, int m, int a)
{
    if(d > 0 && d <= 31 && m > 0 && m <= 12)
    {
        //Nao esta considerando ano bissesto
        if(d <= 28)
        {
            this->diaNasc = d;
            this->mesNasc = m;
            this->anoNasc = a;
        }
        else
        {
            if( d > 28 && m == 2 || 
                d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
            {
                cout << "Dia invalido para este mes! Data inicializada com valor default" << endl;
                this->diaNasc = 1;
                this->mesNasc = 1;
                this->anoNasc = 1970;
            }
            else
            {
                this->diaNasc = d;
                this->mesNasc = m;
                this->anoNasc = a;
            }
        }
    }
    else
    {
        cout << "Data de nascimento invalida! Data inicializada com valor default" << endl;
        this->diaNasc = 1;
        this->mesNasc = 1;
        this->anoNasc = 1970;
    }
}

void Pessoa::setGenero(char g)
{
    if(g == 'm' || g == 'M')
        this->genero = g;
    else if(g == 'f' || g == 'F')
        this->genero = g;
    else
        cout << "Genero " << g << " invalido! Nao foi setado!" << endl;
}