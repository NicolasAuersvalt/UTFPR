#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Caixa
{
private:
    int largura, altura, profundidade;

public:
    //Construtora
    Caixa();

    //Destrutora
    ~Caixa();

    //Funções Set's
    bool setLargura(int l);
    bool setAltura(int a);
    bool setProfundidade(int p);
    bool setCaixa(int l, int a, int p);

    //Calcula área externa da caixa
    int calcAreaExt(int l, int a, int p);

    //Calcula volume da caixa
    int calcVolume(int l, int a, int p);

    //Imprime na tela de saída a área
    void printAreaExt();

    //Imprime na tela de saída o volume
    void printVolume();

    //Imprime na tela de saída a área e o volume
    void printAreaVolume();
};
