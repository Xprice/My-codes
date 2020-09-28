
// ARDUINO <--> FDC
// A4 <-------> SDA
// A5 <-------> SCL

#include <Wire.h>
#include "FDC2214.h"
FDC2214 capsense(FDC2214_I2C_ADDR_0); // Use FDC2214_I2C_ADDR_1 

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nFDC2x1x test");
  bool capOk = capsense.begin(0x3, 0x4, 0x5);  
  if (capOk) Serial.println("Sensor OK");  
  else Serial.println("Sensor Fail");  
}

void loop() {
  unsigned long X =capsense.getReading28(0);
    Serial.println(X);  
   
  
}

