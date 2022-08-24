#include<math.h>
byte trava = 9;
byte relogio = 10;
byte bits = 11;

byte numeroBinario[8] = {0,0,0,0,0,0,0,0};

int x = 1;

void setup() {
  pinMode(trava, OUTPUT);
  pinMode(relogio, OUTPUT);
  pinMode(bits, OUTPUT);

  digitalWrite(trava, LOW);
  digitalWrite(relogio, LOW);
  digitalWrite(bits, LOW);
}

void loop() {
  if(x==256){
    x=1;
    for(int x=0; x<9; x++){
      numeroBinario[x] = 0;
    }
  }
  transformaBinario(x);
  setLed();
  delay(1000);
  x = x*2;
  
}

void transformaBinario(int numero){
  byte *ponteiroBinario = numeroBinario;
  int numerador = numero;
  int y = 0;
  for(int x=0; x<9; x++){
    if(numero-(pow(2, x))<0){break;}
    y += 1;
  }
  for(int x=y; x>-1; x--){
    *ponteiroBinario = numerador%2;
    numerador= numerador/2;
    ponteiroBinario+=1;
  }
}

void setLed(){
  digitalWrite(trava, LOW);
  byte *ponteiroBinario = numeroBinario;
  for(int x=0; x<9; x++){
    if(*ponteiroBinario==1){digitalWrite(bits, HIGH);}
    else{digitalWrite(bits, LOW);}
    ponteiroBinario+=1;
    digitalWrite(relogio, HIGH);
    digitalWrite(relogio, LOW);
  }
  digitalWrite(trava, HIGH);
}