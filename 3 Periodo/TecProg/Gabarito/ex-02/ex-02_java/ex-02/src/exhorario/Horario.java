
package exhorario;


public class Horario {
    //vamos utilizar um tipo adequado
    //para hora de 0 a 23 -> byte -> 8 bits, 
    //-128 a 127
    //para min de 0 a 59 -> idem
    private byte hora;
    private byte min;

    //getters e setters
    public void setHora(byte hora) {
        //this.hora -> indica o atributo hora
        //deste objeto, para diferenciar do 
        //parâmetro hora no cabeçalho do método
        this.hora = hora;
    }

    public void setMin(byte min) {
        this.min = min;
    }
    
    
    public byte getHora() { return hora; }
    public byte getMin() { return min; }
    
    public int calcularIntervalo(Horario h)
    {
        //calcula o intervalo entre os horarios "deste"
        //objeto e o horário do objeto h
        int intervalo = (h.getHora()*60 + h.getMin()) - 
                (hora*60 + min);
        //se for negativo quer dizer que mudou de dia
        if (intervalo < 0)
        {
            //soma o tempo de 1 dia
            intervalo = intervalo + 1440;
        }
        return intervalo;
        
    }
    
}
