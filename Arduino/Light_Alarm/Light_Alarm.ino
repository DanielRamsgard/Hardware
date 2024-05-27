//All code produced by Daniel Ramsgard - https://danielramsgard.github.io/my_web.html
const int BUZZ_Pin = 3;
const int LIGHT_Value = 100;
//Setup code
void setup() {
  pinMode(A2, INPUT);
  pinMode(BUZZ_Pin, OUTPUT);
}
void loop() {
  //Loop code to buzz when light intensity reaches light_value
  if (analogRead(A2) >= LIGHT_Value){
    digitalWrite(BUZZ_Pin, HIGH);
    delay(800);
    digitalWrite(BUZZ_Pin, LOW);
    delay(600);
  }
}
