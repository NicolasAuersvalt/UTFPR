### 34 - Fazer uma classe *Pessoa*:
* Atributos privados:
  * Nome completo
  * Gênero (masculino ou feminino)
  * Dia, mês e ano de nascimento
* Métodos públicos
  * *Pessoa(nome, gênero, dia, mês, ano)*   
    Por default, gênero=‘m’, dia=1, mês=1, ano=1970
  * *obter_descricao()* retorna  
    *“\<nome\>, [homem|mulher], nasceu em dd/mm/aa”*
* Fazer um setter para dia, mês e ano que faça consistência dos dias em função dos meses
* Fazer um setter para gênero que só aceita ‘m’ ou ‘f’, caso contrário não efetua o set.


Fazer duas especializações da classe *Pessoa*:

* *Aluno*
  * Atributos: curso e universidade
  * Ano de ingresso
  * Sobrescrever o método *obter_descricao()*:    
    *“\<nome\>, [homem|mulher], nasceu em dd/mm/aa, cursa <curso>
    desde \<ano de ingresso\>”*
* *Professor*
  * Universidade
  * Ano de contratação
  * Sobrescrever o método *obter_descricao()*:  
    *“\<nome\>, [homem|mulher], nasceu em dd/mm/aa, professor da
    \<universidade\> desde \<ano de ingresso\>”.*

No programa principal:
* Instanciar uma mulher com data de nascimento.
* Instanciar um homem com valores padrão.
* Imprimir as descrições na tela.