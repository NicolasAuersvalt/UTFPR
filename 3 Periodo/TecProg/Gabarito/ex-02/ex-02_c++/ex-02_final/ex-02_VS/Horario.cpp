#include "Horario.hpp"

//Construtoras
Horario::Horario(int h, int m)
{
    if (!setHora(h) || !setMin(m))
        exit(-1);
}

Horario::Horario() :
hora(0), min(0)
{

}

//Destrutora
Horario::~Horario()
{

}

//Funções Set's
bool Horario::setHora(int h)
{
    //Testa se h é um valor de hora válido
    if(h >= 0 && h <= MAX_HORA)
    {
        hora = h;
        return true;
    }
    return false;
}

bool Horario::setMin(int m)
{
    //Testa se m é um valor de minuto válido
    if(m >= 0 && m <= MAX_MIN)
    {
        min = m;
        return true;
    }
    return false;
}

//Funções Get's
int Horario::getHora()
{
    return hora;
}

int Horario::getMin()
{
    return min;
}

//Calcula o intervalo de tempo com um horário dado
int Horario::calculaIntervalo(Horario horario)
{
    //Calcula a diferença entre as horas (transformada em minutos) + diferença entre os minutos
    int intervalo = (horario.getHora() - hora)*HORA_PARA_MIN + horario.getMin() - min;

    //Se o intervalo é negativo, passou mais de um dia.
    return intervalo > 0 ? intervalo : intervalo + MIN_POR_DIA;
}