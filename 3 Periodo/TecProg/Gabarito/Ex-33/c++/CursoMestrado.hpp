#ifndef H_CURSO_MESTRADO
#define H_CURSO_MESTRADO

#include "Curso.hpp"

class CursoMestrado : 
    public Curso
{
private:
    float notaDefesa;

public:
    CursoMestrado(float const notaDefesa = 0, 
        string const nome = "Sem Nome", 
        int const cargaHorariaMin = 0);
    ~CursoMestrado();

    //Nao é polimorfismo, pois a funcao da base nao eh virtual e os argumentos sao diferentes
    bool cumpriuCriterios(int const cargaHorariaCumprida, float nota) const;

};

#endif