#ifndef H_CURSO
#define H_CURSO

#include <string>

using std::string;

class Curso
{
protected:
    int cargaHorariaMin;
    string nome;

public:
    Curso(string const nome = "Sem Nome", int const cargaHorariaMin = 0);
    ~Curso();

    bool cumpriuCriterios(int const cargaHorariaCumprida) const;
    string getNome() const;
};

#endif