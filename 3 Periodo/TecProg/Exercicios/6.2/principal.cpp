#include "principal.h"
#include <iostream>
using namespace std;

Principal::Principal():

	Nicolas("Nicolas", 23,11,2003),
	Sandra("Sandra", 16,05,1980)

{
	Nicolas.CalculaIdade(22,10,2024);
	Sandra.CalculaIdade(22,10,2024);
	cout << Nicolas.getNome() << " " << Nicolas.getIdade();
	cout << Sandra.getNome() << " " << Sandra.getIdade();
}
Principal::~Principal(){
}

