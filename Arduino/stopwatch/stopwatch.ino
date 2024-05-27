  int dividend = 1;
  int divisor = 60; 
  int minuteCounter; 


void setup() {
  Serial.begin(9600);

}

void loop() {
  
  stopWatch();


}


int stopWatch(){
 
  if (dividend % divisor != 0)
  {
    Serial.println(dividend - 1);
    delay(1000);
    dividend++;
    return dividend - 1;
  }
  else if (dividend % divisor == 0){
    
    Serial.print("\n");
    dividend = 1;
    minuteCounter++;
    Serial.print(minuteCounter);
    Serial.print(" minutes\n\n");
    dividend++;
    delay(1000);
    return minuteCounter;

  }
  
}