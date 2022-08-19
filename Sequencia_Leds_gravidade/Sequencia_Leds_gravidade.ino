byte ledpin[]={4,5,6,7,8,9,10,11,12,13};
byte potpin = 2;
int leddelay;
byte momentum = 2;
void setup() {
  for(int x=0; x<10;x++){
    pinMode(ledpin[x], OUTPUT);
  }
}

void loop() {
  /*A ideia é ter uma função que faz a bola ir e voltar, recebendo
  como parâmetro uma altura, que vai diminuindo com o tmepo, por
  meio do loop. Alem disso, acrescentei o "momentum" que determina 
  de quanto em quanto essa altura diminui.*/
  
  for(int z=10; z>-1; z-=momentum){
    altura(z);
  }
}
void altura(int x){
  leddelay = analogRead(potpin)/6;
  for(int y=0; y<x; y++){
    digitalWrite(ledpin[y], HIGH);
    delay(leddelay);
  }
  for(int y=x-1; y>-1;y--){
    digitalWrite(ledpin[y], LOW);
    delay(leddelay);
  }
  delay(85);
}
