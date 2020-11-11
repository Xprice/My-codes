void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   int i=9;   
   char *C=(char*)&i;  
   char c=*C;
  char buf[1];
  sprintf(buf,"%x",c);   //float to char 
  buf[0]=buf[0]-0x30;//int
   //********buf[0]=buf[0]  30 31 32 33 34
  Serial.write(buf[0]);
  delay(800);
}
