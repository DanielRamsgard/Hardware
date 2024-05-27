#include <SPI.h>
#include "RF24.h"

RF24 myRadio (7, 8);
byte addresses[][6] = {"0"};

int YPIN = 1;
int XPIN = 5;

struct package
{
  int RX = (analogRead(XPIN));
  int RY = (analogRead(YPIN));

};



typedef struct package Package;
Package data;

void setup() {
  Serial.begin(115200);
  delay(1000);
  myRadio.begin();
  myRadio.setChannel(115);
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS );
  myRadio.openWritingPipe( addresses[0]);
  pinMode(5, INPUT);
  pinMode(1, INPUT);
  delay(1000);

}

void loop() {
  myRadio.write(&data, sizeof(data));

  Serial.print("\nPackage:");
  Serial.print(data.RX);
  Serial.print("\n");
  Serial.println(data.RY);
  delay(1000);


}
