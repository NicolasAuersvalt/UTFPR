#include <iostream>

#include "Pessoa.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"

main()
{
    Pessoa mulher = Pessoa("Ada Lovelace", 'f', 10, 12, 1815);
    Pessoa homem;
    Aluno aluno = Aluno("Fulano", 'm', 31, 12, 2000, "Engenharia da Computacao", 2020);
    Professor professor = Professor("Ciclana", 'F', 15, 06, 1990, "UTFPR", 2015);

    cout << "Mulher: " << mulher.obter_descricao() << endl;
    cout << "Homem: " << homem.obter_descricao() << endl;
    cout << "Aluno(a): " << aluno.obter_descricao() << endl;
    cout << "Professor(a): " << professor.obter_descricao() << endl;

    return 0;
}