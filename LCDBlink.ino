
// include the library code:
#include <LiquidCrystal.h>
#define LED_PIN 7
#define BUTTON_PIN 6
int i = 0;
int delayValue;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("DelayValue:");
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(delayValue);
  
  int buttonState;
  buttonState = digitalRead(BUTTON_PIN);

  if (i == 12) {
    i = 0;
  }

  if (buttonState == LOW) {
    i++;
  }

  delayValue = map(i, 0, 12, 1000, 100);
  digitalWrite(LED_PIN, HIGH);
  delay(delayValue);
  digitalWrite(LED_PIN, LOW);
  delay(delayValue);
}
