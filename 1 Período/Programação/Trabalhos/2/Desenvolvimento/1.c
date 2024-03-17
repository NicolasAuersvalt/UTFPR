// Função 1

void mudaGanho(double *dados, int n_amostras, double ganho)
{
    double apoio;
    int posicao;

    // Analisa as amostras e aplica o ganho
    for (posicao = 0; posicao < n_amostras; posicao++)
    {
        if ((ganho != 1))
        {
            apoio = dados[posicao];
            dados[posicao] = apoio * ganho;
        }
    }
}


// Função 1

void mudaGanho(double *dados, int n_amostras, double ganho)
{
    double apoio;

    // Analisa as amostras e aplica o ganho
    for (int i = 0; i < n_amostras; i++)
    {
        if ((ganho != 1))
        {
          // apoio = dados[i];
          dados[i] = dados[i] * ganho;
          //dados[i] = apoio * ganho;


        }
    }
}



// Função 1

void mudaGanho(double *dados, int n_amostras, double ganho)
{
    double apoio;
    int posicao;

    // Analisa as amostras e aplica o ganho
    for (posicao = 0; posicao < n_amostras; posicao++)
    {
        if ((ganho != 1))
        {
            apoio = dados[posicao];
            dados[posicao] = apoio * ganho;
        }
    }
}





///HISTORICO

void mudaGanho(double *dados, int n_amostras, double ganho)
{
    double apoio;

    // Analisa as amostras e aplica o ganho
    for (int i = 0; i < n_amostras; i++)
    {
        if ((ganho != 1))
        {
          // Altera o valor por ganho
            apoio = dados[i];
            dados[i] = apoio * ganho;
        }
    }
}