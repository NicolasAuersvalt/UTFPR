ls
// Definição dos pinos do teclado 3x3
#define ROW1 12
#define ROW2 A0
#define ROW3 A1
#define ROW4 A2
#define COL1 A3
#define COL2 A4
#define COL3 A5

// Pinos dos motores  8, 9, 10, 11
int pins1[] = {0, 1, 2, 3};  // Pinos conectados ao driver do motor1
int pins2[] = {4, 5, 6, 7};  // Pinos conectados ao driver do motor2
int pins3[] = {8, 9, 10, 11}; // Pinos conectados ao driver do motor3

// Sequência de meio passo para o motor 28BYJ-48
const int halfStepSequence[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

int velocidade = 1; // Velocidade máxima (mínimo delay)
int movimentoAnterior = 1; // Variável para alternar entre horários e anti-horários

// Função para configurar os pinos
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  Serial.println("Aguardando entrada no teclado...");

  // Configura os pinos dos motores como saída
  for (int i = 0; i < 4; i++) {
    pinMode(pins1[i], OUTPUT);
    pinMode(pins2[i], OUTPUT);
    pinMode(pins3[i], OUTPUT);
  }

  // Configura as linhas e colunas como entradas com pull-up
  pinMode(ROW1, INPUT_PULLUP);
  pinMode(ROW2, INPUT_PULLUP);
  pinMode(ROW3, INPUT_PULLUP);
  pinMode(ROW4, INPUT_PULLUP);
  pinMode(COL1, INPUT_PULLUP);
  pinMode(COL2, INPUT_PULLUP);
  pinMode(COL3, INPUT_PULLUP);
}

void loop() {
  // Verifica se alguma tecla foi pressionada
  if (digitalRead(ROW1) == LOW) {
    if (digitalRead(COL1) == LOW) {
      teclaPressionada('1');
    } else if (digitalRead(COL2) == LOW) {
      teclaPressionada('2');
    } else if (digitalRead(COL3) == LOW) {
      teclaPressionada('3');
    }
  }
  else if (digitalRead(ROW2) == LOW) {
    if (digitalRead(COL1) == LOW) {
      teclaPressionada('4');
    } else if (digitalRead(COL2) == LOW) {
      teclaPressionada('5');
    } else if (digitalRead(COL3) == LOW) {
      teclaPressionada('6');
    }
  }
  else if (digitalRead(ROW3) == LOW) {
    if (digitalRead(COL1) == LOW) {
      teclaPressionada('7');
    } else if (digitalRead(COL2) == LOW) {
      teclaPressionada('8');
    } else if (digitalRead(COL3) == LOW) {
      teclaPressionada('9');
    }
  }
  else if (digitalRead(ROW4) == LOW) {
    if (digitalRead(COL1) == LOW) {
      teclaPressionada('*');
    } else if (digitalRead(COL2) == LOW) {
      teclaPressionada('0');
    } else if (digitalRead(COL3) == LOW) {
      teclaPressionada('#');
    }
  }
}

// Função chamada quando uma tecla é pressionada
void teclaPressionada(char tecla) {
  Serial.print("Tecla pressionada: ");
  Serial.println(tecla);

  // Se for uma das teclas '1', '2' ou '3', faz a rotação normal
  if (tecla == '1') {
    Serial.println("Girando os motores no sentido horário por 3 segundos.");
    rotateMotors(1); // Sentido horário
  } else if (tecla == '2') {
    Serial.println("Girando os motores no sentido anti-horário por 3 segundos.");
    rotateMotors(2); // Sentido anti-horário
  } else if (tecla == '3') {
    Serial.println("Girando os motores no sentido horário por 3 segundos.");
    rotateMotors(1); // Sentido horário
  } else {
    // Se for qualquer outra tecla, alterna o movimento
    if (movimentoAnterior == 1) {
      Serial.println("Girando os motores no sentido anti-horário por 3 segundos.");
      rotateMotors(2); // Sentido anti-horário
      movimentoAnterior = 2; // Atualiza para o próximo movimento
    } else {
      Serial.println("Girando os motores no sentido horário por 3 segundos.");
      rotateMotors(1); // Sentido horário
      movimentoAnterior = 1; // Atualiza para o próximo movimento
    }
  }

  // Após a execução, aguarda um tempo
  delay(500); // Evita múltiplas leituras da mesma tecla
}

// Função para girar os motores
void rotateMotors(int direction) {
  unsigned long startTime = millis(); // Marca o tempo inicial
  unsigned long duration = 3000;      // Duração em milissegundos (3 segundos)

  while (millis() - startTime < duration) {
    if (direction == 1) {
      // Gira no sentido horário
      for (int step = 0; step < 8; step++) {
        setMotorStep(step, pins1);
        setMotorStep(step, pins2);
        setMotorStep(step, pins3);
        delay(velocidade);
      }
    } else if (direction == 2) {
      // Gira no sentido anti-horário
      for (int step = 7; step >= 0; step--) {
        setMotorStep(step, pins1);
        setMotorStep(step, pins2);
        setMotorStep(step, pins3);
        delay(velocidade);
      }
    }
  }

  // Para os motores após o tempo definido
  stopMotors(pins1);
  stopMotors(pins2);
  stopMotors(pins3);
  Serial.println("Motores parados.");
}

// Define os passos dos motores
void setMotorStep(int step, int pins[]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], halfStepSequence[step][i]);
  }
}

// Para os motores
void stopMotors(int pins[]) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pins[i], LOW);
  }
}
