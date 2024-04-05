#include <SevSeg.h>

SevSeg sevseg;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5}; 
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12,13};
  
  bool resistorsOnSegments = false; 
  bool updateWithDelays = false;
  bool leadingZeros = true; 
  bool disableDecPoint = false; 

  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);

  sevseg.setBrightness(100); 
}

void loop() {

sevseg.setNumber(101, 2);
  sevseg.refreshDisplay();
}
