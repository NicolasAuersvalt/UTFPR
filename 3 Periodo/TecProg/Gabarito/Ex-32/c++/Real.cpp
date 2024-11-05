#include "Real.hpp"

Real::Real(double valor) : 
    Complexo(valor, 0.0)
{
    
}

Real::~Real()
{
        
}

int Real::sinal() const
{
    if(real >= 0)
        return 1;
    else   
        return -1;
} 