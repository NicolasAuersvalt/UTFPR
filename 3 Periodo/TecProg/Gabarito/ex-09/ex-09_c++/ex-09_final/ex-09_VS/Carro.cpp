#include "Carro.hpp"

//Construtoras

Carro::Carro(float max, int cons, const char* n) : 
combustivelAt(0), distPerc(0), disPercLocal{0, 0}
{
    setNome(n);
    if(!setCombMax(max) || !setConsumo(cons))
        exit(0);
}

Carro::Carro() :
combustivelMax(1), combustivelAt(0), consumo(1), distPerc(0), disPercLocal{0, 0}
{
    setNome("");
}

//Destrutora
Carro::~Carro()
{

}

bool Carro::setCombMax(float max)
{
    //Testa de a capacidade máxima do tanque é válida
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

void Carro::setNome(const char* n)
{
    strcpy(nome, n);
}

float Carro::getCombustivel()
{
    return combustivelAt;
}

char* Carro::getNome()
{
    return nome;
}

//O carro anda uma distância dada no respectivo local (estrada ou cidade)
void Carro::andar(int dist, int local)
{
    //Verifica se o nível atual de combustível é o suficiente para percorrer a distância dada
    if(combustivelAt < (float)dist/consumo){
        cout << "Combustivel insuficiente." << endl;
        disPercLocal[local] += combustivelAt*consumo; //Soma a distância percorrida no local
        distPerc += combustivelAt*consumo;
        combustivelAt = 0;
    }
    //Se o nível de combustível é insuficiente, percorre somente a distância máxima possível com o combustível
    else{
        combustivelAt -= (float)dist/consumo;
        disPercLocal[local] += dist; //Soma a distância percorrida no local
        distPerc += dist;
    }
}

//O carro abastece o tanque com uma quantia dada
void Carro::abastecer(float quantComb)
{
    //Verifica se o abastecimento respeita a capacidade máxima do tanque
    if(quantComb + combustivelAt > combustivelMax)
        combustivelAt = combustivelMax;
    //Se não, abastece com a capacidade máxima do tanque
    else
        combustivelAt += quantComb;
}

//O carro realiza um viajem de uma distância e um nivel inicial de combustível no tanque, ambos parâmetros
void Carro::viajem(int dist, float comb)
{
    cout << "Faltam " << dist << " para chegar ao destino..." << endl << endl;
    
    //Abastece o carro antes de iniciar a viajem
    abastecer(comb);

    //Para utilizar valores aleatórios
    unsigned seed = time(0);
    srand(seed);

    //Executa enquanto não terminou o trajeto
    while(dist > 0)
    {
        int distTrajeto = rand()%10 + 1; //Obtém um valor aleatório de trajeto (1 até 10)

        //Arruma o valor do trajeto se for maior que a distância restante da viajem
        if(distTrajeto > dist)
            distTrajeto = dist;

        //Verifica se o combustível chegou em um nível critico, ou seja, precisa abastecer para não ficar na parado na estrada
        if(combustivelAt <= NIVEL_COMB_CRITICO)
            abastecer(combustivelMax/2); //Abastece com metade da capacidade máxima do tanque

        //Calcula aleatoriamente se o carro vai andar na estrada ou cidade
        andar(distTrajeto, rand()%2); 
        dist -= distTrajeto;
    }

    cout << "O carro " << nome << " viajou por " << distPerc << " Km, sendo que " << disPercLocal[CIDADE] << " Km eram na cidade, e " << disPercLocal[ESTRADA] << " Km eram na estrada." << endl << endl;
}
