/*
  ==============================================
  
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
char ssid[] = "nicolas";
char pass[] = "12345678";

#define EspSerial Serial1

// Pinos ESP
SoftwareSerial EspSerial(A0, A1); // RX, TX

// Taxa de transmissão do ESP8266:
#define ESP8266_BAUD 9600 //19200

ESP8266 wifi(&EspSerial);

// Define motores nas saídas M[1] e M[2]
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

const int max_range = 100; /* Valor máximo da velocidade */

// Tempo de delay
int time = 10;

int mov(int time, int x, int y)
{
  int starting_position = 128;
  int lim_nx = 108;
  int lim_x = 148;

  /*
    Posição dos motores:
      motor1 - Esquerdo
      motor4 - Direito
  */

  // Acelerado

  if ((x > lim_x) && (y > starting_position)) // Curva Frontal à direita
  {

    // Inicia o Motor
    motor1.run(BACKWARD);
    motor1.setSpeed(y);

    motor2.setSpeed(y);
    motor2.run(BACKWARD);
    delay(time);
  }

  // Curva Frontal à Esquerda
    
  else if ((x < lim_nx) && (y > starting_position)) 
  {

    motor1.setSpeed(y);
    motor1.run(BACKWARD);

    motor2.setSpeed(y);
    motor2.run(FORWARD);
    delay(time);
  }

  // Movimento Retrógrado

  // Ré para a Direita
    
  else if ((x > lim_x) && (y < starting_position)) 
  {

    motor1.setSpeed(255 - y);
    motor1.run(FORWARD);

    motor2.setSpeed(255 - y);
    motor2.run(BACKWARD);
    delay(time);
  }

  // Ré para a esquerda
    
  else if ((x < lim_nx) && (y < starting_position)) 
  {
    motor1.run(FORWARD);
    motor1.setSpeed(255 - y);

    motor2.setSpeed(255 - y);
    motor2.run(BACKWARD);
    delay(time);
  }

  // Movimento frontal
    
  else if ((lim_nx < x < lim_x) && (y > starting_position)) 
  {
    motor1.setSpeed(y);
    motor1.run(BACKWARD);

    motor2.setSpeed(y);
    motor2.run(FORWARD);
    delay(time);
  }

  // Ré

  else if ((lim_nx < x < lim_x) && (y < starting_position)) 
  {
    motor1.setSpeed(255 - y);
    motor1.run(FORWARD);

    motor2.setSpeed(255 - y);
    motor2.run(BACKWARD);
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
  mov(time, x, y);
}
