#ifndef ASSUNTO_H
#define ASSUNTO_H

#include <string>

using namespace std;

class Assunto{

	private:
		string texto;

	public:
		Assunto();
		~Assunto();
		void setTexto(const string& texto);
		string getTexto();

};

#endif
