#include "Principal.hpp"

Principal::Principal()
{

}

Principal::~Principal()
{

}

//Obtém os valores de entrada dos colaboradores
void Principal::getColaboradores()
{
    cout << "EMPREGADO  -> 0" << endl;
    cout << "SOCIO      -> 1" << endl;
    cout << "ESTAGIARIO -> 2" << endl;
    char n[30];
    int vinculo, i, horasTrabalhadas;
    int temp;
    float hora;
    for(i = 0; i < 3; i++){
        cout << "Digite os dados do colaborador <nome> <vinculo>: ";
        cin >> n >> vinculo;
        cout << endl;
        colaboradores[i] = Colaborador(n, vinculo);

        //Se o vínculo é diferente de estagiário precisa perguntar o número de horas trabalhadas
        if(vinculo != ESTAGIARIO)
        {
            cout << "Digite o tempo de serviço do colaborador, o valor da hora de trabalho, e o número de horas trabalhadas <tempo> <hora> <numero>: ";
            cin >> temp >> hora >> horasTrabalhadas;
            cout << endl;

            colaboradores[i].setHorasTrabalha(horasTrabalhadas);

        }
        else
        {
            cout << "Digite o tempo de serviço do colaborador e o valor da hora de trabalho <tempo> <hora>: ";
            cin >> temp >> hora;
            cout << endl;

            colaboradores[i].setHorasTrabalha(HORAS_TRABALHADAS_MES_PADRAO);

        }
        colaboradores[i].setTempoServico(temp);
        colaboradores[i].setValorHoraTrabalho(hora);
    }

}

//Obtém colaborador com maior rendimento
Colaborador Principal::getMaiorRendimento()
{
    float rendimentoC1, rendimentoC2, rendimentoC3;
    rendimentoC1 = colaboradores[0].getRendimento();
    rendimentoC2 = colaboradores[1].getRendimento();
    rendimentoC3 = colaboradores[2].getRendimento();

    if(rendimentoC1 >= rendimentoC2)
    {
        if(rendimentoC1 >= rendimentoC3)
            return colaboradores[0];
        else
            return colaboradores[2];
    }
    else
    {
        if(rendimentoC2 >= rendimentoC3)
            return colaboradores[1];
        else
            return colaboradores[2];
    }
}

//Obtém colaborador com maior custo
Colaborador Principal::getMaiorCusto()
{
    float custoC1, custoC2, custoC3;
    custoC1 = colaboradores[0].getCusto();
    custoC2 = colaboradores[1].getCusto();
    custoC3 = colaboradores[2].getCusto();

    if(custoC1 >= custoC2)
    {
        if(custoC1 >= custoC3)
            return colaboradores[0];
        else
            return colaboradores[2];
    }
    else
    {
        if(custoC2 >= custoC3)
            return colaboradores[1];
        else
            return colaboradores[2];

    }
}

void Principal::executar()
{
    Colaborador rende, custa;
    getColaboradores();


    for (int i = 0; i < 3; i++) {
        colaboradores[i].calculaRendimento();
        colaboradores[i].calculaCusto();
    }

    rende = getMaiorRendimento();
    custa = getMaiorCusto();

    cout << "O colaborador com maior rendimento foi " << rende.getNome() << endl;
    cout << "O colaborador com maior custo foi " << custa.getNome() << endl;
}
