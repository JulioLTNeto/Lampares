int sensor = 9;
int sensor2 = 10;
int sensor3 = 11;
int sensor4 = 12;
int led = 8;
int ultimo = 0;
int ledA = 13;
unsigned long tempoInicial = 0;
unsigned long tempoFinal = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(led, OUTPUT);
  pinMode(ledA, OUTPUT);
}

void loop() {
  int achou = digitalRead(sensor);
  int achou2 = digitalRead(sensor2);
  int achou3 = digitalRead(sensor3);
  int achou4 = digitalRead(sensor4);

  tempoFinal = millis();
  if(tempoFinal - tempoInicial >= 6000){
    tempoInicial = tempoFinal;
    digitalWrite(led, HIGH);
    digitalWrite(ledA, LOW);
    Serial.println("Fechar");
  }
  
  if(achou || achou2 || achou3 || achou4){
    Serial.println("Detectou, reiniciando contagem");
    digitalWrite(led, LOW);
    digitalWrite(ledA, HIGH);
    tempoInicial = tempoFinal;
  }
  
}
