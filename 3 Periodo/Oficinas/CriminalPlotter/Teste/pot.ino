ls
const int pot = A0;
int i;
int pins[] = {8, 9, 10, 11};  // Pinos conectados ao driver do motor
int velocidade = 5;
int centro = 512;  // Valor central do potenciômetro (aproximadamente)

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

void setup() {
  pinMode(pot, INPUT);  // Configura o pino do potenciômetro como entrada

  for (i = 0; i < 4; i++) {
    pinMode(pins[i], OUTPUT);  // Configura os pinos como saída
  }
}

void loop() {
  // Faz a leitura do potenciômetro
  int potValue = analogRead(pot);

  // Determina a direção e a velocidade
  if (potValue > centro + 20) {  // Região direita (horário)
    velocidade = map(potValue, centro + 20, 1023, 1, 10);  // Mapeia para 1 a 10 para ter um delay mínimo

    // Gira o motor no sentido horário
    for (int step = 0; step < 8; step++) {
      for (i = 0; i < 4; i++) {
        digitalWrite(pins[i], halfStepSequence[step][i]);
      }
      delay(velocidade);  // Tempo mínimo para o motor processar o movimento
    }
  } else if (potValue < centro - 20) {  // Região esquerda (anti-horário)
    velocidade = map(potValue, centro - 20, 0, 1, 10);  // Mapeia para 1 a 10 para ter um delay mínimo

    // Gira o motor no sentido anti-horário
    for (int step = 7; step >= 0; step--) {
      for (i = 0; i < 4; i++) {
        digitalWrite(pins[i], halfStepSequence[step][i]);
      }
      delay(velocidade);  // Tempo mínimo para o motor processar o movimento
    }
  } else {
  }
}
