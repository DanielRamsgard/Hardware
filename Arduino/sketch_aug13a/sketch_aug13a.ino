void setup() {
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);


}

void loop() {
  delay(2000);
  digitalWrite(0, HIGH);
  if (analogRead(A1) == 1023){
  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delay(1000);
  }

}
