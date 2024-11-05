#include "Carro.hpp"

//Construtoras
Carro::Carro(int max, int cons) : 
combustivelAt(0)
{
    if(!setCombMax(max) || !setConsumo(cons))
        exit(0);
}

Carro::Carro() :
combustivelMax(1), combustivelAt(0), consumo(1) //Inicializa os atributos com os valores mínimos de acordo com as restrições.
{

}

//Destrutora
Carro::~Carro()
{

}

//Set's
bool Carro::setCombMax(int max)
{
    //Testa se a capacidade máxima do tanque de combustível é válida
    if(max < 1)
    {
        cout << "Capacidade máxima do tanque inválida!" << endl;
        return false;
    }
    combustivelMax = max;
    return true;
}

bool Carro::setConsumo(int cons)
{
    //Testa se o valor de consumo é válido
    if(cons < 1)
    {
        cout << "Consumo do veículo incorreto!" << endl;
        return false;
    }
    consumo = cons;
    return true;
}

//Get's
int Carro::getCombustivel()
{
    return combustivelAt;
}

//O carro anda uma distância dada
void Carro::andar(int dist)
{
    if(combustivelAt < dist/consumo){
        cout << "Combustível insuficiente." << endl;
        combustivelAt = 0;
    }
    else
        combustivelAt -= dist/consumo;
}

//O carro abastece o tanque com um quantidade dada
void Carro::abastecer(int quantComb)
{
    combustivelAt += quantComb;
}
