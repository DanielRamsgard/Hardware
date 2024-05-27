#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

VR myVR(2,3);    // 2:RX 3:TX, you can choose your favourite pins.

uint8_t records[7]; // save record
uint8_t buf[64];

#define how    (0)
#define name   (1) 
#define date   (2) 
#define number (3) 
#define school (4) 
#define today  (5) 
#define where  (6) 

void setup()
{
  //Initialize Voice Recognition Module
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
  myVR.load((uint8_t)how);
  myVR.load((uint8_t)name);
  myVR.load((uint8_t)date);
  myVR.load((uint8_t)number);
  myVR.load((uint8_t)school);
  myVR.load((uint8_t)today);
  myVR.load((uint8_t)where); 
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case how:
        //Print 
        Serial.println("how");
        break;
      case name:
        //Print
        Serial.println("name");
        break;
      case date:
        //Print
        Serial.println("date");
        break;
      case number:
        //Print
        Serial.println("number");
        break;
      case school:
        //Print
        Serial.println("school");
        break;
      case today:
        //Print
        Serial.println("today");
        break;
      case where:
        //Print
        Serial.println("where");
        break;
      default:
        Serial.println("Speak again: unrecognized command");
        break;
    }
  }
}

