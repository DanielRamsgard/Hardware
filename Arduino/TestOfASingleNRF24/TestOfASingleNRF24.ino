#include <SPI.h>
#include <RF24.h>
#include <printf.h>

RF24 radio(7, 8);

byte addresses[][6] = {"1Node", "2Node"};


void setup() {

  radio.begin();
  radio.setPALevel(RF24_PA_LOW);

  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.startListening();

  Serial.begin(9600);
  
}

void loop() {
  radio.printDetails();

}
