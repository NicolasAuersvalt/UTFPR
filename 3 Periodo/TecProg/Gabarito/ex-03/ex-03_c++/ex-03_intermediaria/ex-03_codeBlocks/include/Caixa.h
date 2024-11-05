#ifndef CAIXA_H
#define CAIXA_H


class Caixa
{
    //Por definição, todos os membros
    //de uma classe em C++ são private,
    //a menos que se especifique o
    //contrário.
private:
    double largura;
    double altura;
    double profundidade;
    //A declaração public abaixo
    //especifica que todos os membros
    //a partir deste ponto são públicos
public:
    //cabeçalho/protótipo dos métodos
    bool setLargura(double largura);
    bool setAltura(double altura);
    bool setProfundidade(double profundidade);
    double calcularAreaExt();
    double calcularVolume();


};

#endif // CAIXA_H
