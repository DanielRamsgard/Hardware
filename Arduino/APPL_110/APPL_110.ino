// global variables
// temperature conversion variables setup
  int val;
  float volts;
  float temperature;

void setup()
{
  // variable declaration points to string in memory (pointer)
  char* my_name = "Daniel Ramsgard";
  
  // serial moitor initialization and delay
  Serial.begin(9600);
  Serial.println(my_name);
  delay(1000);
  
  // setup pinModes
  pinMode(9, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  val = analogRead(A0); // read from analog pin A0
  volts = (val/1024.0)*5.0; // convert this to volts
  temperature = (volts-0.75)/0.01+25.0; // convert volts to temperature
  Serial.print("The temperature is: ");
  Serial.println(temperature);
  
  if (temperature > 28) {
    analogWrite(5, 700);
    delay(1000);
  }
  else {
    analogWrite(9, 900);
    delay(1000);
  }
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
}