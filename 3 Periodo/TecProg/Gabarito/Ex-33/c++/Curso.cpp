#include "Curso.hpp"

Curso::Curso(string const nome, int const cargaHorariaMin) :
    nome(nome),
    cargaHorariaMin(cargaHorariaMin)
{

}

Curso::~Curso()
{

}

bool Curso::cumpriuCriterios(int const cargaHorariaCumprida) const
{
    if(cargaHorariaCumprida >= cargaHorariaMin)
        return true;
    else
        return false;
}

string Curso::getNome() const
{
    return nome;
}