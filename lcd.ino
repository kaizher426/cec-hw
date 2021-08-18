const int buttonPin = 8;
int counter = 0;

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.clear();
  lcd.backlight();      // Make sure backlight is on
  
  lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
  lcd.print("Clicks:");
  lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
  lcd.print(counter);
}

void loop() {
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    counter++;
    lcd.clear();
    lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
    lcd.print("Clicks:");
    
    lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
    lcd.print(counter);
    delay(150);
    
    if (counter >= 10){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("What's up");
      delay(1000);
    }
    else if(counter >= 20){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Gud");
      delay(1000);
    }
    else if(counter >= 30){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("WoW");
      delay(1000);
    }
    else if(counter >= 40){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("yo!");
      delay(1000);
    }
    else if(counter >= 50{
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print(":)");
      delay(1000);
    }
  }
}
