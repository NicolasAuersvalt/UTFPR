typedef struct
{
  int largura;
  int altura;
  unsigned char** dados;
} GSImage;

void destroiGSImage (GSImage* img)
{
  int i;
  for (i = 0; i < img->altura; i++)
  free (img->dados [i]);
  free (img->dados);
  free (img);
}

// Escreva uma função que aloca a memória para uma variável do tipo GSImage. Esta função deve
// alocar dinamicamente a memória para a variável e sua matriz de dados, preencher os campos da
// struct adequadamente, e retornar um ponteiro para o espaço alocado. O protótipo da função deve
// ser:

GSImage* criaGSImage (int largura, int altura){

  GSImage *img;
  int i;

  img = (*GSImage) malloc (sizeof(GSImage))

  img->largura = largura;
  img->altura = altura;

  img->dados = (unsigned char**)malloc(altura * sizeof(unsigned char*))
  
}