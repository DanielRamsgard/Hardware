
int trig = 10;
int echo = 5;
int timeInMicro;
int distanceInCm;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}














int ultrasonicDisplacement(int trig, int echo){
 
 int timeInMicro;
 int distanceInCm;
 digitalWrite(trig, LOW);
 delayMicroseconds(2);
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);


 timeInMicro = pulseIn(echo, HIGH);


 distanceInCm = ((timeInMicro/29)/2);


 return distanceInCm;


}
