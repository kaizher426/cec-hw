#include <dht.h>

dht DHT;

#define DHT11_PIN 7

void setup() {
  Serial.begin(9600);

}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  StatueTemp = "Normal";
  StatueHumd = "Normal";
  
  if (DHT.humidity >=75){
    StatueHumd = "HIGH HUMIDITY";
  }
  else if(DHT.temperature >= 30){
    StatueTemp = "HIGH TEMPERATURE";
  }
  
  if (DHT.humidity <= 20){
    StatueHumd = "LOWHUMIDITY";
  }
  else if(DHT.temperature <= 20){
    StatueTemp = "LOW TEMPERATURE";
  }
  
  String p1 = ";";
  Serial.println(DHT.temperature + p1 + DHT.humidity + p1 + StatueTemp + StatueHumd);
  delay(1000);
  
}
