byte ledpin[] = {4,5,6,7,8,9,10,11,12,13};
int direcao = 1;
byte ledatual = 0;
int leddelay;
byte potpin = 2;;

void setup() {
  for(int x=0;x<10;x++){
    pinMode(ledpin[x], OUTPUT);
  }
}

void loop() {
    efectLed();
}

void efectLed(){
  /*Utilizando uma segunda variável alem daquela que itera dentro do for, 
   pode-se ligar ao mesmo tempo os leds das pontas, e por meio do incremento 
   de uma e decremento da outra obtêm-se o efeito de colisão*/
   
  int fim = 9;
  leddelay = analogRead(potpin)/4;
  for(int x=0; x<10; x++){
    delay(leddelay);
    for(int x=0; x<10; x++){
    digitalWrite(ledpin[x], LOW);
    }
    digitalWrite(ledpin[x], HIGH);
    digitalWrite(ledpin[fim], HIGH);
    fim -= 1;
  }
}
