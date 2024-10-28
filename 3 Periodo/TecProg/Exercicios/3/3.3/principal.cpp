#include "principal.h"

Principal::Principal(){

	cout << "Hello World!" << endl;
	Executar();	
}

Principal::~Principal(){
}

int Principal::Executar(){
	cout << "Foi" << endl;
	Sec.Ex();
	return 0;
}
