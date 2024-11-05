#include "Aluno.hpp"

Aluno::Aluno(string nome, char genero, int diaNasc, int mesNasc, int anoNasc, string curso, int anoIngresso):
    Pessoa(nome, genero, diaNasc, mesNasc, anoNasc), 
    curso(curso),
    anoIngresso(anoIngresso)
{

}

Aluno::~Aluno()
{

}

string Aluno::obter_descricao()
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

    descricao += ", cursa " + curso + " desde " + std::to_string(anoIngresso);

    return descricao;
}