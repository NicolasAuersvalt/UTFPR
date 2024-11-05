public class Pilha <T> {
    private final int tamPilha;
    private T[] pilha;
    private int posAtual;
    private final String info;

    Pilha(T[] pilha, final String info){
        this.pilha = pilha;
        this.tamPilha = pilha.length;
        this.info = info;
        for(int i = 0; i < this.pilha.length; i++){
            this.pilha[i] = null;
        }
    }

    void push(T elemento){
        if(this.tamPilha > this.posAtual){
            pilha[posAtual] = elemento;
            posAtual++;
        } else {
            System.out.println("Pilha cheia!");
        }
    }

    void pop(){
        if(this.posAtual > 0){
            pilha[posAtual] = null;
            posAtual--;
        }
    }

    void print(){
        System.out.println(info);
        for(int i = posAtual - 1; i >= 0; i--){
            System.out.println("value[" + i + "] = " + pilha[i].toString());
        }
    }
}
