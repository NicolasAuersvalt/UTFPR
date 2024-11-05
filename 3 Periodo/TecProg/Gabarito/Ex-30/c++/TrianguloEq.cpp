#include "TrianguloEq.h"

TrianguloEq::TrianguloEq(const double tamlados):
    // Inicializa os valores dos atributos passados por parâmetro na construtora
    PolReg(3, tamlados){

}
TrianguloEq::~TrianguloEq(){
}

double TrianguloEq::calculaArea(){
    // Área = 3^(1/2)*l^2/4
    return sqrt(3)*pow(tam_lados,2)/4;
}