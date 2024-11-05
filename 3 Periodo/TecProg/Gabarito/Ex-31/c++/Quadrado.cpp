#include "Quadrado.h"

Quadrado::Quadrado(const double tamlados):
    // Inicializa os valores dos atributos passados por parâmetro na construtora
    PolReg(4, tamlados){
}

Quadrado::~Quadrado(){
}

double Quadrado::calculaArea(){
    // Área = l^2 = l * l 
    return tam_lados*tam_lados;
}
