#pragma once

#include "PolReg.h"
#include "math.h"

// Classe derivada de polígono regular
class TrianguloEq: public PolReg{
private:

public:
    // Construtora não precisa de número de lados pois o triângulo já tem 3 lados por default
    TrianguloEq(const double tamlados = 0);
    ~TrianguloEq();

    // Redefinição polimórfica do método 
    double calculaArea();
};