import java.util.Random;

public class ExBubble {
    public static void main(String[] args){
        ClasseQualquer[] classes = new ClasseQualquer[10];
        Random random = new Random();

        for(int i = 0; i < classes.length; i++){
            //intervalo (-100:100);
            classes[i] = new ClasseQualquer(random.nextInt(200) - 100);    
        }

        Bubble<ClasseQualquer> bubbleSort = new Bubble<ClasseQualquer>(classes);

        bubbleSort.classifica();

        for(int i = 0; i < classes.length; i++){
            System.out.println("Valor = " + classes[i].getValor());
        }
    }
}
