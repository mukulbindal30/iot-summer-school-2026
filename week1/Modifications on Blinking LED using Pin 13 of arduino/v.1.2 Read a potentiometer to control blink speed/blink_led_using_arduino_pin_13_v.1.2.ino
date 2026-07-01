int ledPin = 13;
int potPin = A0;    //potentiometer pin
int blinkCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(potPin); // Read pot value
  
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);                  // Controling speed
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
  
  blinkCount++;
  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}// Fixed potentiometer upper boundary limit mapping issue
