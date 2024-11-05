/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exhorario;

import java.util.Scanner;

/**
 *
 * @author Robson
 */
public class ExHorario {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        byte h1, m1, h2, m2;
        Scanner s = new Scanner(System.in);
        System.out.println("Digite hora de entrada: ");
        h1 = s.nextByte();
        System.out.println("Digite minuto de entrada: ");
        m1 = s.nextByte();
        
        System.out.println("Digite hora de saida: ");
        h2 = s.nextByte();
        System.out.println("Digite minuto de saida: ");
        m2 = s.nextByte();
        
        //criar os objetos
        Horario entrada = new Horario();
        entrada.setHora(h1);
        entrada.setMin(m1);
        
        Horario saida = new Horario();
        saida.setHora(h2);
        saida.setMin(m2);
        
        //calcular intervalo
        //Conforme implementação:
        // - entrada -> objeto no qual estamos executando
        // - saida -> objeto do horário h
        //Portanto interv recebe intervalo entre
        //entrada e saida.
        int interv = entrada.calcularIntervalo(saida);
        
        //se intervalo menor do que 3 h -> R$ 4,50
	//se intervalo entre 3 h e 12 h -> R$ 0,75 a cada 15 min excedente
	//se intervalo maior do que 12 h ->  R$ 33,00 
        double preco;
        if (interv < 3*60)
        {
            preco = 4.5;
        }
        else if (interv < 12*60)
        {
            //calcular quantos intervalos de 15 min
            //existem no horario excedente
            int aux = (interv - 3*60)/15;
            //se não deu multiplo de 15 min, deve
            //cobrar um intervalo a mais
            if (((interv - 3*60)%15) != 0)
            {
                aux++;
            }            
            preco = 4.5 + aux*0.75;
        }
        else
        {
            preco = 33;
        }
        System.out.println("Preço = " + preco);

        
    }
    
}
