#include "OLED_Driver.h"
#include "GUI_paint.h"
#include "DEV_Config.h"
#include "Debug.h"
#include "ImageData.h"
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
//Sets variable

UBYTE *BlackImage;


void setup() {
  System_Init();                          //System/display initiliazed
  OLED_1IN51_Init();                      //Display initiliazed
  Driver_Delay_ms(500);                   //Short delay
  OLED_1IN51_Clear(); 
  //0.Create a new image cache /* not really needed unless selecting an image from memory
  //UBYTE *BlackImage;
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


  /*//Message
  Paint_DrawString_EN(0, 0, "How are you?", &Font8, WHITE, WHITE); 
  OLED_1IN51_Display(BlackImage); 
  Driver_Delay_ms(4000);    
  Paint_Clear(BLACK);
  OLED_1IN51_Clear();  */
  

}

void loop() {
  //Message
  Paint_DrawString_EN(0, 0, "Hello, Julie Aspenleiter", &Font8, WHITE, WHITE);
  Paint_DrawString_EN(0, 8, "Aspenleiter", &Font8, WHITE, WHITE);  
  OLED_1IN51_Display(BlackImage); 
  Driver_Delay_ms(4000);    
  Paint_Clear(BLACK);
  OLED_1IN51_Clear();

}


