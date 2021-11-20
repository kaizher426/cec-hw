#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);

}


void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.println(DHT.temperature);
  Serial.print("Humidity: ");
  Serial.println(DHT.humidity);
  delay(1000);

  if(DHT.temperature +  1){
      Serial.print("HIGH TEMP")
      delay(100);
      }
   else if(DHT.humidity + 1){
      Serial.print("HIGH HUMIDITY");
      delay(100);     
   }
}
