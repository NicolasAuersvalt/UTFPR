#include <iostream>

using std::cout;
using std::endl;

#include "Curso.hpp"
#include "CursoMestrado.hpp"

int main()
{
    Curso cursoNormal("Nome do Curso", 60);
    CursoMestrado cursoMestrado(7.0, "Nome do Mestrado", 40);

    //Teste curso normal
    if(cursoNormal.cumpriuCriterios(90))
        cout << "Cumpriu o criterio do curso normal" << endl;
    else
        cout << "Nao cumpriu o criterio do curso normal" << endl;

    //Teste curso mestrado
    if(cursoMestrado.cumpriuCriterios(30,8.0))
        cout << "Cumpriu os criterios do curso Mestrado" << endl;
    else
        cout << "Nao cumpriu os criterios do curso Mestrado" << endl;

    return 0;
}