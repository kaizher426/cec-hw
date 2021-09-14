void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
}

void loop() {
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  
}
