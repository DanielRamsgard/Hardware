//Code produced by Daniel Ramsgard using the IRremote library by Shirriff
#include <IRremote.h>
 IRrecv irrecv(A5);
int dividend = 2;
int signalValue = 1799;
//Set infrared receiving pin, that's connected to receiver output lead, to analog pin 5
//Initialize variables for a dividend variable and an IR signal value

void setup() {
  //Set pins as outputs for transistors, and initialize IR receiver
  //Set serial port baud rate to 9600
  Serial.begin(9600);
  IrReceiver.enableIRIn();
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
 //Make the divisor varibale constant: unable to be changed via arithmetic
 const int divisor = 2;
 //If there is a signal, data gets assigned to "expectedSignal"
  if (IrReceiver.decode()){
     int expectedSignal = IrReceiver.decodedIRData.decodedRawData; 
     //If the signal matches the expected signal, motor spins
     if((signalValue == expectedSignal) && (dividend%divisor == 0)){
      analogWrite(6, 200);
      analogWrite(9, 200);
      delay(3000);
      analogWrite(6, 0);
      analogWrite(9, 0);
    }
    //If the signal value matches the expected signal, motor spins in the opposite direction
     if((signalValue == expectedSignal) && (dividend%divisor == 1)){
      analogWrite(5, 200);
      analogWrite(10, 200);
      delay(3000);
      analogWrite(5, 0);
      analogWrite(10, 0);
    }
    //dividend is incremented. This allows only one of the if blocks to be valid
    dividend++;

    IrReceiver.resume();   //The infrared receiver is resumed for listening
  }
}



