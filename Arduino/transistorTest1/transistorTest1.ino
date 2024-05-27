
int i;

void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
 for (i = 0; i < 150; i += 10)
{
  analogWrite(5, i);
  Serial.println(i);
  delay(5000);
  analogWrite(5, 0);
  delay(5000);
}
}
