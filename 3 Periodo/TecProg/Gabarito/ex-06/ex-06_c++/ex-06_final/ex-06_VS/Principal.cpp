#include "Principal.hpp"


Principal::Principal() :
Einstein(14, 3, 1879, "Albert Einstein"), Newton(4, 1, 1643, "Isaac Newton")
{   

}

Principal::~Principal()
{

}

void Principal::executar()
{
    Einstein.printIdadeNome();
    Newton.printIdadeNome();
}




