#include <math.h>

const int numSamples = 100;  // Número de amostras por ciclo
const float amplitude = 512; // Amplitude do sinal (0-1023 para portas analógicas)
const float frequency = 1;   // Frequência do sinal (em Hz)
const float pi = 3.14159265358979323846;

void setup() {
  Serial.begin(115200);
}

void loop() {
  for (int i = 0; i < numSamples; i++) {
    float time = (float)i / numSamples;
    int value = (int)(amplitude * (sin(2 * pi * frequency * time) + 1));  // Sinal senoidal
    Serial.println(value);
    delay(10);  // Controla a taxa de amostragem
  }
}

