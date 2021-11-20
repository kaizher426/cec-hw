#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);

}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temp: ")
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
