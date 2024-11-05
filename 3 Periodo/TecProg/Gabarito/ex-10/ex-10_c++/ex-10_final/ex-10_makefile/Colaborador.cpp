#include "Colaborador.hpp"

//Construtoras
Colaborador::Colaborador(const char* n, int vinc) :
tempoServico(0), horasTrabalha(HORAS_TRABALHADAS_MES_PADRAO), valorHoraTrabalho(0)
{
    setNome(n);
    if(!setVinculo(vinc))
        exit(0);
}

Colaborador::Colaborador() :
tempoServico(0), tipoVinculo(0), horasTrabalha(HORAS_TRABALHADAS_MES_PADRAO), valorHoraTrabalho(0)
{
    setNome("");
}

//Destrutora
Colaborador::~Colaborador()
{

}

//Set's
void Colaborador::setNome(const char* n)
{
    strcpy(nome, n);
}

bool Colaborador::setTempoServico(int temp)
{
    //Se o tempo de serviço é um valor válido
    if(temp < 0){
        cout << "Tempo de serviço incorreto!" << endl;
        return false;
    }
    tempoServico = temp;
    return true;
}

bool Colaborador::setVinculo(int vinc)
{
    //Testa se o tipo de vínculo é valido
    if(vinc < 0 || vinc > 2)
    {
        cout << "Vínculo incorreto!" << endl;
    }
    tipoVinculo = vinc;
    return true;
}

bool Colaborador::setValorHoraTrabalho(float valor)
{
    //Testa se o valor da hora de trabalho válida
    if(valor < 0)
    {
        cout << "Valor da hora de trabalho incorreto!" << endl;
        return false;
    }

    valorHoraTrabalho = valor;

    return true;
}

bool Colaborador::setHorasTrabalha(int horas)
{
    //Testa se a quantidade de horas trabalhadas em um dia é um valor válido
    if(horas < 0)
    {
        cout << "Número de horas trabalhadas por dia incorreto!" << endl;
    }
    horasTrabalha = horas;
    return true;
}

char* Colaborador::getNome()
{
    return nome;
}

float Colaborador::getRendimento()
{
    return rendimento;
}

float Colaborador::getCusto()
{
    return custo;
}

//Calcula o rendimento com base no vínculo e o número de horas trabalhadas
void Colaborador::calculaRendimento()
{
    int resto;
    int valorHoraTrabalhoTemp;

    switch (tipoVinculo)
    {
        case EMPREGADO:
            //Calcula o valor da hora de trabalho com base no tempo de serviço
            valorHoraTrabalhoTemp = valorHoraTrabalho * pow(1.1, tempoServico);

            rendimento = valorHoraTrabalhoTemp * horasTrabalha;

            //Verica se o empregado fez hora extra e calcula o rendimento das horas trabalhadas
            if(horasTrabalha > 144) 
            {
                resto = horasTrabalha - 144; //Periodo da hora extra
                rendimento += resto * valorHoraTrabalhoTemp * 0.5;
            }
            break;
        default:
            rendimento = valorHoraTrabalho * horasTrabalha;
    }
}

//Calcula o custo de um colaborador
void Colaborador::calculaCusto()
{
    switch (tipoVinculo)
    {
        case EMPREGADO:
            custo = rendimento * 1.8;
            break;
        default:
            custo = rendimento;
    }
}
