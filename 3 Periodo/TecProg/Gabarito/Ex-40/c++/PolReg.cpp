#include "PolReg.h"

PolReg::PolReg(const int numlados, const double tamlados):
    // Inicializa os valores dos atributos passados por parâmetro na construtora
    num_lados(numlados), tam_lados(tamlados){
}
PolReg::~PolReg(){
}

double PolReg::calculaPerimetro() const{
    // Perímetro = n * l
    return num_lados * tam_lados;
}
int PolReg::calculaAnguloInterno() const{
    // Ângulo Interno = (n - 2) * 180
    return (num_lados - 2) * 180; 
}
