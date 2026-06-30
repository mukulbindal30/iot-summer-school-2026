//tinkercad link : https://www.tinkercad.com/things/5hKuMvlDwwN-blink-led-using-arduino-pin-13
void setup() {
  pinMode(13, OUTPUT);
}
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
