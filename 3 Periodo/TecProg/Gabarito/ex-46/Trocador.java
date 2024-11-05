public class Trocador <T extends ClasseQualquer> {
    private T obj1;
    private T obj2;

    Trocador(T obj1, T obj2){
        this.obj1 = obj2;
        this.obj2 = obj1;
    }

    public T getPrimeiro(){
        return obj1;
    }

    public T getSegundo(){
        return obj2;
    }
}
