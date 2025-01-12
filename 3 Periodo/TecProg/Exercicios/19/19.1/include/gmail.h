#ifndef GMAIL_H
#define GMAIL_H

#include "email.h"

class EMail;

class Gmail{

	private:
		EMail* email;

	public:
		Gmail(string assunto, string mensagem);
		~Gmail();

};

#endif
