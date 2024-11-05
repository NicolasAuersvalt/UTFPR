### 1 - Construir a classe Horario com os seguintes membros (atributos + métodos):
**Atributos: *hora, min***  
**Métodos:**
* *getHora():*  
    não recebe valor  
    retorna o atributo hora  
* *getMin():*  
    não recebe valor
    retorna o atributo min  
* *setHora():*  
    recebe o novo valor da hora  
    retorna true se a hora for válida, false c. c.  
* *setMin():*  
    recebe o novo valor do minuto  
    retorna true se o min for válido, false c. c.  
* *calcularIntervalo():*  
    recebe um horário h (objeto da classe Horario) como parâmetro  
    calcula o intervalo de tempo deste Horario até o *Horario h*  
    retorna o valor do intervalo em minutos (int)  

**Construir a classe principal para testar a classe *Horario*. Esta classe:**
* pede ao usuário dois horários, de entrada e de saída
* cria dois objetos da classe *Horario*
* calcula o intervalo de tempo entre eles
* calcula quanto custou:  
    se intervalo menor do que 3 h -> R$ 4,50  
    se intervalo entre 3 h e 12 h -> R$ 0,75 a cada 15 min excedente  
    se intervalo maior do que 12 h -> R$ 33,00