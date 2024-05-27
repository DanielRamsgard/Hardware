// code written by group 10 APPL 110
// initial setup for variables
int timeInMicro;
int distanceInCm;
int trig = 3;
int echo = 4;

// setup code block for the HC-SR04 and ATtiny85 output pins 
void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  delay(1500);
}
void loop() {

  // necessary code block for the ultrasonic sensor 
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // conversion to get distance in cm 
  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = ((timeInMicro/29)/2);

  // switch case for distance to vibrate differently and make sounds depending val
  switch (distanceInCm){
    case 1 ... 3:
    analogWrite(1, 100);
    delay(100);
    analogWrite(1, 0);
    delay(200);
    break;
    case 4 ... 40:
    analogWrite(0, 255);
    delay(300);
    break;
    case 41 ... 50:
    analogWrite(0, 200);
    delay(300);
    break;
    case 51 ... 70:
    analogWrite(0, 100);
    delay(300);
    break;
    default:
    break;
  }

  // set the pins to zero 
  analogWrite(0, 0);
  analogWrite(1, 0);
}