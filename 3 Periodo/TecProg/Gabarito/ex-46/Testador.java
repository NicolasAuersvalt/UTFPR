public class Testador {

    public static void main(String[] args) {

        //Cria meu objetos
        ClasseQualquer obj1 = new ClasseQualquer(5);
        ClasseQualquer obj2 = new ClasseQualquer(3);

        System.out.println("Primeiro = " + obj1.getValor());
        System.out.println("Segundo = " + obj2.getValor());

        //Troca os objetos na construtora
        Trocador<ClasseQualquer> trocador = new Trocador<>(obj1, obj2);

        //Recebe os objetos trocados
        obj1 = trocador.getPrimeiro();
        obj2 = trocador.getSegundo();

        //Resultado
        System.out.println("Primeiro = " + obj1.getValor());
        System.out.println("Segundo = " + obj2.getValor());


    } 

}