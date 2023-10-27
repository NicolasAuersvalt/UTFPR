int contaSaturacoes(double* dados, int n_amostras)
{
    int n_sat = 0, pos;

    for (pos = 0; pos < n_amostras; pos++)
    {
        if ((dados[pos] < 1) && (dados[pos] > -1))
        {
            n_sat++;
        }
    }
    return n_sat;
}
