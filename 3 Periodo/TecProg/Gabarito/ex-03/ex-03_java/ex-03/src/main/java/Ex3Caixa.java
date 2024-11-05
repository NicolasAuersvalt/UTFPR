
//import -> indica ao compilador de onde virá
//(qual biblioteca) a classe em questão
import java.util.Scanner;


public class Ex3Caixa {
    public static void main (String [] args)
    {
        boolean t1, t2, t3;
        //1. criar objetos da classe Caixa
        //alocação dinâmica -> única forma de 
        //se alocar em Java
        Caixa c1, c2;
        c1 = new Caixa();
        c2 = new Caixa();
        
        //2. receber entradas do usuário
        //Primeiro passo: criar um objeto
        //da classe Scanner
        Scanner s;
        s = new Scanner(System.in);
        
        do
        {
            //segundo passo: chamar um método 
            //apropriado de Scanner para receber
            //o valor do usuário
            System.out.println("Digite o valor da largura da caixa c1:");
            double l = s.nextDouble();

            System.out.println("Digite o valor da altura da caixa c1:");
            double a = s.nextDouble();

            System.out.println("Digite o valor da profundidade da caixa c1:");
            double p = s.nextDouble();

            //armazenar os valores nos atributos do objeto 
            t1 = c1.setAltura(a);
            t2 = c1.setLargura(l);
            t3 = c1.setProfundidade(p);



            if (!t1  || 
                   !t2  || 
                   !t3 )
            {
                System.out.println("Algum dos valores é inválido");
                //Caso eu queira sair do programa,
                //posso usar System.exit(0);
                //System.exit(0);
                
                
            }
            
        } while (!t1  ||  !t2 || !t3);
        
        //3. calcularAreaExt
        System.out.println("Area externa de c1: " + 
               c1.calcularAreaExt());
          
       System.out.println("Volume de c1: " + 
               c1.calcularVolume());
    }     
}
