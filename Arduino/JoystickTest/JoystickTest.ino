int YPIN = 1;
int XPIN = 5;
//int SW = 2;


void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT);
  pinMode(1, INPUT);

}

void loop() {
  //Serial.print("SW: ");
  //Serial.println(digitalRead(SW));
  Serial.print("URY: ");
  Serial.println(analogRead(YPIN));
  Serial.print("URX: ");
  Serial.println(analogRead(XPIN));
  Serial.print("\n\n");
  delay(1000);



}
