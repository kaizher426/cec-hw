String val;     // Data received from serial port
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  if (Serial.available()) {
    // If data is available to read,
    val = Serial.readStringUntil('\n');
    val.trim();
    Serial.println(val);
  }
  
  if (val == "RED") {
      lcd.setCursor(0, 0);
      lcd.print("RED");
  } 
  if else (val == "GREEN"){
      lcd.setCursor(0, 0);
      lcd.print("GREEN");
  }
  if else(val == "BLUE"){
      lcd.setCursor(0, 0);
      lcd.print("BLUE");    
  }
}
