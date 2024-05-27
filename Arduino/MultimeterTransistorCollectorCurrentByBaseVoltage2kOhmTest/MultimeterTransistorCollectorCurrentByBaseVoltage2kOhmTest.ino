void setup() {
pinMode(11, OUTPUT);
Serial.begin(9600);

}

void loop() {
  for (int x = 120; x<255; x += 5){
    Serial.println(x);
    analogWrite(11, x);
    delay(4000);
    analogWrite(11, 0);
    delay(4000);
  }
  
  
  

}
