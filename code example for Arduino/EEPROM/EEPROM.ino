byte a[2][4]={
    {0xff,0xfe,0xfd,0xfc},
    {0xfb,0xfa,0xf9,0xf8},
};
#include <EEPROM.h>
void setup()
{
  Serial.begin(9600);
//  data(); 
  EEPROM.write(32000,0.123);
}
void loop()
{

Serial.print(EEPROM.read(32000));
  //Serial.print(EEPROM.PageBase0, HEX);
  //Serial.println(EEPROM.PageBase1, HEX);
//  Serial.print(EEPROM.PageBase2, HEX);
//  Serial.print(EEPROM.PageBase3, HEX);
  //Serial.println(EEPROM.PageBase4, HEX);
//Serial.println(a[0][0]);
}
