#include<bits/stdc++.h>

using namespace std;

int main(){

  int passos, len, qtd, camI, camJ, tamCaminho=0;
  // Entrada de dados: passos, len (dimensão da matriz), qtd (quantidade de entradas),
  // camI e camJ (caminho de início e fim)
  cin >> passos >> len >> qtd >> camI >> camJ;

  // Criação da matriz principal
  int** mat = new int*[len];

  // Matrizes de apoio e final
  int** apoio = new int*[len];
  int** final = new int*[len];

  // Inicializa as matrizes
  for(int i=1; i<=len; i++){
    mat[i] = new int[len];
    apoio[i] = new int[len];
    final[i] = new int[len];
  }

  // Preenche as matrizes com zeros
  for(int i=1;i<=len; i++){
    for(int j=1; j<=len; j++){
      mat[i][j] = 0;
      apoio[i][j] = 0;
      final[i][j] = 0; 
    }
  } 

  // Recebe as entradas de caminhos e preenche a matriz com 1's nas posições indicadas
  for(int i=0; i<qtd; i++){
      int a, b;
      cin >> a >> b;
      mat[a][b] = 1;
      final[a][b] = 1;
      apoio[a][b] = 1;
  }

  // Variável que controla se o caminho foi encontrado
  bool achou = true;

  // Calcula as potências da matriz de adjacência até encontrar um caminho
  for(tamCaminho=1; (tamCaminho<len) && achou; tamCaminho++){

    // Verifica se o caminho inicial já existe
    if(mat[camI][camJ]){
      achou = false;
      break;
    }

    // Multiplica as matrizes mat e apoio
    for(int i=1; i<=len; i++){
      for(int j=1; j<=len; j++){ // percorre as colunas da matriz

        int sum = 0;

        // Multiplica a linha da primeira matriz pela coluna da segunda
        for(int k=1; k<=len; k++){
          sum += mat[i][k] * apoio[k][j]; // soma os produtos dos elementos
        }

        // Armazena o resultado da soma na matriz final
        final[i][j] = sum;
      }
    }

    // Copia a matriz final para a matriz original para continuar o cálculo na próxima iteração
    for(int m=1; m<=len; m++){
      for(int n=1; n<=len; n++){
        mat[m][n] = final[m][n]; 
      }
    } 
  }

  // Caso não encontre um caminho válido
  if(achou){
    cout << "Não há caminho válido.";
    return 0;
  }

  // Caso encontre um caminho, exibe o número de passos necessários
  cout << "O menor número de caminhos, de " << camI << " até " << camJ << " é: ";
  cout << tamCaminho << endl;

  return 0;
}
