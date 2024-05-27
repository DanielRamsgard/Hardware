//All code produced by Daniel Ramsgard www.hackster.io/Daniel-Ramsgard
void setup() {
}
void loop() {
}

//Stopwatch function: prints time elapsed 
int stopWatch(){
  //Static variable declarations
  static int dividend = 1;
  static int divisor = 60;
  static int minuteCounter;
  //If blocks
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

//Function that provides a displacement value using the HC_SR04, a popular ultrasonic sensor
int ultrasonicDisplacement(int trig, int echo)
{
  //Initialize variables
  int timeInMicro;
  int distanceInCm;
  //Code needed for proper function of HC-SR04
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //Arithmetic of variables to compute displacement
  timeInMicro = pulseIn(echo, HIGH);
  distanceInCm = ((timeInMicro/29)/2);
  //Return value of function
  return distanceInCm;
}

//Function that computes an equivalent parallel resistance (up to seven resistors)
float parallelResistance( float a, float b, float c, float d, float e, float f, float g){ 
  float inverse[7] = {(1/a), (1/b), (1/c), (1/d), (1/e), (1/f), (1/g)};
  //Setting any values to zero
  for (int i=0; i<7; ++i){
    if (i == 0 && a == 0){
      inverse[i] = 0;
    } else if (i == 1 && b == 0){
      inverse[i] = 0;
    } else if (i == 2 && c == 0){
      inverse[i] = 0;
    } else if (i == 3 && d == 0){
      inverse[i] = 0;
    } else if (i == 4 && e == 0){
      inverse[i] = 0;
    } else if (i == 5 && f == 0){
      inverse[i] = 0;
    } else if (i == 6 && g == 0){
      inverse[i] = 0;
    }
  }
  //Arithmetic needed for algorithm
  float sum = 0;
  for (int i=0; i<7; ++i){
    sum += inverse[i];
  } 
  float pResistanceA = (1/sum);
  //Return value of function is eq resistance
  return pResistanceA; 
}

//Pythagorean Theorem: take two perpendicular sides to compute third side
float pTheorem( float a, float b){
    float hypotenuse = (sqrt(a*a + b*b));
    return hypotenuse;
}

//Function that computes an equivalent parallel capacitance (up to seven caps)
float seriesCapacitance( float a, float b, float c, float d, float e, float f, float g){ 
  float inverse[7] = {(1/a), (1/b), (1/c), (1/d), (1/e), (1/f), (1/g)};
  //Setting any values to zero
  for (int i=0; i<7; ++i){
    if (i == 0 && a == 0){
      inverse[i] = 0;
    } else if (i == 1 && b == 0){
      inverse[i] = 0;
    } else if (i == 2 && c == 0){
      inverse[i] = 0;
    } else if (i == 3 && d == 0){
      inverse[i] = 0;
    } else if (i == 4 && e == 0){
      inverse[i] = 0;
    } else if (i == 5 && f == 0){
      inverse[i] = 0;
    } else if (i == 6 && g == 0){
      inverse[i] = 0;
    }
  }
  //Arithmetic needed for algorithm
  float sum = 0;
  for (int i=0; i<7; ++i){
    sum += inverse[i];
  } 
  //Return value of function is eq capacitance
  float seriesCapacitance = (1/sum);
  return seriesCapacitance; 
}

//Function to determine unknown quantities (input zero for unknown quantitie)
//Function returns unknown, the input set to zero
float ohmsLaw( float v, float i, float r){
  if (v != 0 && i != 0 && r == 0){
    float resistance = (v/i);
    return resistance;
  } else if (v != 0 && i == 0 && r != 0){
    float amperage = (v/r);
    return amperage;
  } else if (v == 0 && i !=0 && r != 0){
    float voltage = (i*r);
    return voltage;
  } else {
    int zero = 0;
    return 0;
  }
}






