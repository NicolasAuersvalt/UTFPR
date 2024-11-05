#include "Professor.hpp"

Professor::Professor(string nome, char genero, int diaNasc, int mesNasc, int anoNasc, string universidade, int anoIngresso) :
    Pessoa(nome, genero, diaNasc, mesNasc, anoNasc), 
    universidade(universidade),
    anoIngresso(anoIngresso)
{

}

Professor::~Professor()
{

}

string Professor::obter_descricao()
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

    descricao += ", professor da " + universidade + " desde " + std::to_string(anoIngresso);

    return descricao;

}