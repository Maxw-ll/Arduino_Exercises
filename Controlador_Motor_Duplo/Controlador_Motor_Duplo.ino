
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

    intensidadeMotor1 = analogRead(potenciometro1);
    intensidadeMotor2 = analogRead(potenciometro2);

    if(digitalRead(chaveMotor1)){
        digitalWrite(positivoMotor1, HIGH);
        digitalWrite(negativoMotor1, LOW);
    }
    else{
        digitalWrite(positivoMotor1, LOW);
        digitalWrite(negativoMotor1, HIGH);
    }

    if(digitalRead(chaveMotor2)){
        digitalWrite(positivoMotor2, HIGH);
        digitalWrite(negativoMotor2, LOW);
    }
    else{
        digitalWrite(positivoMotor2, LOW);
        digitalWrite(negativoMotor2, HIGH);
    }
    
    analogWrite(sinalPWM1, intensidadeMotor1);
    analogWrite(sinalPWM2, intensidadeMotor2);

}
