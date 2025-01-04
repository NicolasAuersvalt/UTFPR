const int pot = A0;
int i;
int motorX[] = {2,3,4,5};
int motorY[] = {6,7,8,9};
int motorZ[] = {10,11,12,13};
int horario = 0;

const int velocidade = 97;
const int passo = 100;

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
      
      for( i=0 ; i < 4 ; i++ ){  // Intercala o as bobinas acionadas
        
         digitalWrite(motor[i],HIGH); // Envia um pulso de um passo
         delay(100-velocidade); 
         digitalWrite(motor[i],LOW);
      }
    }

    if(horario == false){ // Aciona o motor no sentido Anti-Horário
      
      for( i=4 ; i > -1 ; i-- ){ // Intercala o as bobinas acionadas
        
         digitalWrite(motor[i],HIGH); // Envia um pulso de um passo
         delay(100-velocidade);
         digitalWrite(motor[i],LOW); 
      }
    }
    
  }

}

void canetar(int *giros, bool *horario, int motorZ){

    *horario = true;
    mover(giros, horario, motorZ); // Desce

    *horario = false;
    mover(giros, horario, motorZ); // Sobe

}

void loop() {

    int matriz[10][10] = {
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0}
  };

  bool horario = false;
  int giros = passo;
  int sizeMat = 10;

  for (int i = 0; i < sizeMat; i++) {
    
    for (int j = 0; j < sizeMat; j++) {
          
      if(matriz[i][j]==1){

        canetar(&giros, &horario, motorZ);

      }
    horario = true;
    mover(giros, horario, motorX); // em x
  }
  horario = true;
  mover(giros, horario, motorY); 

  horario = false;
  mover(giros * sizeMat, horario, motorX); 
  }

  horario = false;
  mover(giros * sizeMat, horario, motorY); 

}