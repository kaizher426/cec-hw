const int buttonPin1 = 8;
const int buttonPin2 = 9;
const int buttonPin3 = 10;
const int buttonPin4 = 11;
const int buttonPin5 = 12;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);


}

void loop() {
  int buttonState1;
  buttonState1 = digitalRead(buttonPin1);
  int buttonState2;
  buttonState2 = digitalRead(buttonPin2);
  int buttonState3;
  buttonState3 = digitalRead(buttonPin3);
  int buttonState4;
  buttonState4 = digitalRead(buttonPin4);
  int buttonState5;
  buttonState5 = digitalRead(buttonPin5);
  
  if (buttonState1 == LOW)
  {
    Serial.println("1");
    delay(200);
  }
  else if (buttonState2 == LOW){
    Serial.println("2");
    delay(200);
    }
  else if (buttonState3 == LOW){
    Serial.println("3");
    delay(200);
    }
  else if (buttonState4 == LOW){
    Serial.println("4");
    delay(200);
    }
  else if (buttonState5 == LOW){
    Serial.println("5");
    delay(200);
    }
   
}
