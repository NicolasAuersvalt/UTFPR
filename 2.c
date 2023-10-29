// Função 2

int contaSaturacoes(double* dados, int n_amostras)
{
    int n_sat = 0, pos;
  
    // Analisa se as amostras saturam
    for (pos = 0; pos < n_amostras; pos++)
    {
      // Se saturar (valor maior que 1 ou menor que -1, pois será módulo)
        if (dados[pos] > 1 || dados[pos] < -1)
        {
            n_sat++;
        }
    }
  
    // Retorna numero de saturacoes
    return n_sat;
}
