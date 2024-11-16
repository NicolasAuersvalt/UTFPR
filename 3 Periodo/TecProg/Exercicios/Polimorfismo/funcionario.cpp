#include <iostream>
#include <string>

class Pessoa {
public:
    std::string nome;

    Pessoa(const std::string& nome) : nome(nome) {}

    // Método virtual
    void exibirInformacao() const {
        std::cout << "Nome: " << nome << std::endl;
    }
};

class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno(const std::string& nome, int matricula) : Pessoa(nome), matricula(matricula) {}

    // Substituição do método virtual
    void exibirInformacao() const {
        std::cout << "Matrícula: " << matricula << std::endl;
    }
};


int main() {
    Aluno* aluno = new Aluno("Ana", 12345);

    aluno->exibirInformacao();

    Pessoa* pessoa = static_cast<Pessoa*>(aluno);

    pessoa->exibirInformacao();

    delete pessoa;
    return 0;
}
