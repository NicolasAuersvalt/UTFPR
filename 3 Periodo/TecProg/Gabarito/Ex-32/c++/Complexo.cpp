#include "Complexo.hpp"

Complexo::Complexo(const double real, const double imag) : 
    real(real), 
    imag(imag)
{

}

Complexo::~Complexo() 
{

}

double Complexo::modulo() const
{
    return sqrt( (real*real) +  (imag*imag) );
} 

double Complexo::angulo() const
{
    //Converte de rad para grau
    return  acos(real/modulo()) * 180.0 / M_PI;
}