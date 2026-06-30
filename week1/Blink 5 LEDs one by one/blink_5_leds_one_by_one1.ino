//Tinkercad link : https://www.tinkercad.com/things/fjtHIuvegsk-blink-5-leds-one-by-one
const int n = 5;
int pins[n] = {2,3,4,5,6} ;
void setup()
{
  for(int i = 0 ; i <= 4 ; i++){
    pinMode(pins[i] , OUTPUT);
  }
}

void loop()
{
  for(int j = 0 ; j<= n-1 ; j++){
    digitalWrite(pins[j] , HIGH);
    delay(1000) ;
    digitalWrite(pins[j] , LOW);
  }
}