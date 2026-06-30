//Tinkercad link : https://www.tinkercad.com/things/exU1cm4cEqa-control-rgb-led-
int red = 7 ;
int green = 8 ;
int blue = 9 ;
void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green , OUTPUT);
  pinMode(blue , OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(green , HIGH);
  delay(1000);
  digitalWrite(green , LOW);
  digitalWrite(blue , HIGH);
  delay(1000);
  digitalWrite(blue , LOW);
}