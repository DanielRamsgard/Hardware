//All code produced by Daniel Ramsgard - https://danielramsgard.github.io/my_web.html
//Libraries included and minor parts of example codes used in project
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
//3:RX 2:TX
VR myVR(3,4); 
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
  Serial.begin(115200);
  //Debugging 
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }
  else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  //Loading pretrained commands to module
  myVR.load((uint8_t)system_check);
  myVR.load((uint8_t)snore2);
  myVR.load((uint8_t)snore3);
  myVR.load((uint8_t)snore4);
  myVR.load((uint8_t)snore5);
  myVR.load((uint8_t)snore6);
  myVR.load((uint8_t)quickb1); 
  //Finalization Statment
  Serial.println("System Ready");
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
        //Print 
        Serial.print("system_check: ");
        Serial.println(counter);
        break;
      case snore2:
        //Print
        Serial.println("snore2");
        counter++;
        break;
      case snore3:
        //Print
        Serial.println("snore3");
        counter++;
        break;
      case snore4:
        //Print
        Serial.println("snore4");
        counter++;
        break;
      case snore5:
        //Print
        Serial.println("snore5");
        counter++;
        break;
      case snore6:
        //Print
        Serial.println("snore6");
        counter++;
        break;
      case quickb1:
        //Print
        Serial.println("quickb1");
        counter++;
        break;
      default:
        Serial.println("Speak again: unrecognized command");
        break;
    }
  }
}
