#include <dht.h>

dht DHT;

#define DHT11_PIN 7
#define PIEZO_PIN 2

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.clear();
  lcd.backlight();      // Make sure backlight is on

  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  digitalWrite(PIEZO_PIN, LOW);
  int chk = DHT.read11(DHT11_PIN);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");//Set cursor to character 2 on line 0
  lcd.setCursor(5, 0);  //Move cursor to character 2 on line 1
  lcd.print(DHT.temperature);
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.setCursor(9, 1);  //Move cursor to character 2 on line 1
  lcd.print(DHT.humidity);
  delay(1000);

  if(DHT.temperature +  1){
      lcd.setCursor(0, 1);
      lcd.print("HIGH TEMPERATURE");
      delay(1000);
      digitalWrite(PIEZO_PIN,HIGH);
      delay(100);
      }
   else if(DHT.humidity + 1){
      lcd.setCursor(0, 1);
      lcd.print("HIGH HUMIDITY");
      delay(1000);
      digitalWrite(PIEZO_PIN,HIGH);
      delay(100);     
   }
}
