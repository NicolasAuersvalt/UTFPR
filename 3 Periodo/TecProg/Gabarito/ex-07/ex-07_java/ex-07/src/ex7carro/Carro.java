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
public class Carro {
    
    private double consumo; //km/litro
    private double capacidade; //litro
    private double qtde;       //litro
    
    //construtora
    public Carro (double cons, double cap)
    {
        consumo = cons;
        capacidade = cap;
        //tanque inicialmente vazio
        qtde = 0;
    }
    public double andar (double dist)
    {
        
        if (qtde >= dist/consumo)
        {
        
            //cuidado! Quanto maior o valor
            //de "consumo", mais econômico
            //é o veículo!
            qtde = qtde - dist/consumo;
            return dist;
        }
        else
        {
            //se não tem combustivel
            //suficiente, anda o que é
            //possível e esvazia o 
            //tanque.
            double aux = qtde*consumo;
            qtde = 0;
            return aux;
        }
    }
    public double getCombustivel() { return qtde; }
    public double abastecer(double q)
    {
        if (q > capacidade - qtde)
        {
            double aux = capacidade - qtde;
            qtde = capacidade;
            return aux;
        }
        else
        {
            qtde += q;
            return q;
        }
    
    
    }
    
    
}
