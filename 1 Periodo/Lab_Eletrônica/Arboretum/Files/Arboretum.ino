/*
  ==============================================
  Universidade Tecnológica Federal do Paraná 
  
  Disciplina de Introdução às Práticas de Laboratório em Eletricidade e Eletrônica
  (ELEX10) - 1º Semestre, 2023



  樹木園 


  Desenvolvido por:

  Nícolas Auersvalt Marques
  Isabela Bella Bortoleto
  Vittor Henrique da Silva Masotti​

  Versão atual (1.0)
  ==============================================
*/

// Blynk
#define BLYNK_TEMPLATE_ID "TMPLrG9kgao2"
#define BLYNK_TEMPLATE_NAME "ESP8266"
#define BLYNK_AUTH_TOKEN "NpE9rh2CVCOxYIGL-78m3zfKID46Rtvh"
#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#include <AFMotor.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "removido"; 
char pass[] = "removido";

#define EspSerial Serial1

// Pinos ESP
SoftwareSerial EspSerial(A0, A1); // RX, TX

// Taxa de transmissão do ESP8266:
#define ESP8266_BAUD 9600 //19200

ESP8266 wifi(&EspSerial);

// Define motores nas saídas M[3] e M[4]
// M[3] Esquerda M[4] Direita

AF_DCMotor motor1(3); // Esquerda
AF_DCMotor motor2(4); // Direita

const int max_range = 100; /* Valor máximo da velocidade */

int mov(int x, int y)
{
  
  // Tempo de delay
   int time = 10;

  int starting_position = 128;

  // Limite de deslocamento mínimo do Joystick
  int lim_min = 90; 
  int lim_max = 140; 

  // Velocidades
  int velocidade=0;
  int velMin = 1;
  int velMax = 150;

  /*
    Posição dos motores:
      motor1 - Esquerdo
      motor2 - Direito
  */

  // Acelerado

   // Curva Frontal à direita

  if ((x > lim_max) && (y > lim_max))
  {

    velocidade = map(y, 128, 255, velMin, velMax);

    motor1.setSpeed(velocidade);
    motor1.run(FORWARD); // Esquerda
    Serial.println();

    motor2.run(RELEASE);// Direita
    motor2.setSpeed(velocidade);
    delay(time);
  }

  // Curva Frontal à Esquerda

  else if ((x < lim_min) && (y > lim_max)) 
  {

    velocidade = map(y, 128, 255, velMin, velMax);

    motor1.setSpeed(velocidade);
    motor1.run(RELEASE);

    motor2.setSpeed(velocidade);
    motor2.run(BACKWARD);
    delay(time);
  }

  // Movimento Retrógrado

  // Ré para a Direita

  else if ((x > lim_max) && (y < lim_min)) 
  {

    velocidade = map(y, 128, 0, velMin, velMax);

    motor1.setSpeed(velocidade);
    motor1.run(BACKWARD);

    motor2.setSpeed(velocidade);
    motor2.run(RELEASE);
    delay(time);
  }

  // Ré para a esquerda

  else if ((x < lim_min) && (y < lim_min)) 
  {

    velocidade = map(y, 128, 0, velMin, velMax);

    motor1.run(RELEASE);
    motor1.setSpeed(velocidade);

    motor2.setSpeed(velocidade);
    motor2.run(FORWARD);
    delay(time);
  }

  // Movimento frontal

  else if ((lim_min < x < lim_max) && (y > lim_max)) 
  {

    velocidade = map(y, 128, 255, velMin, velMax);

    motor1.setSpeed(velocidade);
    motor1.run(FORWARD);

    motor2.setSpeed(velocidade);
    motor2.run(BACKWARD);
    delay(time);
  }

  // Ré

  else if ((lim_min < x < lim_max) && (y < lim_min)) 
  {

    velocidade = map(y, 128, 0, velMin, velMax);

    motor1.setSpeed(velocidade);
    motor1.run(BACKWARD);

    motor2.setSpeed(velocidade);
    motor2.run(FORWARD);
    delay(time);
  }

  // Parado

  else
  {
    
    motor1.setSpeed(y);
    motor1.run(RELEASE);

    motor2.setSpeed(y);
    motor2.run(RELEASE);
    delay(time);
  }
}

void setup()
{
  // Define a taxa de transmissão do ESP8266 (9600)
  EspSerial.begin(ESP8266_BAUD);

  // Se conecta ao wifi -> Depois se coneta ao Template
  Blynk.begin(auth, wifi, ssid, pass);
}

void loop()
{
  // Inicia a execução do blynk
  Blynk.run();
}

// Pino do Joystick Virtual  = V0

BLYNK_WRITE(V0)
{
  int x = param[0].asInt(); // Eixo X
  int y = param[1].asInt(); // Eixo Y

  // Chama a função de movimento
  mov(x, y);
}
