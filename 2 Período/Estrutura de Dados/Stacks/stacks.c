#include <queue.h>

Queue create(int n){

  // Aloca espaço para nosso queue e retorna o endereço de memória alocado

  // Pacotinho completo, nele tem o valor de front
  // valor de back, valor de size e o endereço de memória alocada
  // para o tipo int só pra ele. Por meio desse pacotinho temos acesso a tudo
  // isso acessando queue->front, queue->back;

  
  Queue *queue = (Queue*) malloc (Queue);

  queue->front = 0;
  queue->back = 0;
  queue->size = n;

  // Aloca espaço para inteiros e dá o endereço ao nosso pacotinho

  queue->array = (int*) malloc((int)*n);


  // Retorna o endereço desse nosso pacotinho do tipo queue que tem
  // todas essas informações fáceis
  
  return queue;
}

Queue enqueue(Queue *queue, int n){ // Insere um valor na última posição

  // Move o valor de back + 1
  
}

Queue dequeue(Queue *queue){ // Remove um valor da primeira posição
  
}

Queue front(Queue *queue){ // Retorna o valor da primeira posição
  
}

Queue size(Queue *queue){ // Retorna o tamanho
  
}
Queue empty(Queue *queue){ // Retorna se está vazia ou não
  
}
Queue full(Queue *queue){ // Retorna se está cheia ou não
  
}