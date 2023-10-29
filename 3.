// Função 3

int hardClipping(double *dados, int n_amostras, double limite)
{
    int amostras_alteradas = 0, cada_amostra;

    // Analisa as amostras
    for (cada_amostra = 0; cada_amostra < n_amostras; cada_amostra++)
    {
        if (dados[cada_amostra] > limite)
        {
            // Deixa magnitude dos picos igual ao limite superior
            dados[cada_amostra] = limite;
            amostras_alteradas++;
        }

        else if (dados[cada_amostra] < -limite)
        {
            // Deixa magnitude dos vales igual ao limite inferior
            dados[cada_amostra] = -limite;
            amostras_alteradas++;
        }
    }
    return amostras_alteradas;
}
