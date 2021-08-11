#define LED_PIN1 6
#define LED_PIN2 5
#define LED_PIN3 3

// defining the pins
const int trigPin = 10;
const int echoPin = 11;

// defining variables
long duration;
int distance;

void setup(){
  pinMode(trigPin, OUTPUT);
  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); 
  // Sets the echon as an Input
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  Serial.begin(9600); 
  // Starts the serial communication
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
  LED_bright_dim();
}


void LED_bright_dim(){
  if (distance <= 2) {
    analogWrite(LED_PIN1, 200);
    analogWrite(LED_PIN2, 200);
    analogWrite(LED_PIN3, 200);

  }
  else if (distance <= 3) {
    analogWrite(LED_PIN1, 150);
    analogWrite(LED_PIN2, 150);
    analogWrite(LED_PIN3, 150);
  }

  else if (distance <= 7) {
    analogWrite(LED_PIN1, 100);
    analogWrite(LED_PIN2, 100);
    analogWrite(LED_PIN3, 100);
  }

  else if  (distance <= 10) {
    analogWrite(LED_PIN1, 50);
    analogWrite(LED_PIN2, 50);
    analogWrite(LED_PIN3, 50);

  }
}
