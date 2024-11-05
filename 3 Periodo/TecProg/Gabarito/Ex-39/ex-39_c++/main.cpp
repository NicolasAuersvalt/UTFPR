#include "Aluno.hpp"

int main(){
    Pessoa joao("Joao",20);
    
    joao.Mostradados();
    
    Aluno bruno("Bruno",19, "eng comp");
    
    static_cast <Pessoa*> (&bruno)->Mostradados();
    /*
    troquei pra ponteiro, caso contrário ele iria criar um objeto de Pessoa auxiliar 
    e depois chamaria a destrutora desse auxiliar estragando a contagem
    (existem formas melhores para contornar esse tipo de problema)
    */     

    bruno.Mostradados();

    cout<<"Foram criadas "<<Pessoa::QuantidadePessoas()<<" pessoas"<<endl;

    return 0;
}