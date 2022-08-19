byte azul = 11;
byte vermelho = 10;
int tempo = 75;
void setup() {
  pinMode(azul, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop() {
  /* A ideia é utilizar o random pra determinar a intensidade do led,
  mas o efeito em si é produzido acesdendo e apagando cada Led duas vezes*/
  randomSeed(analogRead(0));
  int intensidade = random(256);
  for(int x=0; x<2; x++){
    analogWrite(azul, intensidade);
    delay(tempo);
    analogWrite(azul, 0);
  }
  for(int x=0; x<2; x++){
    analogWrite(vermelho, intensidade);
    delay(tempo);
    analogWrite(vermelho, 0);
}}
