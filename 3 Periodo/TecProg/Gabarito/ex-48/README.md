### 48 - Implementar uma classe de gabarito / genérico para efetuar a ordenação por meio do método *Bubble-sort*. Esta classe deve:
* definir um atributo genérico que corresponde ao vetor de elementos, de tipo genérico, a serem ordenados
* definir um método *classifica()* que efetua a ordenação. Para comparar elementos adjacentes e decidir sobre a sua ordem relativa, este método deve chamar o método *maiorQue()* da classe dos elementos sendo ordenados.

O programa deve rodar com o seguinte código (caso seja feito em Java):

```java
public class ExBubble {
    public static void main(String[] args) {
        AlgoOrdenavel[] aov = new AlgoOrdenavel[3];
        aov[0] = new AlgoOrdenavel(5);
        aov[1] = new AlgoOrdenavel(3);
        aov[2] = new AlgoOrdenavel(-2);
        Bubble<AlgoOrdenavel> b = new Bubble<AlgoOrdenavel>(aov);
        b.classifica();
        for (int i = 0; i < aov.length; i++) {
            System.out.println("Valor = " + aov[i].getValor());
        }
    }
}

class AlgoOrdenavel {
    private int valor;

    public AlgoOrdenavel(int v) {
        valor = v;
    }

    public boolean maiorQue(AlgoOrdenavel ao) {
        if (valor > ao.valor)
            return true;
        return false;
    }

    public int getValor() {
        return valor;
    }
}
```