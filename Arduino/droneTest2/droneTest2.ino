//All code produced by Daniel Ramsgard
void setup() {
  //Set pinModes for output pins (transistor bases)
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  //Set all transistor bases to FB
  analogWrite(6, 250);
  analogWrite(9, 250);
  analogWrite(10, 250);
  analogWrite(11, 250);
}






