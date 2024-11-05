#include "ExTestadorDeCaixa.hpp"

//Construtor
ExTestadorDeCaixa::ExTestadorDeCaixa()
{

}

//Destrutor
ExTestadorDeCaixa::~ExTestadorDeCaixa()
{

}

//Obtém as dimensões de cada caixa
void ExTestadorDeCaixa::perguntaEntradas()
{
    int l, a, p;

    cout << "Qual a largura, altura e profundidade da caixa 1: ";
    cin >> l >> a >> p;
    cout << endl;

    if(!c1.setCaixa(l, a, p))
        exit(-1);

    cout << "Qual largura, altura e profundidade da caixa 2: ";
    cin >> l >> a >> p;
    cout << endl;

    if(!c2.setCaixa(l, a, p))
        exit(-1);
}

void ExTestadorDeCaixa::executar()
{
    perguntaEntradas();
    c1.printAreaVolume();
    c2.printAreaVolume();

}
