#include "principal.h"
#include <iostream>
using namespace std;

Principal::Principal(){
	Nicolas.setNome("Nícolas");
	Sandra.setNome("Sandra");

	Nicolas.setDataDeNascimento(23, 11, 2003);
	Sandra.setDataDeNascimento(16,05,1980);
	cout << Nicolas.getNome() << " " << Nicolas.getIdade();
	cout << Sandra.getNome() << " " << Sandra.getIdade();
}
Principal::~Principal(){
}

