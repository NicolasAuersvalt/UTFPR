#pragma once

#include "Poligono.h"

class Principal {
private:
    Poligono polig;

public:
    Principal();
    ~Principal();

private:
    void exec();
    void lerPonto();
    void imprimirPerimetro();
    void removerPonto();
};
