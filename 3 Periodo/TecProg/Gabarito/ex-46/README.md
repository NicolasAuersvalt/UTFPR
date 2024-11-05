### 46 - Fazer um programa em Java que:
- defina a classe genérica *Trocador\<P>.* Esta classe implementa os seguintes métodos:
  - construtor: recebe dois objetos do tipo P e troca. Armazena um dos objetos no atributo *primeiroObjeto* e o outro objeto no atributo *segundoObjeto*.
  - *getPrimeiro()*: retorna o primeiro objeto
  - *getSegundo()*: retorna o segundo objeto.
O programa deve funcionar com a seguinte classe de entrada:

``` java
public class Testador {
    public static void main(String[] args) {
        ClasseQualquer obj1 = new ClasseQualquer(5);
        ClasseQualquer obj2 = new ClasseQualquer(3);
        Trocador<ClasseQualquer> t = new Trocador<ClasseQualquer>(obj1,
                obj2);
        obj1 = t.getPrimeiro();
        obj2 = t.getSegundo();
        System.out.println("Primeiro = " + obj1.getValor());
        System.out.println("Segundo = " + obj2.getValor());
    }
}

class ClasseQualquer {
    private int valor;

    public ClasseQualquer(int v) {
        valor = v;
    }

    public int getValor() {
        return valor;
    }
}
```