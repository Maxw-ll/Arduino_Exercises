#include<math.h>
#include <stdlib.h>

byte trava = 9;
byte relogio = 10;
byte bits = 11; 


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
  byte *numeroBinario = (byte *)malloc(sizeof(byte)*8);
  for(int i=0; i<256; i++){
    for(int x=0; x<8; x++){numeroBinario[x]=0;}
    transformaBinario(i, numeroBinario);
    setLed(numeroBinario);
    Serial.print("Número atual: ");
    Serial.println(i);
    delay(1000);
  }
  free(numeroBinario);
}

void transformaBinario(int num, byte *binary_number){
  int y = 1;
  int numerador = num;
  for(int x=1; x<9;x++){
    if(num-pow(2, x)<0){
      break;
    }
    y += 1;
  }
  for(int x=7; x>7-y;x--){
    binary_number[x] = numerador%2;
    numerador = numerador/2;
  }
}

void setLed(byte *binary_number){
  digitalWrite(trava, LOW);
  for(int x=7; x>-1; x--){
    if (binary_number[x]==1){digitalWrite(bits, HIGH);}
    else{digitalWrite(bits, LOW);}
    digitalWrite(relogio, HIGH);
    digitalWrite(relogio, LOW);
  } 
  digitalWrite(trava, HIGH);
}
