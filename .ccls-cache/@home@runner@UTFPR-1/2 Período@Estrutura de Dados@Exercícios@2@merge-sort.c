#include¨queue.c¨

Queue* merge(Queue *a, Queue *b){

	// Cria uma queue do tamanho do somatório das duas
	
	int higher, i, val1, val2;
	
	Queue *queue;
	queue = create((a->size + b->size));
	
	// pega o tamanho da maior delas
	//
	if((a->size)>(b->size))
		higher = a->size;
	else
		higher = b->size;

	// loop
	
	for(i=0; i<higher; i++){

		val2 = dequeue(b);

		if(empty(a)){
			// Preenche com os elementos da restante
			enqueue(queue, val2);
		}
		else{
		
			val1 = dequeue(a);

			if(a>b){ // A maior q B
				enqueue(queue, val2);
				enqueue(queue, val1);
			}

			else{
				enqueue(queue, val1);
				enqueue(queue, val2);
			}
		}
	}

	print(queue);

	return 0;
	
		// Verifica se a menor está vazia/cheia

		

		// Pega os elementos pelo Front

		// compara entre eles
		

		// adiciona o maior deles e depois o menor na nova queue

}

