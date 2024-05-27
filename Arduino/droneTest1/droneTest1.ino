void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  int i = 250;
  
  
    analogWrite(6, i);
    analogWrite(9, i);
    analogWrite(10, i);
    analogWrite(11, i);
    Serial.println(i);
    
  

}
