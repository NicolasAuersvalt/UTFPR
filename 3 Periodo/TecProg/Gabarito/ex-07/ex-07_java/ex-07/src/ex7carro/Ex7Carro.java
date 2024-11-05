/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ex7carro;

/**
 *
 * @author Robson
 */
public class Ex7Carro {

    
    public static void main(String[] args) {
        Carro gol = new Carro(12, 45); // 12 quilômetros por litro 
        //de combustível, 
                                        //capacidade do tanque é 45 litros
        gol.abastecer(20); // abastece com 20 litros de combustível.
        Carro uno = new Carro(14,40);
        uno.abastecer(25);
        uno.andar(150); // anda 150 quilômetros.
        double sobra = uno.getCombustivel(); // Exibe o combustível que resta no tanque.
        System.out.println("Litros restantes no Uno: " + sobra);
        gol.andar(80);
        sobra = gol.getCombustivel();
        System.out.println("Litros restantes no Gol: " + sobra);

    }
    
}
