#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define BUTTON_PIN 6

// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int trigPin = 9;    // TRIG pin
int echoPin = 10;    // ECHO pin
float duration_us, distance_cm;
float value;

void setup() {

  // initialize OLED display with address 0x3C for 128x64
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);
  }
  delay(2000);         // wait for initializing
  pinMode(trigPin, OUTPUT); // config trigger pin to output mode
  pinMode(echoPin, INPUT);  // config echo pin to input mode
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonState;
  buttonState = digitalRead(BUTTON_PIN);
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);


  // calculate the distance
  distance_cm = 0.017 * duration_us;
  oled.clearDisplay(); // clear display
  oled.setTextSize(2);          // text size
  oled.setTextColor(WHITE);
  oled.setCursor(0, 0);       // position to display
  oled.println("Distance:");// text color
  if (buttonState = HIGH){
    value = distance_cm
  }
  oled.setCursor(0, 30);       // position to display
  oled.println(value); // text to display
  oled.display();

  }
