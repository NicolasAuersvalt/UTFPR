#include<iostream>

struct Pessoa
{
    int dia;
    int mes;
    int ano;
    int idade;
};

void Calc_Idade (struct Pessoa *p, int dia, int mes, int ano)
{
    p->idade = ano – p->ano;
    if ( p->mes > mes )
        {
            p->idade = p->idade - 1;
        }
    else
        {
            if ( p->mes == mes )
        {
    if ( p->dia > dia )
        {
            p->idade = p->idade - 1;
        }
    }
}
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
    Calc_Idade ( &Einstein, 24, 8, 2009);
    Calc_Idade ( &Newton, 24, 8, 2009); 
    printf("A idade de Einstein seria %d \n", Einstein.idade);
    printf("A idade de Newton seria %d \n", Newton.idade);
    getchar(); // serve para esperar caracter – segurar tela
    return 0;
}