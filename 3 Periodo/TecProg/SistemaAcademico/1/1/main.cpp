#include<iostream>


struct Pessoa
{
    int dia;
    int mes;
    int ano;
    int idade;
};

// Função que recebe a struct pessoa
int Calc_Idade ( struct Pessoa p, int ano )
{
    int idd = ano - p.ano;
    return idd;
}

int main()
{
    // Cria duas estruturas Einstein e Newton
    struct Pessoa Einstein, Newton;
    Einstein.dia = 14;
    Einstein.mes = 3;
    Einstein.ano = 1879;
    Newton.dia = 4;
    Newton.mes = 1;
    Newton.ano = 1643;
    Einstein.idade = Calc_Idade ( Einstein, 2009 );
    Newton.idade = Calc_Idade ( Newton, 2009 );
    printf("A idade de Einstein seria %d \n", Einstein.idade);
    printf("A idade de Newton seria %d \n", Newton.idade);
    getchar();
    return 0;
}