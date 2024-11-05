#pragma once

#include "PolReg.h"

// Classe derivada de polígono regular
class Quadrado: public PolReg{
private:

public:
    // Construtora não precisa de número de lados pois o quadrado já tem 4 lados por default
    Quadrado(const double tamlados = 0);
    ~Quadrado();

    // Redefinição polimórfica do método 
    double calculaArea();
};