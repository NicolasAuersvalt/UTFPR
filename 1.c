void mudaGanho(double* dados, int n_amostras, double ganho)
{
    double apoio;
    for (int i = 0; i < n_amostras; i++)
    {
        if ((ganho >= 1) || (ganho < 0))
        {
            apoio = dados[i]; //perguntar se eh necessario manter a variável de apoio
            dados[i] = apoio * ganho;
        }
        else
        {
            dados[i] = 0;
        }
    }
}


// Alterado


void mudaGanho(double* dados, int n_amostras, double ganho) 
{   
    int i;

    // Analisa as amostras e aplica o ganho
    for (i = 0; i < n_amostras; i++) 
    {
        dados[i] *= ganho;
    }
}

