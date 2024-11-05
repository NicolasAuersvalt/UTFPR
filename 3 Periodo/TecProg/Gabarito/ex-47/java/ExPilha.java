import java.util.Random;

public class ExPilha {
    public static void main(String[] args){

        //define tamanho das pilhas
        final int tamPilha = 10;

        //cria arrays
        Integer[] integer = new Integer[tamPilha];
        Character[] character = new Character[tamPilha];

        //cria pilhas
        Pilha<Integer> pilhaInteiro = new Pilha<Integer>(integer, "Pilha de inteiros");
        Pilha<Character> pilhaCaracter = new Pilha<Character>(character, "Pilha de caracteres");

        Random random = new Random();

        //adicionando elementos na pilha
        pilhaInteiro.push(random.nextInt(100));
        pilhaInteiro.push(random.nextInt(100));
        pilhaInteiro.push(random.nextInt(100));

        pilhaCaracter.push((char) (random.nextInt(26) + 'a'));
        pilhaCaracter.push((char) (random.nextInt(26) + 'a'));
        pilhaCaracter.push((char) (random.nextInt(26) + 'a'));
        pilhaCaracter.push((char) (random.nextInt(26) + 'a'));

        //printa elementos
        pilhaInteiro.print();
        pilhaCaracter.print();

        //desimpilhando elementos
        pilhaInteiro.pop();
        pilhaCaracter.pop();
        pilhaCaracter.pop();

        //printa elementos
        pilhaInteiro.print();
        pilhaCaracter.print();

    }
}
