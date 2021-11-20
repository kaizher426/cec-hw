// defining the pins
const int trigPin = 11;
const int echoPin = 10;

// defining variables
long duration;
int distance;

void setup(){
  pinMode(trigPin, OUTPUT);
  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); 
  // Starts the serial communication
  Serial.begin(9600);   
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
}
