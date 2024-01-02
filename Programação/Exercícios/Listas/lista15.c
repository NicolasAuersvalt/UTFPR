#include <stdio.h>
#define N 100

int ehLetra (char c)
{
    int x = 0;
    if (c>='a' && c<='z')
        x = 1;

    return x;

}

int main()
{
    int i, cont=0;

    char palavra[N];

    fgets(palavra, N, stdin);

    for (i=0; i<N-1; i++)
    {
        if (ehLetra(palavra[i]) != ehLetra(palavra[i+1]))
        cont++;
        printf("ehL = %d\nehL = %d\n\n", ehLetra(palavra[i]), ehLetra(palavra[i+1]));
    }


    cont = cont/2 + 1;

    printf("%d", cont);

    return 0;
}
