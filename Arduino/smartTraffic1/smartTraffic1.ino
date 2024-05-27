//Code produced by Daniel Ramsgard
//Initialize pins and global variables
int trig = 10;
int echo = 3;
int timeInMicro;
int distanceInCm;

void setup() {
  //Set serial-port baud rate to 9600 and pinmodes for HC-SR04
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
   //Not needed for program but useful for testing displacement
   //Prints displacement to serial port
   Serial.println(ultrasonicDisplacement(trig, echo));
   //Code for red light: light set to on for ten seconds unless displacement function returns <50
   //Then green light goes on
   for (int i = 0; i < 10; i++)
   {
     digitalWrite(8, HIGH);
     delay(1000);
      if (ultrasonicDisplacement(trig, echo) < 50)
      {
        digitalWrite(8, LOW);
        digitalWrite(13, HIGH);
        delay(5000);
        digitalWrite(13, LOW);
      }
      if (i == 9)
      {
        digitalWrite(8, LOW);
      }
    }
    //Code for yellow light: light set to on for seven seconds unless displacement function returns <50
    //Then green light goes on
    for (int j = 0; j < 7; j++)
    {
     digitalWrite(4, HIGH);
     delay(1000);
      if (ultrasonicDisplacement(trig, echo) < 50)
      {
        digitalWrite(4, LOW);
        digitalWrite(13, HIGH);
        delay(5000);
        digitalWrite(13, LOW);
      }
      if (j == 6)
      {
        digitalWrite(4, LOW);
      }
    }
    //Code for green light: light set to on for ten seconds
    for (int f = 0; f < 10; f++)
    {
      digitalWrite(13, HIGH);
      delay(1000);
      if (f == 9)
      {
        digitalWrite(13, LOW);
      }
    }
 }
//Code for function used for displacement
int ultrasonicDisplacement(int trig, int echo){
 //Code for HC-SR04
 int timeInMicro;
 int distanceInCm;
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 //Variables
 timeInMicro = pulseIn(echo, HIGH);
 distanceInCm = ((timeInMicro/29)/2);
 delay(1000);
 //Function's return value
 return distanceInCm;
}