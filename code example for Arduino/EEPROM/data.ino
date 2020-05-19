void data()
{
    int i=0;
  for(int x=0;x<2;x++)
  {
    for(int y=0;y<4;y++)
    {
        EEPROM.write(i,a[x][y]);        
        //delay(3);  
        i++;           
    }
  }
 /* EEPROM.write(0,a[0][0]); 
  EEPROM.write(1,a[0][1]); */
  delay(4000);

  for(int i=0;i<8;i++)
  {
  Serial.write(EEPROM.read(i));  
 // delay(2);
  }
}
