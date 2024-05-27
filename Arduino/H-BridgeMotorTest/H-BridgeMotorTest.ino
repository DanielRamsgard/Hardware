void setup() {
pinMode(3, OUTPUT);
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(10, OUTPUT);


}

void loop() {

analogWrite(5, 200);
analogWrite(10, 200);
analogWrite(3, 0);
analogWrite(6, 0);
delay(1000);

analogWrite(5, 0);
analogWrite(10, 0);
analogWrite(3, 200);
analogWrite(6, 200);
delay(1000);
}
