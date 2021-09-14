#define LED_1_R 11
#define LED_1_G 10
#define LED_1_B 9

#define LED_2_R 6
#define LED_2_G 5
#define LED_2_B 3

#define LED_3_R A0
#define LED_3_G A1
#define LED_3_B A2

#define PIEZO_PIN 2

void lightLED(int led, int red, int green, int blue){
  if (led == 1){
    analogWrite(LED_1_R, 255-red);
    analogWrite(LED_1_G, 255-green);
    analogWrite(LED_1_B, 255-blue);
  }
  else if (led == 2){
    analogWrite(LED_2_R, 255-red);
    analogWrite(LED_2_G, 255-green);
    analogWrite(LED_2_B, 255-blue);
  }
  else if (led == 3){
    analogWrite(LED_3_R, 255-red);
    analogWrite(LED_3_G, 255-green);
    analogWrite(LED_3_B, 255-blue);
  }
} 


void setup() {
  pinMode(LED_1_R, OUTPUT);
  pinMode(LED_1_G, OUTPUT);
  pinMode(LED_1_B, OUTPUT);

  pinMode(LED_2_R, OUTPUT);
  pinMode(LED_2_G, OUTPUT);
  pinMode(LED_2_B, OUTPUT);

  pinMode(LED_3_R, OUTPUT);
  pinMode(LED_3_G, OUTPUT);
  pinMode(LED_3_B, OUTPUT); 
  
  pinMode(PIEZO_PIN, OUTPUT);
}

void loop() {
  lightLED(1, 255,0,0); delay(1000);
  digitalWrite(11, HIGH);
  delay(1000); 
  digitalWrite(11, LOW);
  delay(1000); 
  lightLED(1, 0,0,0); delay(500);
  lightLED(2, 255,255,0); delay(1000);
  lightLED(2, 0,0,0); delay(500);
  lightLED(3, 0,255,0); delay(1000);
  lightLED(3, 0,0,0); delay(500);
}
