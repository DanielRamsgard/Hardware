void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  
  for (int i = 0; i < 15; i++)
  {
    digitalWrite(8, HIGH);
    delay(1000);
      if (i == 14)
      {
        digitalWrite(8, LOW);
      }
  }

  for (int j = 0; j < 7; j++)
  {
    digitalWrite(4, HIGH);
    delay(1000);
      if (j == 6)
      {
        digitalWrite(4, LOW);
      }
  }

  for (int f = 0; f < 15; f++)
  {
    digitalWrite(13, HIGH);
    delay(1000);
      if (f == 14)
      {
        digitalWrite(13, LOW);
      }
  }



}
