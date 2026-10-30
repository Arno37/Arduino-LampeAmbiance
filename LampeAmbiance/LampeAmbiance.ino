const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600); // ouvrir un port série
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}
void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(1000);
  greenSensorValue = analogRead(greenSensorPin);
  delay(1000);
  blueSensorValue = analogRead(blueSensorPin);
  delay(1000);

  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.println("Raw Sensor Values : ");
  Serial.print("Green : ");
  Serial.println(greenSensorValue);
  Serial.print("Red : ");
  Serial.println(redSensorValue);
  Serial.print("Blue : ");
  Serial.println(blueSensorValue);


  Serial.print("Valeurs recalculees \t Rouge : ");
  Serial.print(redValue);
  Serial.print("\t Vert : ");
  Serial.print(greenValue);
  Serial.print("\t Bleu : ") ;
  Serial.print(blueValue) ;


  analogWrite(greenLEDPin, greenValue);
  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);

}
