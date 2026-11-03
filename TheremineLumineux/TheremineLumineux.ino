const int sensorPin = A0;
const int speakerPin = 8;
const int ledPin = 13;

int sensorValue = 0;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  // On active la communication avec l'ordinateur pour lire les valeurs
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  // On affiche la valeur en direct sur l'ordinateur
  Serial.print("Valeur capteur : ");
  Serial.println(sensorValue);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 200, 500);
  tone(speakerPin, pitch);
  delay(50);
}