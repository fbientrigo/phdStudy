/*
Codigo de semaforo
Hay 3 leds conectados a una resistencia de 330[Omhs],
Luego corre el loop en donde el valor de i va cambiando y estableciendo el estado

Este codigo usa un divisor de corriente en el LDR,
de manera que se puede comprara la resistencia.

A mayor luz va mas rapido, a menor luz va mas lento
*/
  // ============= Pins =============
const int RedPin = 7;
const int YellowPin = 6;
const int GreenPin = 5;
const int LDRPin = A0; // Pin analógico donde se conecta el LDR
int delayTime = 1000; // Delay inicial de 1 segundo
int i=0;

void setup() {
  // Setups del codigo
  pinMode(RedPin, OUTPUT);
  pinMode(YellowPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  // inicializa en Low
  digitalWrite(RedPin, LOW);
  digitalWrite(YellowPin, LOW);
  digitalWrite(GreenPin, LOW);
  
  int i=0; // usada en loops
  Serial.begin(9600);

}

void loop() {
  int sensorValue = analogRead(LDRPin); // Lee el valor del sensor de luz
  delayTime = map(sensorValue, 80, 400, 10, 800); // Mapea el valor del sensor al rango de delay deseado (500 ms a 3 segundos)
  
  Serial.print("i: ");
  Serial.print(i);
  Serial.print(", Sensor: ");
  Serial.print(sensorValue);
  Serial.print(", Delay: ");
  Serial.println(delayTime);
  
  delay(delayTime); // Usa la variable delayTime para controlar el tiempo de espera

  if (i%4==0) digitalWrite(RedPin, HIGH);
  else if (i%4==1) digitalWrite(YellowPin, HIGH);
  else if (i%4==2) digitalWrite(GreenPin, HIGH);
  else {
    digitalWrite(RedPin, LOW);
    digitalWrite(YellowPin, LOW);
    digitalWrite(GreenPin, LOW);
  }
  i++;

}
