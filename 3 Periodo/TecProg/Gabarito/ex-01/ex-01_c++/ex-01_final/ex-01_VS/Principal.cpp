#include "Principal.hpp"

//Construtora
Principal::Principal()
{

}

//Destrutora
Principal::~Principal()
{

}

//Funções Set's
void Principal::setHorarioEntrada(int h, int m)
{
    if (!entrada.setHora(h) || !entrada.setMin(m))
        exit(-1);
}

void Principal::setHorarioSaida(int h, int m)
{
    if (!saida.setHora(h) || !saida.setMin(m))
        exit(-1);
}

//Obtém dos valores do horário de entrada e saída pelo terminal
void Principal::setHorarios()
{
    int h, m;

    //Pede o horário de entrada
    cout << "Escreva o horario de entrada (Formato: hh mm) :";
    cin >> h >> m;
    cout << endl;

    setHorarioEntrada(h, m);

    //Pede o horário de saída
    cout << "Escreva o horario de saida (Formato: hh mm) : ";
    cin >> h >> m;
    cout << endl;

    setHorarioSaida(h, m);
}

//Calcula o custo de um intervalo de horários
float Principal::calculaCusto()
{
    float custo;
    int intervalo = entrada.calculaIntervalo(saida);
    if(intervalo < 3*HORA_PARA_MIN)
        custo = 4.5; // Custo padrão inferior
    else if(intervalo >= 3* HORA_PARA_MIN && intervalo <= 12* HORA_PARA_MIN){
        custo = 4.5 + ((intervalo - HORA_PARA_MIN *3)/15)*0.75; //Custo base + número de bloco de 15 minutos de tempo excendente * custo
    }
    else
        custo = 33.0; // Custo padrão superior

    return custo;
}

void Principal::executar()
{
    setHorarios();
    cout << "O custo foi de R$" << calculaCusto() << endl;
}
