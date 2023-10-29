// Função 1

void mudaGanho(double *dados, int n_amostras, double ganho)
{
    double apoio;

    // Analisa as amostras e aplica o ganho
    for (int i = 0; i < n_amostras; i++)
    {
        if ((ganho != 1))
        {
            apoio = dados[i];
            dados[i] = apoio * ganho;
        }
    }
}
