#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>
#define SET PA8       //切换模式   **PA8--10
#define TURN PA9      //翻页
#define REMOVE PA10   //删除
#define BUZZER PB0   //蜂鸣器
DHT dht11_0(PA0, DHT11);
LiquidCrystal_I2C lcd_0(0x27, 16, 2);
File myFile;
String T, H;
int Dline = 0;
unsigned int count = 0;
bool flag = false;
unsigned char buf[10][12];
char dat[10][12];

void setup() {
  Serial.begin(9600);
  pinMode(SET, INPUT_PULLUP);
  pinMode(TURN, INPUT_PULLUP);
  pinMode(REMOVE, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  attachInterrupt(SET, change, FALLING);
  dht11_0.begin();
  lcd_0.init();
  lcd_0.backlight();
  while (!SD.begin(PA4)) {                   //如果连接sd卡模块不成功
    //Serial.println("initialization failed!");
    lcd_0.setCursor(0, 0);
    lcd_0.print("  Check SDcard! ");
    lcd_0.setCursor(0, 1);
    lcd_0.print("   Or Reset!!!  ");
    buzzer(5);  //报警      请连接sd卡并 重启设备
  }
  //Serial.println("initialization done.");  //连接提示
  myFile = SD.open("T_H_DATA.txt");     //文件大于预定大小，删除文件
  delay(1);
  if (myFile.size() > 10000)
    SD.remove("T_H_DATA.txt");
  myFile.close();
  Initbuz();                //初始化完成,启动正常 连接提示
}
void loop() {
  T = (String)(int)dht11_0.readTemperature();
  H = (String)(int)dht11_0.readHumidity();

  lcd_0.setCursor(0, 0);                /*显示+写入数据模式     SD写*/
  lcd_0.print("   H&T Monitor   ");

  lcd_0.setCursor(0, 1);
  lcd_0.print(" Tem:");
  lcd_0.setCursor(5, 1);
  lcd_0.print(T);
  lcd_0.setCursor(7, 1);
  lcd_0.print("  ");
  lcd_0.setCursor(9, 1);
  lcd_0.print("Hum:");
  lcd_0.setCursor(13, 1);
  lcd_0.print(H);
  count++;
  //Serial.println("0");//test
  /* 隔固定次数写入 ↓↓↓↓↓↓↓ */
  while (count == 20) {
    String data = "T:" + T + "\tH:" + H; //12byte
    // Serial.println(sizeof(data));    //test
    myFile = SD.open("T_H_DATA.txt", FILE_WRITE); //隔固定时间数据保存至SD卡
    delay(1);
    if (myFile) {
      myFile.println(data);
      myFile.close();
      //Serial.println("000000000");  //test
    }
    else {
      lcd_0.setCursor(0, 0);
      lcd_0.print(" W EARRING!!!  ");
      buzzer(3);  //存入异常响应
      count = 0;
    }
    count = 0;
  }
  Dline = 0;
  /* 隔固定时间写入 ↑↑↑↑↑↑↑↑   */
  while (flag == true) {
    int choose = KEY();
    delay(20);
    switch (choose) {
      case 0: {
          lcd_0.setCursor(0, 0);
          lcd_0.print("1: ");
          lcd_0.setCursor(3, 0);
          lcd_0.print(dat[0]);
          lcd_0.setCursor(12, 0);
          lcd_0.print("    ");
          lcd_0.setCursor(0, 1);
          lcd_0.print("2: ");
          lcd_0.setCursor(3, 1);
          lcd_0.print(dat[1]);
          lcd_0.setCursor(12, 1);
          lcd_0.print("    ");
        } break;
      case 1: {
          lcd_0.setCursor(0, 0);
          lcd_0.print("3: ");
          lcd_0.setCursor(3, 0);
          lcd_0.print(dat[2]);
          lcd_0.setCursor(12, 0);
          lcd_0.print("    ");
          lcd_0.setCursor(0, 1);
          lcd_0.print("4: ");
          lcd_0.setCursor(3, 1);
          lcd_0.print(dat[3]);
          lcd_0.setCursor(12, 1);
          lcd_0.print("    ");
        } break;
      case 2: {
          lcd_0.setCursor(0, 0);
          lcd_0.print("5: ");
          lcd_0.setCursor(3, 0);
          lcd_0.print(dat[4]);
          lcd_0.setCursor(12, 0);
          lcd_0.print("    ");
          lcd_0.setCursor(0, 1);
          lcd_0.print("6: ");
          lcd_0.setCursor(3, 1);
          lcd_0.print(dat[5]);
          lcd_0.setCursor(12, 1);
          lcd_0.print("    ");
        } break;
      case 3: {
          lcd_0.setCursor(0, 0);
          lcd_0.print("7: ");
          lcd_0.setCursor(3, 0);
          lcd_0.print(dat[6]);
          lcd_0.setCursor(12, 0);
          lcd_0.print("    ");
          lcd_0.setCursor(0, 1);
          lcd_0.print("8: ");
          lcd_0.setCursor(3, 1);
          lcd_0.print(dat[7]);
          lcd_0.setCursor(12, 1);
          lcd_0.print("    ");
        } break;
      case 4: {
          lcd_0.setCursor(0, 0);
          lcd_0.print("9: ");
          lcd_0.setCursor(3, 0);
          lcd_0.print(dat[8]);
          lcd_0.setCursor(12, 0);
          lcd_0.print("    ");
          lcd_0.setCursor(0, 1);
          lcd_0.print("10:");
          lcd_0.setCursor(3, 1);
          lcd_0.print(dat[9]);
          lcd_0.setCursor(12, 1);
          lcd_0.print("    ");
        } break;
      case 7: {
          lcd_0.setCursor(0, 0);
          lcd_0.print("Delate Success!!!");
          lcd_0.setCursor(0, 1);
          lcd_0.print("------------------");
          buzzer(1);// 删除成功提示
          delay(800);
          lcd_0.clear();
          flag = false;
        } break;
    }
  }
}
int KEY() {
  if (digitalRead(TURN) == LOW)
  {
    delay(20);   //延时消抖
    if (digitalRead(TURN) == LOW)
    {
      Dline++;
      if (Dline == 5) {
        Dline = 0;
      }
    }
    while (digitalRead(TURN) == LOW);
  }
  else if (digitalRead(REMOVE) == LOW) //检测到REMOVE时
  {
    delay(20);
    if (digitalRead(REMOVE) == LOW)
    {
      SD.remove("T_H_DATA.txt");
      Dline = 7;
    }
    while (digitalRead(REMOVE) == LOW);
  }
  return Dline;
}
void change() {
  if (digitalRead(SET) == LOW) {
    delay(60);
    if (digitalRead(SET) == LOW) {
      if (flag == true) {
        flag = !flag;
      }
      else {
        myFile = SD.open("T_H_DATA.txt", FILE_WRITE);                     /*读数据进大数组并分割为小数组*/
        delay(1);
        unsigned long pt = myFile.position();
        myFile.seek(pt - 110);
        if (myFile) {
          for (int i = 0; i < 10; i++) {
            if (myFile.available()) {
              myFile.read(buf[i], 11);
              delay(1);
              // Serial.write(buf[i], 11);     //串口显示读到的数据
              // Serial.println();
              // Serial.println(i);
            }
          }
          myFile.close();
          for (int a = 0; a < 10; a++) {
            for (int b = 0; b < 9; b++) {   //12-3=9抛弃无用位，优化显示
              if (buf[a][b] == '\t') {
                buf[a][b] = ' ';
              }
              dat[a][b] = buf[a][b];
              delay(1);
            }
            //Serial.print(dat[a]);

          }
        }
        else {
          lcd_0.setCursor(0, 0);
          lcd_0.print(" R EARRING!!!  ");
          buzzer(3); //读不到数据报警
        }
        flag = !flag;
      }
    }
   while (digitalRead(SET) == LOW);
   }
}
void buzzer(int i) {
  for (int t = 0; t < i; t++) {
    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(BUZZER, LOW);
    delay(300);
  }
}
void Initbuz() {
  digitalWrite(BUZZER, HIGH);
  delay(1000);
  digitalWrite(BUZZER, LOW);
}
