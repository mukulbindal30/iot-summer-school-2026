//Tinkercad Link : https://www.tinkercad.com/things/afw9OnjiqLW-blink-13-leds-one-by-one-exact-10-times
const int n = 14;
int pins[n] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13} ;
void setup()
{
  for(int i = 0 ; i <= n-1 ; i++){
    pinMode(pins[i] , OUTPUT);
  }
}

void loop()
{
  int k = 1 ;
  while (k <= 10){
 
      for(int j = 0 ; j<= n-1 ; j++){
      digitalWrite(pins[j] , HIGH);
      delay(1000) ;
      digitalWrite(pins[j] , LOW);
    }
    k++ ;
     
  }
  while(true){
  
  }
}