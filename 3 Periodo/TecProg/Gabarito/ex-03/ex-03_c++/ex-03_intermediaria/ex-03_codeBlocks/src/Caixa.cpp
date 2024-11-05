//Indicando o caminho relativo
//do Caixa.h. Este tipo de
//configuração geralmente pode
//ser feito no próprio ambiente
//(no caso, opções do Code::Blocks)
#include "..\include\Caixa.h"

//Lembrar de incluir o operador
//:: (resolução de escopo) para
//indicar que setLargura é um
//método da classe Caixa.
bool Caixa::setLargura(double largura)
{
    if (largura > 0)
    {

        //largura "deste objeto" (ou seja, o
        //atributo) recebe largura que é o
        //parâmetro.
        //Diferença em relação a
        //Java: para usar o this
        //em C++, utilizar o
        //operador de seta (->)
        this->largura = largura;
        return true;
    }
    return false;
}

bool Caixa::setAltura(double altura)
{
    if (altura > 0)
    {
        this->altura = altura;
        return true;
    }
    return false;
}

bool Caixa::setProfundidade(double profundidade)
{
    if (profundidade > 0)
    {
        this->profundidade = profundidade;
        return true;
    }
    return false;
}

double Caixa::calcularAreaExt()
{
    //variável local do método -> deixa de
    //existir quando o método retorna
    double area;
    area = 2*(largura*altura + largura*profundidade + altura*profundidade);
    return area;
}

    //Idem às considerações para o calcularAreaExt
double Caixa::calcularVolume()
{
    //variável local do método -> deixa de
    //existir quando o método retorna
    double volume;
    volume = largura*altura*profundidade;
    return volume;
}
