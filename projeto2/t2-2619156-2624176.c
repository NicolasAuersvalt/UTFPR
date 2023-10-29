// Nícolas Auersvalt Marques 
// Isabela Bella Bortoleto


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

// Função 2

int contaSaturacoes(double *dados, int n_amostras)
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

// Função 4

void limitaSinal(double *dados, int n_amostras, int n_passos)
{
    int posicoes, laterais;
    double coeficiente = 0.0, apoio = 0.0;

    for (posicoes = 0; posicoes < n_amostras;
         posicoes++)
    { // Percorre todas as posições

        if ((dados[posicoes] < -1.0) ||
            (dados[posicoes] > 1.0))
        { // Encontrou Saturação

            // Fórmula para determinar o coeficiente que
            // reduz a 1 ou -1 a saturação
            coeficiente = 1.0 / dados[posicoes];

            // Se coeficiente for negativo, torna-o positivo

            if (coeficiente < 0)
                coeficiente = -coeficiente;

            // Atualiza a posição

            dados[posicoes] *= coeficiente;

            // Atualiza o apoio que será usado para cada lateral
            // em função de sua magnitude
            apoio = (1 - coeficiente) / (n_passos + 1);

            // Percorre n_passos laterais, alterando cada
            for (laterais = 1; laterais <= n_passos; laterais++)
            {

                coeficiente += apoio;

                // À esquerda
                dados[(posicoes - laterais)] *= coeficiente;

                // À direita
                dados[(posicoes + laterais)] *= coeficiente;
            }
        }
    }
}

// Função 5

void geraOndaQuadrada(double *dados, int n_amostras, int taxa, double freq)
{
    double ciclo, meio_periodo;
    int valores, valor_atual = 1, ciclo_atual = 0;

    ciclo = (taxa / freq);
    meio_periodo = ciclo / 2;

    // Loop para gerar a onda quadrada
    for (valores = 0; valores < n_amostras; valores++)
    {
        dados[valores] = valor_atual;

        // Verifica se chegamos ao final de um ciclo
        if (valores >= (ciclo_atual + 1) * ciclo)
        {
            // Volta ao valor maximo
            valor_atual = 1;
            ciclo_atual++;
        }

        // Verifica se chegamos à metade de um ciclo para inverter o valor
        else if (valores >= (ciclo_atual * ciclo + meio_periodo))
        {
            // Muda para o valor minimo
            valor_atual = -1;
        }
    }
}
