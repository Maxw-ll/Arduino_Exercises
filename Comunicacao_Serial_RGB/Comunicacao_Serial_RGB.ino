char caracteres[18];

byte azul = 11;
byte vermelho = 10;
byte verde = 9;

int red, green, blue;

void setup() {
    Serial.begin(9600);
    Serial.flush();
    pinMode(azul, OUTPUT);
    pinMode(vermelho, OUTPUT);
    pinMode(verde, OUTPUT);
}

void loop() {
    if(Serial.available()>0){
    delay(100);

    int numeroCaracteres = Serial.available();
    if(numeroCaracteres>15){numeroCaracteres=15;}
    int indice = 0;
    while(numeroCaracteres>0){
        caracteres[indice] = Serial.read();
        numeroCaracteres -= 1;
        indice += 1;
    }
    funcaoSplit(caracteres);
    }
}

void funcaoSplit(char *data){
    Serial.print("Entrada: ");
    Serial.println(data);
    char *parametro;
    parametro = strtok(data, ", ");
    while (parametro != NULL){
        setRGB(parametro);
        parametro = strtok(NULL, ", ");
    }
    for(int x =0; x<16; x++){
        caracteres[x] = '\0';
    }
    Serial.flush();
}
void setRGB(char *Cor){
    if((Cor[0]=='r') || (Cor[0]=='R')){
        int resposta = strtol(Cor+1, NULL, 10);
        resposta = constrain(resposta, 0, 255);
        analogWrite(vermelho, resposta);
        Serial.print("Vermelho recebe: ");
        Serial.println(resposta);
    }

    if((Cor[0]=='g')||(Cor[0]=='G')){
        int resposta = strtol(Cor+1,NULL,10);
        resposta = constrain(resposta, 0, 255);
        analogWrite(verde, resposta);
        Serial.print("Verde recebe: ");
        Serial.println(resposta);
    }

    if((Cor[0]=='b')||(Cor[0]=='B')){
        int resposta = strtol(Cor+1, NULL, 10);
        resposta = constrain(resposta, 0, 255);
        analogWrite(azul, resposta);
        Serial.print("Azul recebe: ");
        Serial.println(resposta);
    }
}
