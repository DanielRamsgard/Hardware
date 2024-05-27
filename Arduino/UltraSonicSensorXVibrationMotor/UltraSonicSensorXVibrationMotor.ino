//Code produced by Daniel Ramsgard 
//Initialize variables and set pins
int trig = 10;
int echo = 5;
int timeInMicro;
int distanceInCm;

void setup() {
  //Set serial port baud rate to 9600 and pins to output
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(5, INPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  //Functions needed to use and receive data from the HC-SR04
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //PulseIn function records the time for ultrasonic waves to travel back to sensor
  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = ((timeInMicro/29)/2); //Speed conversion and division by two to get displacement
  //Switch case blocks for more tight code (functionality equivalent to many if statements)
  //Set different displacements to different voltages (results in different vibration amplitudes)
  switch (distanceInCm){
    case 0 ... 30:
    analogWrite(11, 225);
    break;
    case 31 ... 40:
    analogWrite(11, 200);
    break;
    case 41 ... 50:
    analogWrite(11, 175);
    break;
    default:
    analogWrite(11, 0);
    break;
  }
  delay(100);
}
