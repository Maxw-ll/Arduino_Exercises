
byte potenciometro1 = 0;
byte potenciometro2 = 1;
byte chaveMotor1 = 2;
byte chaveMotor2 = 5;
byte positivoMotor1 = 3;
byte negativoMotor1 = 4;
byte positivoMotor2 = 6;
byte negativoMotor2 = 7;
byte sinalPWM1 = 9;
byte sinalPWM2 = 10;

int intensidadeMotor1;
int intensidadeMotor2;

void setup() {
    pinMode(chaveMotor1, INPUT);
    pinMode(chaveMotor2, INPUT);

    pinMode(positivoMotor1, OUTPUT);
    pinMode(negativoMotor1, OUTPUT);
    pinMode(positivoMotor2, OUTPUT);
    pinMode(negativoMotor2, OUTPUT);
    pinMode(sinalPWM1, OUTPUT);
    pinMode(sinalPWM2, OUTPUT);
}

void loop() {

  
}
