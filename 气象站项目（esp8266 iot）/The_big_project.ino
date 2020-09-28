#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <dht11.h>

dht11 DHT11;
int gasSensor_D_0 = A1;
int soilHumidity_0 = A2;
int sensorPin = A3;
int sensorfire=A4;
int measurePin =A0;            
int ledPower = 4;     
float dustDensity = 0;   
int length;
int tonepin=5; 
int val=0;      


char auth[] = "2c0c629216114fe38fdf96327a7547e5";
char ssid[]="0315";
char pass[]="wt511355803";

#define EspSerial Serial

#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

#define PIN_UPTIMET V5
#define PIN_UPTIMEH V6
#define PIN_UPTIMEsh V7
#define PIN_UPTIMEgs V8
#define PIN_UPTIMEPM V9
#define PIN_UPTIMEG V10
#define PIN_UPTIMEFIRE V11

BlynkTimer timer;




void sendpm()
{
  unsigned int samplingTime = 280;
  unsigned int deltaTime = 40;
  unsigned int sleepTime = 9680;
  float voMeasured = 0;
  float calcVoltage = 0;
  digitalWrite(ledPower,LOW);
  delayMicroseconds(samplingTime);
  voMeasured = analogRead(measurePin);
  delayMicroseconds(deltaTime);
  digitalWrite(ledPower,HIGH);
  delayMicroseconds(sleepTime);
 //calcVoltage = voMeasured*(5.0/1024);
 //dustDensity = 0.17*calcVoltage-0.1;
  calcVoltage= voMeasured/1024-0.0356;
  dustDensity=calcVoltage*42;
  if ( dustDensity < 0)
  {
   dustDensity = 0.00;
  }
   Blynk.virtualWrite(PIN_UPTIMEPM,dustDensity);
}

void sendsensor()
{
  float sh=analogRead(soilHumidity_0);
  float gs=analogRead(gasSensor_D_0);
  int chk=DHT11.read(6);
  float temp = DHT11.temperature;
  float humi = DHT11.humidity;
  humi=humi/1024*100;
  float g=analogRead(sensorPin);
  sh=sh/1024*100;
  g=g/1024*100;
  Blynk.virtualWrite(PIN_UPTIMET,temp);
  Blynk.virtualWrite(PIN_UPTIMEH,humi);
  Blynk.virtualWrite(PIN_UPTIMEsh,sh);
  Blynk.virtualWrite(PIN_UPTIMEgs,gs);
  Blynk.virtualWrite(PIN_UPTIMEG,g);
}

void fireornot()
{
  //蜂鸣器乐谱
#define F -1
#define F1 350
#define F2 393
#define F2S 415
#define F3 441
#define F4 495
#define F5 556
#define F6 624
#define F7 661

#define FL1 175
#define FL2 196
#define FL3 221
#define FL4 234
#define FL4S 247
#define FL5 262
#define FL6 294
#define FL7 330

#define FH1 700
#define FH2 786
#define FH2S 830
#define FH3 882
#define FH4 935
#define FH4S 988
#define FH5 1049
#define FH6 1178
#define FH7 1322

#define FHH2 1568

int tune[]=       
{
  FL6,FL6,F6,F3,F2S,F,F2,F1,FL6,F1,F2,
  FL5,FL5,F6,F3,F2S,F,F2,F1,FL6,F1,F2,
  FL4S,FL4,F6,F3,F2S,F,F2,F1,FL6,F1,F2,
  FL4,FL4,F6,F3,F2S,F,F2,F1,FL6,F1,F2
};
float durt[]=                   
{
 0.25,0.25,0.5,0.75,0.25,0.25,0.5,0.5,0.25,0.25,0.25,
 0.25,0.25,0.5,0.75,0.25,0.25,0.5,0.5,0.25,0.25,0.25,
 0.25,0.25,0.5,0.75,0.25,0.25,0.5,0.5,0.25,0.25,0.25,
 0.25,0.25,0.5,0.75,0.25,0.25,0.5,0.5,0.25,0.25,0.25
};
  length=sizeof(tune)/sizeof(tune[0]); 
  
  if(analogRead(sensorfire)>=20)
  {
    String fireyes="有火";
    Blynk.virtualWrite(PIN_UPTIMEFIRE,fireyes);
    for(int x=0;x<length;x++)
  {
      tone(tonepin,tune[x]);
      delay(500*durt[x]); 
      noTone(tonepin);
  }
  }
  else
  {
    String fireno="无火";
    Blynk.virtualWrite(PIN_UPTIMEFIRE,fireno);
  }
}

void setup()
{
  Serial.begin(9600);

  delay(10);

  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass);
  pinMode(6,OUTPUT);
  pinMode(ledPower,OUTPUT);
  pinMode(tonepin,OUTPUT);
  timer.setInterval(1000L,sendpm);
  timer.setInterval(1000L,sendsensor);
  timer.setInterval(1000L,fireornot);
}

void loop()
{
  Blynk.run();
  timer.run();
}
