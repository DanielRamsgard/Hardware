//All code produced by Daniel Ramsgard - https://danielramsgard.github.io/my_web.html
const int LED_Pin1 = 0;
const int LED_Pin2 = 2;

void setup() {
  pinMode(LED_Pin1, OUTPUT);
  pinMode(LED_Pin2, OUTPUT);
  pinMode(A2, INPUT);
}

void loop() {
  if (analogRead(A2) >= 12 && analogRead(A2) < 15){
    digitalWrite(LED_Pin1, HIGH);
    delay(200);
    digitalWrite(LED_Pin1, LOW);
    delay(200);
  }
  if (analogRead(A2) >= 15){
    digitalWrite(LED_Pin1, HIGH);
    digitalWrite(LED_Pin2, HIGH);
    delay(100);
    digitalWrite(LED_Pin1, LOW);
    digitalWrite(LED_Pin2, LOW);
    delay(100);
  }
}
