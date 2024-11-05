#ifndef H_COMPLEXO
#define H_COMPLEXO

#include <iostream> //Saida para o usuario
#include "math.h" //Calculos de numeros reais

class Complexo
{
protected:
    double real;
    double imag;

public:
    Complexo(const double real = 0.0, const double imag = 0.0);
    ~Complexo();

    double modulo() const; // Retorna o módulo do número complexo.
    double angulo() const; // Retorna o ângulo do número complexo em graus 0 à 180.

    //sets e gets
    void setReal(double real) { this->real = real; }
    void setImag(double imag) { this->imag = imag; }

    double getReal() const {return this->real;}
    double getImag() const {return this->imag;}
};

#endif