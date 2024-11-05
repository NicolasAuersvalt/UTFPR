#include<iostream>

struct Pessoa
{
    int dia;
    int mes;
    int ano;
    int idade;
};

int Calc_Idade(struct Pessoa p, int dia, int mes, int ano)
{
    int idd = ano - p.ano;
    if (p.mes > mes)
    {
        idd = idd - 1;
    }
    else
    {
        if (p.mes == mes)
    {
        if (p.dia > dia)
        {
            idd = idd - 1;
        }
    }
    }
    return idd;
}

int main()
{
    struct Pessoa Einstein, Newton;
    Einstein.dia = 14;
    Einstein.mes = 3;
    Einstein.ano = 1879;
    Newton.dia = 4;
    Newton.mes = 1;
    Newton.ano = 1643;
    Einstein.idade = Calc_Idade ( Einstein, 28, 8, 2009);
    Newton.idade = Calc_Idade ( Newton, 28, 8, 2009);
    printf("A idade de Einstein seria %d \n", Einstein.idade);
    printf("A idade de Newton seria %d \n", Newton.idade);
    getchar(); // serve para esperar caracter – segurar tela
    return 0;
}