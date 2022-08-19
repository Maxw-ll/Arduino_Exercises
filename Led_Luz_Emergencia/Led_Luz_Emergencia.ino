byte azul = 11;
byte vermelho = 10;
int tempo = 75;
void setup() {
  pinMode(azul, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop() {
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
