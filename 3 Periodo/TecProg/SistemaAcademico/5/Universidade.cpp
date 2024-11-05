#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade()
{
    indice = 0;

    for (int i = 0; i < 50; i++)
	{
		pDptos[indice] = NULL;
	}
}

Universidade::~Universidade()
{
}

char* Universidade::getNome()
{
   return nome;
}

void Universidade::setNome(char* n)
{
   strcpy(nome, n);
}

void Universidade::setDepartamento(Departamento* pdep)
{
   if (indice < 50)
   {
		pDptos[indice] = pdep;
		indice++;    // indice = indice + 1;
   }
   else
   {
		cout << "A universidade soh pode ter até 50 departamentos..." << endl;
   }
}

