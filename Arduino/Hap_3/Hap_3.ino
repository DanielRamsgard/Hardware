// code written by group 10 APPL 110
// initial setup for variables
int timeInMicro;
int distanceInCm;
int trig = 12;
int echo = 13;

// setup code block for the HC-SR04 and ATtiny85 output pins 
void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
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

 Serial.println(distanceInCm);
 // switch case for distance to vibrate differently and make sounds depending val
  switch (distanceInCm){
    case 6 ... 10:
    analogWrite(3, 100);
    delay(200);
    analogWrite(3, 0);
    delay(300);
    break;
    case 11 ... 60:
    digitalWrite(7, HIGH);
    delay(300);
    default:
    // set the pins to zero 
    digitalWrite(7, LOW);
    analogWrite(3, 0);
    break;
  }
}