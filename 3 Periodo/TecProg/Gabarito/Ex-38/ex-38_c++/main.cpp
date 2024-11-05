#include "Aluno.hpp"

int main(){
    Pessoa joao("Joao",20);
    joao.Mostradados();
    
    Aluno bruno("Bruno",19, "eng comp");
    
    //mostrando que um aluno tbm é uma Pessoa e é possível a conversão
    static_cast <Pessoa> (bruno).Mostradados();
    
    bruno.Mostradados();
    return 0;
}
