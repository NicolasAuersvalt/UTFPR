### 4 - Fazer um programa com as seguintes características:
* classe C1 com acesso público, no pacote p1, com o atributo a1 e os métodos getA1() e setA1();  
* classe C2 com acesso público, também no pacote p1, com o atributo a2 e os métodos getA2() e setA2();  
* na classe C2, incluir o método acessar() que cria objeto da classe C1 e chama os getters e setters;  
* classe C3, com acesso público, no pacote p2, com o método executar() que cria objetos das classes C1, C2 e C4 e chama os getters e setters;  
* classe C4, com acesso default, no pacote p2, com o atributo a4 e getter e setter;  
* classe de entrada ExPacotes, com método main() que cria objetos de C1 e C3 e chama os getters e setters e o método executar().  

Pergunta: caso a classe C1 tenha acesso padrão (ou seja, não público), que efeitos isso causa na compilação ou execução do programa?