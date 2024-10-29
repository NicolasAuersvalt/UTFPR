#include "stdafx.h"
#include "Estrela.h"
#include "Planeta.h"

Estrela::Estrela() : Astro()
{
    cout << " I am Shining " << endl;
    tempo_existencia = 0;
    pPlaneta = NULL;

}

Estrela::~Estrela(){



}