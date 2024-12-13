/*
Developed by 

Nícolas Auersvalt Marques

Federal University of Technology - Paraná

Late 2024


Plotter CNC usando Arduino Uno R3
Utiliza-se três motores de passo 28BYJ-48 com controlador ULN2003A
Lê-se uma matriz de dado (0 e 1) no python e envia tais coordenadas
para o arduino movimentar-se a tal posição.
Em função da combinação de teclas do KeyPad, envia os dados para acessar
uma matriz específica no python
*/


#include <Stepper.h>

// Definição dos pinos do teclado 3x3
#define ROW1 1
#define ROW2 A0
#define ROW3 A1
#define ROW4 A2
#define COL1 A3
#define COL2 A4
#define COL3 A5

bool motorActive = false;

// Definir o número de passos por volta do motor 28BYJ-48
const int stepsPerRevolution = 2048;  // Número de passos por revolução

int posAtual_x= 0;
int posAtual_y = 0;

// Teclas -> COLOCAR VETOR
char primeira = 'L';
char segunda = 'L';

// Horizontal e Vertical
const int inicio = 0;
const int limite = 300;

// Eixo z
const int cima = 0;
const int baixo = -20; // NEGATIVO

// TEMPOS
const int tmp1 = 10; // INTERVALO ENTRE OS MOTORES
const int tmp2 = 50; // INTERVALO INICIALIZAÇÃO
const int tmp3 = 

Stepper motor_X(stepsPerRevolution, 0, 1, 2, 3);  // Pinos conectados ao motor
Stepper motor_Y(stepsPerRevolution, 4, 5, 6, 7);  // Pinos conectados ao motor
Stepper motor_Z(stepsPerRevolution, 8, 9, 10, 11);  // Pinos conectados ao motor

void desenhar(int tecla){

  // while o python enviar valores para x e y
  Serial.print(primeiro);
  Serial.print(segundo);
  Serial.print("Pronto");

  // Enquanto houver dados
   while(Serial.available() >= 8){
      int x = Serial.parseInt();
      int y = Serial.parseInt();

      if()
      x -= posAtual_x;
      y -= posAtual_y;

      if((posAtual_x + x <= limite) && (posAtual_y + y <= limite)){
        posAtual_x += x;
        posAtual_y += y;

        motor_X.step(x);  // Gira uma revolução completa
        motor_y.step(y);
        delay();
        printar(); // PARA Z
      }
   }
   Serial.print("OK");
}

void printar(){ // DESCE A CANETA PRONTO

  motor_Z.step(baixo);  // Gira uma revolução completa
  delay(tmp1);
  motor_Z.step(cima);  // Gira uma revolução completa
  delay(tmp1);
  
}

char teclado(){

   char tecla, bool pressionada = false;

   // Impedir ler várias teclas, apenas uma por vez
   while(!pressionada){
      if (digitalRead(ROW1) == LOW) {
        if (digitalRead(COL1) == LOW) {
          tecla = '1';
        } else if (digitalRead(COL2) == LOW) {
          tecla = '2';
        } else if (digitalRead(COL3) == LOW) {
          tecla = '3';
        }
        pressionada = true;
      }
      else if (digitalRead(ROW2) == LOW) {
        if (digitalRead(COL1) == LOW) {
          tecla = '4';
        } else if (digitalRead(COL2) == LOW) {
          tecla = '5';
        } else if (digitalRead(COL3) == LOW) {
          tecla = '6';
        }
        pressionada = true;
      }
      else if (digitalRead(ROW3) == LOW) {
        if (digitalRead(COL1) == LOW) {
          tecla = '7';
        } else if (digitalRead(COL2) == LOW) {
          tecla = '8';
        } else if (digitalRead(COL3) == LOW) {
          tecla = '9';
        }
        pressionada = true;
      }
      else if (digitalRead(ROW4) == LOW) {
        
        else if (digitalRead(COL2) == LOW) {
          tecla = '0';
        }
        pressionada = true;
      }
      return tecla;
    }

void proximo(){
  
  bool pressionada = false;
  while(!pressionada){
    
    else if (digitalRead(ROW4) == LOW) {
    if (digitalRead(COL1) == LOW) { // * - PROXIMO
      return true;
    }
    else if (digitalRead(COL3) == LOW) { // # - RETROCEDER
      return false;
    }
  }
    
    }
}

void limpar(char& caractere){
   (*caractere) = 'L';
}

void encadeamento(){
  
        while(True){
          
            bool proximo=false;
            
             // Espera a leitura do keypad
            primeira = teclado();
            
            if(primeira == '#'){ // TERMINA A IMPRESSÃO
                return;
              }
              
            if(proximo()){ // USUARIO TECLOU *
              
                while(true){ // CORRIGIR A PARTE DA PESSOA ENTRAR NA PRIMEIRA CARACTERISTISCA, DIGITAR A SEGUNDA MAS QUERER VOLTAR PARA A PRIMEIRA
                  segunda = teclado();
                
                  if(proximo){ // USUARIO TECLOU *
                    desenhar();
                    break;
                  }
                  else(){ // USUARIO TECLOU #
                    limpar(segunda);  // LIMPA A TECLA DIGITADA
                  }
                 }
                 
                 // Limpa as teclas
                limpar(primeira);
                limpar(segunda);
                
            }
            else if()
              limpar(primeira);
             }
          }


void inicializar(){ // PRONTO

  // inicializa em x e y
  motor_X.step(inicio);  // Gira uma revolução completa
  motor_Y.step(inicio);  // Gira uma revolução completa
  motor_Z.step(cima);
  delay(tmp2);
  
  
}

void setup() {

  
  // Configura as linhas e colunas como entradas com pull-up
  pinMode(ROW1, INPUT_PULLUP);
  pinMode(ROW2, INPUT_PULLUP);
  pinMode(ROW3, INPUT_PULLUP);
  pinMode(ROW4, INPUT_PULLUP);
  pinMode(COL1, INPUT_PULLUP);
  pinMode(COL2, INPUT_PULLUP);
  pinMode(COL3, INPUT_PULLUP);

  // Definir a velocidade do motor (RPM)
  stepper.setSpeed(15);  // Velocidade em rotações por minuto

  Serial.begin(9600);
}

void principal(){
  inicializar();
  encadeamento();
}

void loop() {

  principal();

  // CENTRALIZAR NO 0 0
  
  // Gire o motor em uma direção
  stepper.step(stepsPerRevolution);  // Gira uma revolução completa

  delay(1000);  // Pausa de 1 segundo

  // Gire o motor na direção oposta
  stepper.step(-stepsPerRevolution);  // Gira uma revolução completa no sentido contrário

  delay(1000);  // Pausa de 1 segundo
}


