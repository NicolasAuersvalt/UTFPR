#include <iostream>
#include <string>

class Pessoa {
public:
    std::string nome;

    Pessoa(const std::string& nome) : nome(nome) {}

    // Método virtual
    virtual void exibirInformacao() const {
        std::cout << "Nome: " << nome << std::endl;
    }
};

class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno(const std::string& nome, int matricula) : Pessoa(nome), matricula(matricula) {}

    // Substituição do método virtual
    void exibirInformacao() const override {
        std::cout << "Nome: " << nome << ", Matrícula: " << matricula << std::endl;
    }
};


int main() {
    Pessoa* pessoa1 = new Pessoa("Carlos");
    Pessoa* pessoa2 = new Aluno("Ana", 12345);

    pessoa1->exibirInformacao();  // Chama Pessoa::exibirInformacao
    pessoa2->exibirInformacao();  // Chama Aluno::exibirInformacao devido ao polimorfismo

    delete pessoa1;
    delete pessoa2;
    return 0;
}
