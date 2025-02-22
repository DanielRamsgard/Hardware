#include <SPI.h>
#include "RF24.h"


RF24 myRadio (7, 8);
struct package
{
  int RX = 0;
  int RY = 0;
  
};

byte addresses[][6] = {"0"};





typedef struct package Package;
Package data;


void setup() {
  Serial.begin(115200);
  delay(1000);

  myRadio.begin();
  myRadio.setChannel(115);
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS );
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();

}

void loop() {

  if (myRadio.available())
  {
    while (myRadio.available())
    {
      myRadio.read( &data, sizeof(data) );
  }
  Serial.print("\nPackage:");
  Serial.print(data.RX);
  Serial.print("\n");
  Serial.println(data.RY);

  }
}
