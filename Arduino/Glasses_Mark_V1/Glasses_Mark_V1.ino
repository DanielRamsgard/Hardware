//All code produced by Daniel Ramsgard - https://danielramsgard.github.io/my_web.html
//Libraries included and minor parts of example codes used in project
#include "OLED_Driver.h"
#include "GUI_paint.h"
#include "DEV_Config.h"
#include "Debug.h"
#include "ImageData.h"
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"

//3:RX 2:TX
VR myVR(2,3); 

//Save records; establish size of buf
uint8_t records[7];
uint8_t buf[64];

//Pretrained commands entered as their assigned indexs: 0,1, ... 6
#define how    (0)
#define name   (1) 
#define date   (2) 
#define number (3) 
#define school (4) 
#define today  (5) 
#define where  (6) 
//Variable set
UBYTE *BlackImage;

void setup() {
  //Initialization of Waveshare TOLED 
  System_Init();                          //System/display initialized
  OLED_1IN51_Init();                      //Display initialized
  Driver_Delay_ms(500);                   //Short delay
  OLED_1IN51_Clear(); 
  //Create a new image cache
  UWORD Imagesize = ((OLED_1IN51_WIDTH%8==0)? (OLED_1IN51_WIDTH/8): (OLED_1IN51_WIDTH/8+1)) * OLED_1IN51_HEIGHT;
  if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
      Serial.print("Failed to apply for black memory...\r\n");
      return -1;
  }
  //Settings for image set
  Paint_NewImage(BlackImage, OLED_1IN51_WIDTH, OLED_1IN51_HEIGHT, 270, BLACK);  
  //Select Image
  Paint_SelectImage(BlackImage);
  Paint_Clear(BLACK);
  //More settings specific to orientation of screen
  Paint_SetMirroring(MIRROR_HORIZONTAL);
  Paint_SetRotate(ROTATE_180);
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
  //Finalization Statment
  //Serial.println("System Ready");
}

void loop() {
  //Establish a variable for the output of the VR module
  int ret;
  ret = myVR.recognize(buf, 50);
  //If there is 
  if(ret>0){
    switch(buf[1]){
      case how:
        //Print 
        Serial.println("how");
        //Message
        Paint_DrawString_EN(0, 0, "How are you?", &Font8, WHITE, WHITE);
        break;
      case name:
        //Print
        Serial.println("name");
        //Message
        Paint_DrawString_EN(0, 0, "What's your", &Font8, WHITE, WHITE);
        Paint_DrawString_EN(0, 8, "name?", &Font8, WHITE, WHITE);
        break;
      case date:
        //Print
        Serial.println("date");
        //Message
        Paint_DrawString_EN(0, 0, "What's the", &Font8, WHITE, WHITE);
        Paint_DrawString_EN(0, 8, "date?", &Font8, WHITE, WHITE);
        break;
      case number:
        //Print
        Serial.println("number");
        //Message
        Paint_DrawString_EN(0, 0, "What's your", &Font8, WHITE, WHITE);
        Paint_DrawString_EN(0, 8, "number?", &Font8, WHITE, WHITE);
        break;
      case school:
        //Print
        Serial.println("school");
        //Message
        Paint_DrawString_EN(0, 0, "Where do you", &Font8, WHITE, WHITE);
        Paint_DrawString_EN(0, 8, "go to school?", &Font8, WHITE, WHITE);
        break;
      case today:
        //Print
        Serial.println("today");
        //Message
        Paint_DrawString_EN(0, 8, "off", &Font8, WHITE, WHITE);
        free(BlackImage);
        break;
      case where:
        //Print
        Serial.println("where");
        //Message
        Paint_DrawString_EN(0, 0, "Where are", &Font8, WHITE, WHITE);
        Paint_DrawString_EN(0, 8, "you from?", &Font8, WHITE, WHITE);
        break;
      default:
        Serial.println("Speak again: unrecognized command");
        break;
    }
    OLED_1IN51_Display(BlackImage); 
    Driver_Delay_ms(4000);    
    Paint_Clear(BLACK);
    OLED_1IN51_Clear();
  }
//add a command in there for "off" that frees the malloc dynamically allocated memory of BlackImage
}
