int potentiometer_conversion(int pot_val){
  float new_val = pot_val / 1023.0; // relative-strength ratio
  float shift_val = 80 * new_val;
  float pwm_val = 175 + shift_val;

  // special condition where we want the vibration to stop
  if (pwm_val == 102){
    pwm_val = 0;
  }


  return pwm_val;

}

void staged_start(int x, int delay_factor){

  x = potentiometer_conversion(analogRead(A0));
  Serial.println(x);
    analogWrite(11, x);
    delay(delay_factor);
    x = potentiometer_conversion(analogRead(A0));
    Serial.println(x);
    analogWrite(10, x);
    delay(delay_factor);
    x = potentiometer_conversion(analogRead(A0));
    Serial.println(x);
    analogWrite(6, x);
    delay(delay_factor);
    analogWrite(5, x);
    Serial.println(x);

}

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  delay(100);
  int x = potentiometer_conversion(analogRead(A0));
  int delay_factor = 1000;
  
  // stay in loop if value is equal to zero
  while (x == 0){
    x = potentiometer_conversion(analogRead(A0));
    Serial.println(x);
  }

  // if we exit the loop, turn on each motor one by one
  staged_start(x, delay_factor);

  // if the voltage value is above and below two and three volts repsectfully, enter loop
  while (x > 0){
    x = potentiometer_conversion(analogRead(A0));
    Serial.println(x);
    analogWrite(11, x);
    analogWrite(10, x);
    analogWrite(6, x);
    analogWrite(5, x);
  }
}