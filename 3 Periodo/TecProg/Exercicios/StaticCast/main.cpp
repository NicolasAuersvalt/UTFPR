#include<iostream>
#include <string>

using namespace std;

class Pessoa {
private:
    int idade;

public:
    string nome;
    Pessoa(){}
    ~Pessoa(){}

    void setIdade(int idade) {
        this->idade = idade;
    }

    void exibirInformacoes() const {
        cout << "Nome: " << nome << ", Idade: " << idade << std::endl;
    }
};



class Aluno : public Pessoa{

    private:

        int matricula;

    public:
        Aluno(){}
        ~Aluno(){
            matricula = -1;
        }
        void setMatricula(int matricula) {
            this->matricula = matricula;
        }

        void exibirInformacoesAluno(){
            cout << "Matricula: " << matricula << endl;
        }

};


int main(){

    Aluno* aluno = new Aluno();

    aluno->nome = "Nicolas";
    aluno->setIdade(20);
    aluno->setMatricula(12345);


    Pessoa* pessoa = static_cast<Pessoa*>(aluno);

    cout << "\nInformações da Pessoa (usando Pessoa*):" << std::endl;
    pessoa->exibirInformacoes();    

    cout << exibirInformacoesAluno << endl

    return 0;
}