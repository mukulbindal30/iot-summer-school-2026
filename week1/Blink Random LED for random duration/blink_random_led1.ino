//Tinkercad link : https://www.tinkercad.com/things/hSzl9FisdaF-blink-random-led
int pins[] = {2,3,4,5,6};
int dur[] = {200 , 2000};
void setup()
{
  for (int i = 0 ; i <= 4 ; i++){
    pinMode(pins[i] , OUTPUT);
    
  }

}

void loop()
{

  int x = random(2,7);
  int d = random(0 , 2);
  int a = random(0 , 2);
  int y = dur[d];
  int z = dur[a];
  digitalWrite(x, HIGH);
  delay(y);
  digitalWrite(x, LOW);
  delay(z);
}
