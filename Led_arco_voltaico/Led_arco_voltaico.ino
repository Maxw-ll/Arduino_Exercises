byte azul1 = 11;
byte azul2 = 10;

void setup() {
  pinMode(azul1, OUTPUT);
  pinMode(azul2, OUTPUT);
}

void loop() {
  
  /*Bem simples, usando a random aleatorizamos a intensidade, obtendo
  o efeito de arco voltaico quando um dos leds tem a intensidade máxima 
  na metade do outro*/
  
  randomSeed(analogRead(0));

  analogWrite(azul1, random(256));
  analogWrite(azul2, random(127));
  delay(20); 
}
