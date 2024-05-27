//All code produced by Daniel Ramsgard - https://danielramsgard.github.io/my_web.html
const int pirPin = 4; 
const int LED_Pin = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(LED_Pin, OUTPUT);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  
  if (motionDetected == HIGH) {
    digitalWrite(LED_Pin, HIGH);
    delay(10);
    digitalWrite(LED_Pin, LOW);
  } else {
    digitalWrite(LED_Pin, LOW);
  }
  delay(50);
}




