#include <iostream>

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

#include "Faxineiro.hpp"
#include "Gerente.hpp"

int main()
{
    // Vetor de empregados
    vector<Empregado*> empregados;
    vector<Empregado*>::iterator iterador;
    Empregado *pEmpregado = NULL;
    int qntDeEmpregados = 0;
    
    // Variaveis de controle
    int op, cont;
    float somaSalarios;
    
    // Variaveis para cadasto
    string nome;
    int CPF, horaTrabalhada;
    float bonus;

    // Programa
    cout << "Entre com a quantidade de empregados que deseja cadastrar:";
    cin >> qntDeEmpregados;
    
    somaSalarios = 0;
    cont = 0;
    while(cont < qntDeEmpregados) {
        cout << "Entre com o indice do funcionario: " << endl;
        cout << "1. Faxineiro" << endl;
        cout << "2. Gerente" << endl;
        cin >> op;

        if(op != 1 && op != 2)
            cout << "Indice invalido!" << endl;
        else {
            cout << "Nome: ";
            cin >> nome;
            cout << "CPF: ";
            cin >> CPF;
            cout << "Horas trabalhadas: ";
            cin >> horaTrabalhada;

            if(op == 1) {
                pEmpregado = new Faxineiro(nome, CPF);
            }
            else {
                cout << "Bonus: ";
                cin >> bonus;
                pEmpregado = new Gerente(nome, CPF, bonus);
            }

            if(pEmpregado != NULL) {
                // Insere no vetor e soma o salario ao total
                empregados.push_back(pEmpregado);
                somaSalarios += pEmpregado->calculaSalario(horaTrabalhada);
                cout << "Salario: R$ " << pEmpregado->calculaSalario(horaTrabalhada) << endl;
                cont++;
            }
            else {
                cout << "Nao foi possivel criar funcionario. Finalizando programa" << endl;
                return 0;
            }
        }
    }

    // Impressao dos dados dos funcionarios
    for(iterador = empregados.begin(); iterador != empregados.end(); iterador++) {
        pEmpregado = *iterador;
        pEmpregado->mostraDados();
    }

    // Soma dos salarios
    cout << "Soma dos salarios: R$ " << somaSalarios << endl;

    // Desalocação de memoria
    while (!empregados.empty()) {
        // Desaloca o funcionado alocado dinamicamente
        delete(*empregados.begin());
        // Remove o ponteiro do vetor
        empregados.erase(empregados.begin());
    }

    return 0;
}