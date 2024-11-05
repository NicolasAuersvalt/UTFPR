public class ClasseQualquer {
    private int valor;

    ClasseQualquer(final int valor){
        this.valor = valor;
    }

    public void algoOrdenavel(final int valor){
        this.valor = valor;
    }

    public boolean maiorQue(ClasseQualquer outraClasse){
        return this.valor > outraClasse.getValor();
    }

    public final int getValor(){
        return this.valor;
    }
}
