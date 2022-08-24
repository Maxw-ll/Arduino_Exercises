#include<math.h>
byte trava = 9;
byte relogio = 10;
byte bits = 11; 

byte numeroBinario[8] = {0,0,0,0,0,0,0,0};

void setup() {
  Serial.begin(9600);
  Serial.flush();

  pinMode(trava, OUTPUT);
  pinMode(relogio, OUTPUT);
  pinMode(bits , OUTPUT);

  digitalWrite(trava, LOW);
  digitalWrite(relogio, LOW);
  digitalWrite(bits, LOW);
}

void loop() {
  for(int i=0; i<255; i++){
    transformaBinario(i);
    setLed();
    Serial.print("Número atual: ");
    Serial.println(i);
    delay(1000);
  }
}

void transformaBinario(int num){
  byte *ponteiroBinario = numeroBinario;
  int y = 1;
  int numerador = num;
  for(int x=1; x<9;x++){
    if(num-pow(2, x)<0){
      break;
    }
    y += 1;
  }
  for(int x=y; x>-1;x--){
    *ponteiroBinario = numerador%2;
     numerador = numerador/2;
     ponteiroBinario += 1;
  }
}

void setLed(){
  byte *ponteiroBinario = numeroBinario;
  digitalWrite(trava, LOW);
  for(int x=0; x<9; x++){
    if (*ponteiroBinario==1){digitalWrite(bits, HIGH);}
    else{digitalWrite(bits, LOW);}
    ponteiroBinario += 1;
    digitalWrite(relogio, HIGH);
    digitalWrite(relogio, LOW);
  } 
  digitalWrite(trava, HIGH);
}
