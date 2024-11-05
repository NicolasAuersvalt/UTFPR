#include "Caixa.hpp"

//Construtora
Caixa::Caixa() :
largura(0), altura(0), profundidade(0)
{

}

//Destrutora
Caixa::~Caixa()
{

}

//Funções Set's
bool Caixa::setLargura(int l)
{
    //Verifica se a largura é válida
    if(l <= 0) 
    {
        cout << "Largura incorreta!" << endl;
        return false;
    }
    largura = l;
    return true;
}

bool Caixa::setAltura(int a)
{
    //Verifica se a altura é válida
    if(a <= 0)
    {
        cout << "Altura incorreta!" << endl;
        return false;
    }
    altura = a;
    return true;
}

bool Caixa::setProfundidade(int p)
{
    //Verifica se a profundidade é válida
    if(p <= 0)
    {
        cout << "Profundidade incorreta!" << endl;
        return false;
    }
    profundidade = p;
    return true;
}

bool Caixa::setCaixa(int l, int a, int p)
{
    //Testa se as dimesões possuem valores corretos
    if(setLargura(l) && setAltura(a) && setProfundidade(p))
        return true;
    return false;
}

//Calcula área externa da caixa
int Caixa::calcAreaExt(int l, int a, int p)
{
    return 2*(l*a + l*p + a*p);
}

//Calcula volume da caixa
int Caixa::calcVolume(int l, int a, int p)
{
    return l*a*p;
}

//Imprime na tela de saída a área
void Caixa::printAreaExt()
{
    cout << "A área externa da caixa é " << calcAreaExt(largura, altura, profundidade) << endl;
}

//Imprime na tela de saída o volume
void Caixa::printVolume()
{
    cout << "O volume da caixa é " << calcVolume(largura, altura, profundidade) << endl;
}

//Imprime na tela de saída a área e o volume
void Caixa::printAreaVolume()
{
    printAreaExt();
    printVolume();
}
