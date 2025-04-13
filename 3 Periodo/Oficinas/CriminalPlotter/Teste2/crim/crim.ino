#include <Keypad.h>

const byte LINHAS = 3;  // Número de linhas
const byte COLUNAS = 3; // Número de colunas

int i;

int motorX[] = {2, 3, 4, 5};
int motorY[] = {6, 7, 8, 9};
int motorZ[] = {10, 11, 12, 13};

int xAtual = 0, yAtual = 0;
bool horario = false;

const int velocidade = 97;
const int passo = 10; // 2mm de distância entre os passos
const int passoEvento = 7;
const int passoZ = 50;
const int tmp = 100;
const int giros_inicioZ = 50;
const int motorDelay = 100 - velocidade;
const int giros_inicio = 1300;
const int tmpEvento = 10;

// Teclas
char combinacao[4];

char teclas[LINHAS][COLUNAS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'*', '0', '#'}
    };

byte pinosLinhas[LINHAS] = {A5, A4, A3};   // Conecte as linhas do teclado aqui
byte pinosColunas[COLUNAS] = {A2, A1, A0}; // Conecte as colunas do teclado aqui

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinhas, pinosColunas, LINHAS, COLUNAS);

void setup()
{

  Serial.begin(9600);

  Serial.setTimeout(5000); // Configura o timeout de leitura para 10 segundos (10000 ms)

  for (i = 0; i < 4; i++)
  {
    pinMode(motorX[i], OUTPUT); // Configura os pinos como saída
    pinMode(motorY[i], OUTPUT); // Configura os pinos como saída
    pinMode(motorZ[i], OUTPUT); // Configura os pinos como saída
  }

}


void desenhar()
{

  Serial.println("Pronto");
  bool primBuffer = true;
  
  // while o python enviar valores para x e y
  Serial.print(combinacao[0]);
  Serial.print(combinacao[2]);

  sinalEvento(1);
  sinalEvento(1);
  
  
  // Enquanto houver dados
  while (Serial.available() >= 4)
  {
    
    Serial.println("Pronto");
    
    byte x_bytes[2];
    byte y_bytes[2];
   
    // Lê os 2 bytes para x e 2 bytes para y
    x_bytes[0] = Serial.read();
    x_bytes[1] = Serial.read();
    y_bytes[0] = Serial.read();
    y_bytes[1] = Serial.read();

    // Converte os bytes para inteiros (considerando a ordem big-endian)
    int xPython = (x_bytes[0] << 8) | x_bytes[1]; // Concatena os dois bytes de x
    int yPython = (y_bytes[0] << 8) | y_bytes[1]; // Concatena os dois bytes de y

    // Direita (Antihorario)
    if (xAtual < xPython)
    {
      
      horario = false; // Direita
      mover(passo * (xPython - xAtual), motorX); // em X

    }
    
    // Esquerda (Horario)
    else if (xAtual > xPython)
    {
      //Serial.println("Esquerda");
      horario = true;
      mover(passo * (xAtual - xPython), motorX); // em x
    }

    // VERIFICAÇÃO NO EIXO Y

    if (yAtual < yPython){
      
      //Serial.println("Baixo");
      horario = false; //  
      mover(passo * (yPython - yAtual), motorY); // em x

  }

    //Serial.println("Movimentacao concluida");

    xAtual = xPython;
    yAtual = yPython;
    
    //Serial.println("Canetar");
    
    // Sempre mover eixo z
    canetar(passoZ);

    //Serial.println("Rotina concluida");
  }
  // Serial.println("Terminou o desenho");
}

void mover(int giro, int motor[])
{
  /*
    Motor X:
      Horário -> Esquerda
      Antihorario -> Direita

    Motor Y:
      Horário -> Cima
      Antihorário -> Baixo

    Motor Z:
      Horário -> Sobe
      Antihorario -> Desce

  */
  while (giro--)
  {

    if (horario == true)
    { // Aciona o motor no sentido Horário

      for (i = 0; i < 4; i++)
      { // Intercala o as bobinas acionadas

        digitalWrite(motor[i], HIGH); // Envia um pulso de um passo
        delay(motorDelay);
        
        digitalWrite(motor[i], LOW);
        // delay(motorDelay);
      }
    }

    else
    { // Aciona o motor no sentido Anti-Horário

      for (i = 3; i >= 0; i--)
      { // Intercala o as bobinas acionadas

        digitalWrite(motor[i], HIGH); // Envia um pulso de um passo
        delay(motorDelay);
        digitalWrite(motor[i], LOW);
        // delay(motorDelay);
      }
    }
  }
}

void teclar(int etapa)
{

  bool pressionada = false;

  while (!pressionada)
  {

    char tecla = teclado.getKey();

    if (tecla)
    {
      
      combinacao[etapa] = tecla;
      pressionada = true;
      
    }
  }
}

void inicializador()
{
  // Serial.println("Inicializador");
  xAtual = 0;
  yAtual = 0;

  horario = false;

  for (int i = 0; i < 3; i++)
  {

    combinacao[i] = 'L';

  }
  
}

void canetar(int giros)
{

  delay(tmp);

  horario = true;
  mover(giros, motorZ); // Desce

  delay(tmp);

  horario = false;
  mover(giros, motorZ); // Sobe

  delay(tmp);
}


void inicializarMotores()
{
  //Serial.println("MOTOR X");
  // Motor X
  horario = true;              // Esquerda
  mover(giros_inicio, motorX); // Desce
  delay(tmp);

  // Motor Y
  //Serial.println("MOTOR Y");
  horario = true;              // Cima
  mover(giros_inicio, motorY); // Sobe
  delay(tmp);

  // Motor Z
  //Serial.println("MOTOR Z");
  horario = false;
  mover(100, motorZ); // Subir
  delay(tmp);
}

void prim_caract()
{
  while (true)
  {
    
    teclar(0);

    if (combinacao[0] != '#' && combinacao[0] != '*' && combinacao[0] != 'L')
    {
      sinalEvento(1);

      if (confirmacao(1))
      {
        
        seg_caract();
        return;
        
      }
    }
    
    else if (combinacao[0] == '#')
    {
      
      inicializarMotores();

    }
  }
}
bool confirmacao(int etapa)
{
  while (true)
  {
    
    teclar(etapa);

    if (combinacao[etapa] == '*' && combinacao[etapa] != 'L')
    {
      
      sinalEvento(1);

      return true;
    }
    
    else if (combinacao[etapa] == '#')
    
    {

      combinacao[etapa] = 'L';
      combinacao[etapa - 1] = 'L';

      sinalEvento(2);
      
      return false;
    }
  }
}

void seg_caract()
{
  
  while (true)
  
  {

    teclar(2);

    if (combinacao[2] != '#' && combinacao[2] != '*' && combinacao[2] != 'L')
    {
      
      sinalEvento(1);

      if (confirmacao(3))
      {

        desenhar();
        return;

      }
    }
  }
}

void sinalEvento(int evento)
{

  if (evento == 1)
  { // POSITIVO
    
    horario = true;
    mover(passoEvento, motorX); // Desce
    delay(tmpEvento);

    horario = true;
    mover(passoEvento, motorY); // Sobe
    delay(tmpEvento);

    horario = false;
    mover(passoEvento, motorZ); // Desce
    delay(tmpEvento);
    
  }
  else if (evento == 2)
  { // NEGATIVO
    
    horario = false;
    mover(passoEvento, motorZ); // Desce
    delay(tmpEvento);

    horario = true;
    mover(passoEvento, motorY); // Sobe
    delay(tmpEvento);

    horario = true;
    mover(passoEvento, motorX); // Desce
    delay(tmpEvento);
  }

  horario = false;
}

void loop()
{

  inicializador();

  sinalEvento(1);

  prim_caract();
} 
