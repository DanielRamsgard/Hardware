//All code produced by Daniel Ramsgard - https://danielramsgard.github.io/my_web.html
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
//0:TX 1:RX 
VR myVR(0,1); 
//Save records; establish size of buf
uint8_t records[7];
uint8_t buf[64];
//Pretrained commands entered as their assigned indexs: 0,1, ... 6
#define system_check     (0)
#define snore2           (1) 
#define snore3           (2) 
#define snore4           (3) 
#define snore5           (4) 
#define snore6           (5) 
#define quickb1          (6) 
int counter = 0;
//Setup code
void setup() {
  //VR mod setup
  myVR.begin(9600);
  //Debugging 
  if(myVR.clear() == 0){
  }
  //Loading pretrained commands to module
  myVR.load((uint8_t)system_check);
  myVR.load((uint8_t)snore2);
  myVR.load((uint8_t)snore3);
  myVR.load((uint8_t)snore4);
  myVR.load((uint8_t)snore5);
  myVR.load((uint8_t)snore6);
  myVR.load((uint8_t)quickb1); 

  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

}
//Loop code
void loop() {
  //Establish a variable for the output of the VR module
  int ret;
  ret = myVR.recognize(buf, 50);
  //If there is 
  if(ret>0){
    switch(buf[1]){
      case system_check:
        for (int i = 0; counter > i; i++){
          digitalWrite(3, HIGH);
          delay(1000);
          digitalWrite(3, LOW);
          delay(1000);
        }
        counter = 0; 
        break;
      case snore2:
        digitalWrite(2, HIGH);
        delay(3000);
        digitalWrite(2, LOW);
        delay(500);
        counter++;
        break;
      case snore3:
        digitalWrite(2, HIGH);
        delay(3000);
        digitalWrite(2, LOW);
        delay(500);
        counter++;
        break;
      case snore4:
        digitalWrite(2, HIGH);
        delay(3000);
        digitalWrite(2, LOW);
        delay(500);
        counter++;
        break;
      case snore5:
        digitalWrite(2, HIGH);
        delay(3000);
        digitalWrite(2, LOW);
        delay(500);
        counter++;
        break;
      case snore6:
        digitalWrite(2, HIGH);
        delay(3000);
        digitalWrite(2, LOW);
        delay(500);
        counter++;
        break;
      case quickb1:
        digitalWrite(2, HIGH);
        delay(3000);
        digitalWrite(2, LOW);
        delay(500);
        counter++;
        break;
      default:
        break;
    }
  }
}
