## ~ ARBORETUM (樹木園) ~
<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/main/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/ArboretumFrontal.jpg">

Como projeto final da disciplina de Introdução às práticas de laboratório em eletricidade e eletrônica (ELEX10) foi realizado uma miniatura de um "_Arboretum_" ou arboreto, um local onde árvores, arbustos e plantas herbáceas são cultivadas para fins científicos e educacionais.

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/main/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/ArboretumLado.jpg">

Nesse trabalho foi necessário a utilização de uma impressora 3D oferecida pelo Departamento Acadêmico de Eletrônica (DAELN) da Universidade Tecnológica Federal do Paraná (UTFPR) para a impressão do cubo, onde a planta será contida.

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Ligado1.jpeg" width="500">

O projeto consiste em um carrinho equipado com dois motores amarelos DC 3/6v, um módulo ESP8266, um adaptador e um componente Shield L293D. A comunicação do carrinho é realizada no aplicativo mobile Blynk, o qual possui um joystick e pinos virtuais que tornam o manejo do dispositivo mais dinâmico e divertido. Desse modo, quando a placa ESP8266 estiver conectada a uma rede Wi-Fi predefinida, podemos transmitir os dados do joystick para o Arduino - por meio da recepção (RX) e transmissão (TX) de dados pelo ESP8266. Assim, ao receber esses dados, o Arduino os interpretará e seguidamente executará a movimentação dos motores obedecendo os movimentos do joystick.

Exemplo de funcionamento:

[Tank](https://youtu.be/343yUzrjcDY) -
[Com Problemas](https://youtu.be/MywrVtYvrxg) -
[Funcionando](https://www.youtube.com/watch?v=djULl-QYb-8) -
[Ligando](https://youtube.com/shorts/QOh1b2ECXVc)<br>

Inspiração do projeto, feito no TinkerCad:

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Arboretum.PNG" alt="Arboretum">

## MATERIAIS

Neste projeto foram utilizados os seguintes materiais:

- ESP8266 e Adaptador
- Motor Shield L293D
- Bateria 9V
- Arduino Uno R3 Blackboard
- Sensor de Temperatura e de Umidade (DHT11) (opcional)

Esta foi uma inspiração e serviu como base para o desenvolvimento:

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Projeto.PNG" alt="Arboretum">

## BLYNK

No aplicativo “Blynk”, é essencial criar um “template” com pinos virtuais, estes empregando o V0 para a movimentação no eixo X e o V1 para a movimentação no eixo Y.

Para obter uma comunicação eficiente com o Arduino, é fundamental definir tokens através do #define, incluindo: nome do dispositivo, o nome do “template”, o SSID e a senha da rede Wi-Fi à qual deseja-se conectar.

Ao mover o joystick para cima, receberemos valores crescentes até 255 pelo parâmetro 1. De maneira análoga, ao movê-lo para baixo, receberemos valores decrescentes, tendendo a 0 pelo mesmo parâmetro. Além disso, destaca-se que a taxa de transmissão entre dados é de 9600 Hz.

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Diagrama.PNG">

## ESP8266

O ESP8266 é um módulo de comunicação sem fio que integra um microcontrolador com suporte Wi-Fi. Frequentemente é utilizado em projetos de IoT (“Internet of Things”) permitindo a comunicação e troca de dados sem fio entre dispositivos.

Contudo, no projeto foi realizado a comunicação do ESP8266 pela porta analógica, apropriando-se da ligação RX/TX. Inicialmente, a placa se conecta à rede Wi-Fi. Estabelecendo-se essa conexão, o ESP8266 procura se vincular com o “Blynk”.

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Trás.jpeg" width="500">

Nesse contexto, é crucial fornecer uma alimentação separada para os motores, uma vez que a interferência na alimentação pode resultar na captação e recepção de sinais (5V). Deste modo, garante-se um funcionamento mais estável, além de evitar possíveis interferências que poderiam comprometer o desempenho do sistema.

Ao isolar a alimentação dos motores, conseguimos minimizar os efeitos negativos da interferência, contribuindo para a eficiência e estabilidade do projeto.

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Led.jpeg" width="500">

## SHIELD L293D

O Shield L293D é um componente que fornece controle de motores para projetos que têm como base fundamental o Arduino. Comumente é aplicado para o manuseio da direção e velocidade de motores de corrente contínua (DC).

<img src="https://github.com/NicolasAuersvalt/UTFPR/blob/2eb441e0e0f74838bcb88f7f56b793e0add985bb/1%20Periodo/Lab_Eletr%C3%B4nica/Arboretum/Images/Cima.jpeg" width="500">
