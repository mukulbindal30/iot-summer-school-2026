int ledPin = 13;
int blinkCount = 0; //Counter

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //serial comm
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  
  blinkCount++; //for counting blinking
  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}