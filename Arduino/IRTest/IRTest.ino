#include <IRremote.h> 
// setting the digital INPUT pin as 8
 const int RECV_PIN = 8;
 // Define IR receiver and results objects
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 int incrementationValue = 0;
 int i;
//IrReceiver.decodedIRData.decodedIRdata
void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();

 
}

void loop() {
 
  
  if (IrReceiver.decode()){
    int IRsignal = IrReceiver.decodedIRData.decodedRawData;
    if (IRsignal != 0){
    Serial.print(IRsignal);
    Serial.print("        ");
    Serial.println(incrementationValue);
    incrementationValue++;
    }
    irrecv.resume();
   
    
   
  }

}
