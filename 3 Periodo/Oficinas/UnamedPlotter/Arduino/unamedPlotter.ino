/*
Federal University of Technology - Paraná (UTFPR)
by Nícolas Auersvalt, 2024.
*/

// Definições de pinos para os motores
#define MOTOR_X_PWM 3      // Pino PWM para velocidade do motor X
#define MOTOR_X_INPUT1 4   // Pino para controle de direção (IN1 do L293D) do motor X
#define MOTOR_X_INPUT2 5   // Pino para controle de direção (IN2 do L293D) do motor X

#define MOTOR_Y_PWM 8      // Pino PWM para velocidade do motor Y
#define MOTOR_Y_INPUT1 7   // Pino para controle de direção (IN1 do L293D) do motor Y
#define MOTOR_Y_INPUT2 6   // Pino para controle de direção (IN2 do L293D) do motor Y

#define MOTOR_INC_PWM 11    // Pino PWM para velocidade do motor de inclinação
#define MOTOR_INC_INPUT1 9  // Pino para controle de direção (IN1 do L293D) do motor de inclinação
#define MOTOR_INC_INPUT2 10 // Pino para controle de direção (IN2 do L293D) do motor de inclinação

#define POT1 A2 // Pino analógico do primeiro potenciômetro (motor X)
#define POT2 A1 // Pino analógico do segundo potenciômetro (motor Y)
#define POT3 A0 // Pino analógico do terceiro potenciômetro (motor de inclinação)


// Range Potenciometro (0, 1023)
#define limPot 512 // Centralizar o potenciômetro

void setup() {
  // Configurar pinos dos motores
  pinMode(MOTOR_X_PWM, OUTPUT);
  pinMode(MOTOR_X_INPUT1, OUTPUT);
  pinMode(MOTOR_X_INPUT2, OUTPUT);

  pinMode(MOTOR_Y_PWM, OUTPUT);
  pinMode(MOTOR_Y_INPUT1, OUTPUT);
  pinMode(MOTOR_Y_INPUT2, OUTPUT);

  pinMode(MOTOR_INC_PWM, OUTPUT);
  pinMode(MOTOR_INC_INPUT1, OUTPUT);
  pinMode(MOTOR_INC_INPUT2, OUTPUT);

  // Configurar pinos dos potenciômetros
  pinMode(POT1, INPUT);
  pinMode(POT2, INPUT);
  pinMode(POT3, INPUT);

  // Iniciar comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Ler os valores dos potenciômetros
  int potValueX = analogRead(POT1);
  int potValueY = analogRead(POT2);
  int potValueInc = analogRead(POT3);
  int motorSpeedX, motorSpeedY, motorSpeedInc;

  // Controlar motor X
  if (potValueX < limPot) {
    motorSpeedX = map(potValueX, 0, 511, 255, 0); // Velocidade máxima até zero
    digitalWrite(MOTOR_X_INPUT1, HIGH);
    digitalWrite(MOTOR_X_INPUT2, LOW);
  } else {
    motorSpeedX = map(potValueX, 512, 1023, 0, 255); // Zero até velocidade máxima
    digitalWrite(MOTOR_X_INPUT1, LOW);
    digitalWrite(MOTOR_X_INPUT2, HIGH);
  }
  analogWrite(MOTOR_X_PWM, motorSpeedX);

  // Controlar motor Y
  if (potValueY < limPot) {
    motorSpeedY = map(potValueY, 0, 511, 255, 0); // Velocidade máxima até zero
    digitalWrite(MOTOR_Y_INPUT1, HIGH);
    digitalWrite(MOTOR_Y_INPUT2, LOW);
  } else {
    motorSpeedY = map(potValueY, 512, 1023, 0, 255); // Zero até velocidade máxima
    digitalWrite(MOTOR_Y_INPUT1, LOW);
    digitalWrite(MOTOR_Y_INPUT2, HIGH);
  }
  analogWrite(MOTOR_Y_PWM, motorSpeedY);

  // Controlar motor de inclinação
  if (potValueInc < limPot) {
    motorSpeedInc = map(potValueInc, 0, 511, 255, 0); // Velocidade máxima até zero
    digitalWrite(MOTOR_INC_INPUT1, HIGH);
    digitalWrite(MOTOR_INC_INPUT2, LOW);
  } else {
    motorSpeedInc = map(potValueInc, 512, 1023, 0, 255); // Zero até velocidade máxima
    digitalWrite(MOTOR_INC_INPUT1, LOW);
    digitalWrite(MOTOR_INC_INPUT2, HIGH);
  }
  analogWrite(MOTOR_INC_PWM, motorSpeedInc);

  // Monitorar os valores dos potenciômetros e as velocidades dos motores
  Serial.print("Pot1: ");
  Serial.print(potValueX);
  Serial.print(" | Velocidade Motor X: ");
  Serial.println(motorSpeedX);

  Serial.print("Pot2: ");
  Serial.print(potValueY);
  Serial.print(" | Velocidade Motor Y: ");
  Serial.println(motorSpeedY);

  Serial.print("Pot3: ");
  Serial.print(potValueInc);
  Serial.print(" | Velocidade Motor Inclinação: ");
  Serial.println(motorSpeedInc);

  delay(50); // Resposta mais rápida
}
