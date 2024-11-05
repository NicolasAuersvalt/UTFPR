#include "Principal.hpp"


Principal::Principal()
{

}

Principal::~Principal()
{

}

void Principal::executar()
{
    time_t tSac = time(NULL);
    tm tms = *localtime(&tSac);

    if(!Einstein.setDataNascimento(14, 3, 1879))
        exit(0);

    Einstein.setNome("Albert Einstein");
    Einstein.setIdade(tms.tm_mday, tms.tm_mon, tms.tm_year + 1900);

    if(!Newton.setDataNascimento(4, 1, 1643))
        exit(0);

    Newton.setNome("Isaac Newton");
    Newton.setIdade(tms.tm_mday, tms.tm_mon, tms.tm_year + 1900);

    Einstein.printIdadeNome();
    Newton.printIdadeNome();
}




