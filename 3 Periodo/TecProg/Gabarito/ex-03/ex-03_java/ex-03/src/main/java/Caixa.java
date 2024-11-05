/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Robson
 */
public class Caixa {
    
    //atributos da caixa
    private double largura;
    private double altura;
    private double profundidade;
    
    public boolean setLargura(double l)
    {
        if (l > 0)
        {
            largura = l;
            return true;
        }
        return false;
    }
    
    public boolean setAltura(double a)
    {
        if (a > 0)
        {
            altura = a;
            return true;
        }
        return false;
    }
    public boolean setProfundidade(double p)
    {
        if (p > 0)
        {
            profundidade = p;
            return true;
        }
        return false;
    }
    
    public double calcularAreaExt()
    {
        return 2*(altura*largura + 
                altura*profundidade +
                largura*profundidade);
    }
    
    public double calcularVolume()
    {
        return profundidade*largura*altura;
    }
    
}
