### 8 - Implemente uma classe chamada Carro com as seguintes propriedades:  

* Um veículo tem um certo consumo de combustível (medidos em km/litro), uma certa capacidade máxima de combustível e uma certa quantidade de combustível no tanque.
* O consumo e a capacidade máxima são passados como parâmetro para o construtor e o nível de combustível inicial é 0.
* Forneça um método *andar( )* que simule o ato de dirigir o veículo por uma certa distância, reduzindo o nível de combustível no tanque de gasolina. 
* Forneça um método *getCombustivel( )*, que retorna o nível atual de combustível.
* Forneça um método *abastecer( )*, para abastecer o tanque.
* Escreva um pequeno programa em C++ que teste sua classe. *Obs.: Em necessitando, alguns métodos podem ter parâmetros.*
* Eis um exemplo de uso (só que aqui em Java): 

``` java
Carro gol = new Carro(12, 45);  // 12 quilômetros por litro
                                //de combustível,
                                //capacidade do tanque é 45 litros
gol.abastecer(20);  // abastece com 20 litros de combustível.
Carro uno = new Carro(14,40);
uno.abastecer(25);
uno.andar(150); // anda 150 quilômetros.
int sobra = uno.getCombustivel() // Exibe o combustível que resta no tanque.
System.out.println("Litros restantes no Uno: " + sobra);
gol.andar(80);
sobra = gol.getCombustivel();
System.out.println("Litros restantes no Gol: " + sobra);

```