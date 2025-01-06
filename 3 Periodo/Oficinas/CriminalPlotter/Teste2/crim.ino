const int pot = A0;
int i;
int motorX[] = {2,3,4,5};
int motorY[] = {6,7,8,9};
int motorZ[] = {10,11,12,13};
int horario = 0;

const int velocidade = 97;
const int passo = 20;
const int tmp = 100;
const int motorDelay = 100 - velocidade;

void setup() {

  
  Serial.begin(9600);

  for( i=0 ; i < 4 ; i++ ){
    pinMode(motorX[i],OUTPUT); // Configura os pinos como saída
    pinMode(motorY[i],OUTPUT); // Configura os pinos como saída
    pinMode(motorZ[i],OUTPUT); // Configura os pinos como saída
  }
}

void mover(int giro, bool horario, int motor[]){

  while(giro--){
  
    if(horario == true){ // Aciona o motor no sentido Horário
      
      for(i = 0 ; i < 4 ; i++ ){  // Intercala o as bobinas acionadas
        
         digitalWrite(motor[i],HIGH); // Envia um pulso de um passo
         delay(motorDelay); 
         digitalWrite(motor[i],LOW);
         //delay(motorDelay);
      }
    }

    else{ // Aciona o motor no sentido Anti-Horário
      
      for(i = 3 ; i >= 0 ; i--){ // Intercala o as bobinas acionadas
        
         digitalWrite(motor[i],HIGH); // Envia um pulso de um passo
         delay(motorDelay);
         digitalWrite(motor[i],LOW); 
         //delay(motorDelay);
      }
    }
    
  }

}

void canetar(int giros, int motorZ[]){
    delay(tmp);
    mover(giros, false, motorZ); // Desce
    delay(tmp);
    mover(giros, true, motorZ); // Sobe
    delay(tmp);
}

void loop() {

    int matriz[10][10] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
  };

  bool horario = false;
  int sizeMat = 10;

  for (int i = 0; i < sizeMat; i++) {
    for (int j = 0; j < sizeMat; j++) {
      horario = false;
          
      if(matriz[i][j]==1){
        canetar(passo + 10, motorZ);

      }
    horario = false;
    mover(passo, horario, motorX); // em x
  }
  horario = true;
  mover(passo, horario, motorY); 

  horario = true;
  mover(passo * sizeMat, horario, motorX); 
  }

  horario = false;
  mover(passo * sizeMat, horario, motorY); 

}