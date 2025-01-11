#include<iostream>
#include<string>

using namespace std;

class Pessoa{

    protected: 
        
        static int total_pessoas;
        string nome;
        int idade;

    public:
        
        Pessoa(string name, int idad) : nome(name), idade(idad){
            total_pessoas++;
        }
        
        ~Pessoa(){
            nome.erase();
        }
        void mostraDados(){

            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
        }
        void totalPessoas(){
            cout << "Total de " << total_pessoas << endl;
        }
};

int Pessoa::total_pessoas = 0;

class Aluno : public Pessoa{

    private:
        string curso;

    public:

        Aluno(string name, int idad, string course) : curso(course),
        Pessoa(name, idad){
        }
        

        ~Aluno(){
            nome.erase();
            curso.erase();
        }

        void mostraDados(){

            cout << "Nome: " << nome << endl;
            cout << "Idade: " << idade << endl;
            cout << "Curso: " << curso << endl;
        }

};


int main(){

    Pessoa Nicolas("Nicolas", 21);
    Nicolas.mostraDados();

    Nicolas.totalPessoas();

    Aluno Sandra("Sandra", 45, "Economia");
    Sandra.mostraDados();

    Nicolas.totalPessoas();

    return 0;
}