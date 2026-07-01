/*
 @author Mukul Bindal
 @date 2026-07-01
 @brief LED control system featuring serial diagnostics and potentiometer speed regulation.
 */

//tinkercad link : https://www.tinkercad.com/things/5hKuMvlDwwN-blink-led-using-arduino-pin-13
int ledPin = 13;
int potPin = A0;
int blinkCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin);
  
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
  
  blinkCount++;
  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}