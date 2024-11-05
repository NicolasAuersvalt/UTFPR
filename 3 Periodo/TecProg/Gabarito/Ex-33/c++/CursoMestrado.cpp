#include "CursoMestrado.hpp"

CursoMestrado::CursoMestrado(float const notaDefesa, string const nome,  int const cargaHorariaMin) :
        Curso(nome, cargaHorariaMin),
        notaDefesa(notaDefesa)
{

}

CursoMestrado::~CursoMestrado()
{

}

bool CursoMestrado::cumpriuCriterios(int const cargaHorariaCumprida, float nota) const
{
    if(cargaHorariaCumprida >= cargaHorariaMin &&
        nota >= this->notaDefesa)
    {
        return true;
    }
    else
    {
        return false;
    }
}