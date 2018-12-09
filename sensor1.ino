int sensor = 9;
int led = 8;
int ultimo = 0;
unsigned long tempoInicial = 0;
unsigned long tempoFinal = 0;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int achou = digitalRead(sensor);

  tempoFinal = millis();
  if(tempoFinal - tempoInicial >= 6000){
    tempoInicial = tempoFinal;
    digitalWrite(led, LOW);
  }
  
  if(achou){
    digitalWrite(led, HIGH);
    tempoInicial = tempoFinal;
  }
  
}
