#include <EEPROM.h>
#define SET 4    //set/exit   **PA4--7
#define UP 5     //⬆
#define DOWN 6   //⬇
#define ENTER 7  //enter
byte mcunum, num;
char data[14] = {0}; //探头返回数组
int NUM[6];
byte N, N1, N2, N3, N4; //N:mcunum  N1,N2,N3,N4:探头num
byte BH1, BH2, BH3, BH4, LC1, LC2, LC3, LC4;
byte N1SJ1, N1SJ2, N1SJ3, N1SJ4, N1SJ5, N1SJ6, N1SJ7, N1SJ8, N1SJ9, N1SJ10, N1SJ11, N1SJ12, N1SJ13, N1SJ14, N1SJ15, N1SJ16, N1SJ17, N1SJ18, N1SJ19, N1SJ20, N1SJ21, N1SJ22;
byte N2SJ1, N2SJ2, N2SJ3, N2SJ4, N2SJ5, N2SJ6, N2SJ7, N2SJ8, N2SJ9, N2SJ10, N2SJ11, N2SJ12, N2SJ13, N2SJ14, N2SJ15, N2SJ16, N2SJ17, N2SJ18, N2SJ19, N2SJ20, N2SJ21, N2SJ22;
byte N3SJ1, N3SJ2, N3SJ3, N3SJ4, N3SJ5, N3SJ6, N3SJ7, N3SJ8, N3SJ9, N3SJ10, N3SJ11, N3SJ12, N3SJ13, N3SJ14, N3SJ15, N3SJ16, N3SJ17, N3SJ18, N3SJ19, N3SJ20, N3SJ21, N3SJ22;
byte N4SJ1, N4SJ2, N4SJ3, N4SJ4, N4SJ5, N4SJ6, N4SJ7, N4SJ8, N4SJ9, N4SJ10, N4SJ11, N4SJ12, N4SJ13, N4SJ14, N4SJ15, N4SJ16, N4SJ17, N4SJ18, N4SJ19, N4SJ20, N4SJ21, N4SJ22;

byte N1com1[9][6] =
{
  {0XFE, 0X05, mcunum, num, 0X02},    //读单位(显示hz或者cps)
  {0XFE, 0X05, mcunum, num, 0X08},    //读射线类型
  {0XFE, 0X05, mcunum, num, 0X07},    //读编号
  {0XFE, 0X05, mcunum, num, 0X00},    //读转化前的数据/原始数据
  {0XFE, 0X05, mcunum, num, 0X01},    //读转化后的数据/实时数据
  {0XFE, 0X05, mcunum, num, 0X03},    //读失效阈值
  {0XFE, 0X05, mcunum, num, 0X05},    //读校准时间
  {0XFE, 0X05, mcunum, num, 0X60},    //切换到用户状态
  {},
};
byte N1com2[13][7] =
{
  {0XFE, 0X06, mcunum, num, 0X04, 0X03}, //读低报警项
  {0XFE, 0X06, mcunum, num, 0X04, 0X01}, //读第一报警
  {0XFE, 0X06, mcunum, num, 0X04, 0X02}, //读第二报警
  {0XFE, 0X06, mcunum, num, 0X61, 0X01}, //切换到工厂状态
  {0XFE, 0X06, mcunum, num, 0X21, 0X01}, //读死时间

  {0XFE, 0X06, mcunum, num, 0X12, 0X01}, //写单位hz
  {0XFE, 0X06, mcunum, num, 0X12, 0X02}, //写单位usv
  {0XFE, 0X06, mcunum, num, 0X12, 0X03}, //写单位ugy
  {0XFE, 0X06, mcunum, num, 0X12, 0X04}, //写单位mrh
  {0XFE, 0X06, mcunum, num, 0X18, 0X01}, //写射线类型X
  {0XFE, 0X06, mcunum, num, 0X18, 0X02}, //写射线类型N
  {0XFE, 0X06, mcunum, num, 0X18, 0X03}, //写射线类型γ
};
byte N1com3[7] = {0XFE, 0X06, mcunum, num, 0X17/*,0X00-FF*/}; //写探头编号****** 1组数据0-255编号
byte N1com4[5][7] =
{
  {0XFE, 0X06, mcunum, num, 0X24/*,0X01-06*/}, //读上下限    ******量程1-6
  {0XFE, 0X06, mcunum, num, 0X20/*,0X01-06*/}, //读本底（本地数为0.00）
  {0XFE, 0X06, mcunum, num, 0X22/*,0X01-06*/}, //读灵敏度
  {0XFE, 0X06, mcunum, num, 0X21/*,0X01-06*/}, //读死时间
};
byte N1com5[3][10] =
{
  {0XFE, 0X09, mcunum, num, 0X13/*,0X00-FF*4组*/}, //写失效阈值     ****** 4组数据
  {0XFE, 0X09, mcunum, num, 0X15/*,0X00-FF*4组*/}, //写校准时间
};

byte N1com6[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X14, 0X01/*,0X00-FF*4组*/}, //写第一报警  ******* 4组数据
  {0XFE, 0X0A, mcunum, num, 0X14, 0X02/*,0X00-FF*4组*/}, //写第二报警
  {0XFE, 0X0A, mcunum, num, 0X14, 0X03/*,0X00-FF*4组*/}, //写低报警
};
byte N1com7[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X20/*0X01-060X00-FF*4组*/}, //写本底   *******量程1-6+++4组数据
  {0XFE, 0X0A, mcunum, num, 0X32/*0X01-060X00-FF*4组*/}, //写灵敏度
  {0XFE, 0X0A, mcunum, num, 0X31/*0X01-060X00-FF*4组*/}, //写死时间
};
byte N1com8[16] = {0XFE, 0X0E, mcunum, num, 0X20/*,0X01-06*//*,0X00-FF*8组*/}; //写上下限   **** 量程1-6++++8组数据

byte N2com1[9][6] =
{
  {0XFE, 0X05, mcunum, num, 0X02},    //读单位(显示hz或者cps)
  {0XFE, 0X05, mcunum, num, 0X08},    //读射线类型
  {0XFE, 0X05, mcunum, num, 0X07},    //读编号
  {0XFE, 0X05, mcunum, num, 0X00},    //读转化前的数据/原始数据
  {0XFE, 0X05, mcunum, num, 0X01},    //读转化后的数据/实时数据
  {0XFE, 0X05, mcunum, num, 0X03},    //读失效阈值
  {0XFE, 0X05, mcunum, num, 0X05},    //读校准时间
  {0XFE, 0X05, mcunum, num, 0X60},    //切换到用户状态
  {},
};
byte N2com2[13][7] =
{
  {0XFE, 0X06, mcunum, num, 0X04, 0X03}, //读低报警项
  {0XFE, 0X06, mcunum, num, 0X04, 0X01}, //读第一报警
  {0XFE, 0X06, mcunum, num, 0X04, 0X02}, //读第二报警
  {0XFE, 0X06, mcunum, num, 0X61, 0X01}, //切换到工厂状态
  {0XFE, 0X06, mcunum, num, 0X21, 0X01}, //读死时间

  {0XFE, 0X06, mcunum, num, 0X12, 0X01}, //写单位hz
  {0XFE, 0X06, mcunum, num, 0X12, 0X02}, //写单位usv
  {0XFE, 0X06, mcunum, num, 0X12, 0X03}, //写单位ugy
  {0XFE, 0X06, mcunum, num, 0X12, 0X04}, //写单位mrh
  {0XFE, 0X06, mcunum, num, 0X18, 0X01}, //写射线类型X
  {0XFE, 0X06, mcunum, num, 0X18, 0X02}, //写射线类型N
  {0XFE, 0X06, mcunum, num, 0X18, 0X03}, //写射线类型γ
};
byte N2com3[7] = {0XFE, 0X06, mcunum, num, 0X17/*,0X00-FF*/}; //写探头编号****** 1组数据0-255编号
byte N2com4[5][7] =
{
  {0XFE, 0X06, mcunum, num, 0X24/*,0X01-06*/}, //读上下限    ******量程1-6
  {0XFE, 0X06, mcunum, num, 0X20/*,0X01-06*/}, //读本底（本地数为0.00）
  {0XFE, 0X06, mcunum, num, 0X22/*,0X01-06*/}, //读灵敏度
  {0XFE, 0X06, mcunum, num, 0X21/*,0X01-06*/}, //读死时间
};
byte N2com5[3][10] =
{
  {0XFE, 0X09, mcunum, num, 0X13/*,0X00-FF*4组*/}, //写失效阈值     ****** 4组数据
  {0XFE, 0X09, mcunum, num, 0X15/*,0X00-FF*4组*/}, //写校准时间
};
byte N2com6[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X14, 0X01/*,0X00-FF*4组*/}, //写第一报警  ******* 4组数据
  {0XFE, 0X0A, mcunum, num, 0X14, 0X02/*,0X00-FF*4组*/}, //写第二报警
  {0XFE, 0X0A, mcunum, num, 0X14, 0X03/*,0X00-FF*4组*/}, //写低报警
};
byte N2com7[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X20/*0X01-060X00-FF*4组*/}, //写本底   *******量程1-6+++4组数据
  {0XFE, 0X0A, mcunum, num, 0X32/*0X01-060X00-FF*4组*/}, //写灵敏度
  {0XFE, 0X0A, mcunum, num, 0X31/*0X01-060X00-FF*4组*/}, //写死时间
};
byte N2com8[16] = {0XFE, 0X0E, mcunum, num, 0X20/*,0X01-06*//*,0X00-FF*8组*/}; //写上下限   **** 量程1-6++++8组数据

byte N3com1[9][6] =
{
  {0XFE, 0X05, mcunum, num, 0X02},    //读单位(显示hz或者cps)
  {0XFE, 0X05, mcunum, num, 0X08},    //读射线类型
  {0XFE, 0X05, mcunum, num, 0X07},    //读编号
  {0XFE, 0X05, mcunum, num, 0X00},    //读转化前的数据/原始数据
  {0XFE, 0X05, mcunum, num, 0X01},    //读转化后的数据/实时数据
  {0XFE, 0X05, mcunum, num, 0X03},    //读失效阈值
  {0XFE, 0X05, mcunum, num, 0X05},    //读校准时间
  {0XFE, 0X05, mcunum, num, 0X60},    //切换到用户状态
  {},
};
byte N3com2[13][7] =
{
  {0XFE, 0X06, mcunum, num, 0X04, 0X03}, //读低报警项
  {0XFE, 0X06, mcunum, num, 0X04, 0X01}, //读第一报警
  {0XFE, 0X06, mcunum, num, 0X04, 0X02}, //读第二报警
  {0XFE, 0X06, mcunum, num, 0X61, 0X01}, //切换到工厂状态
  {0XFE, 0X06, mcunum, num, 0X21, 0X01}, //读死时间

  {0XFE, 0X06, mcunum, num, 0X12, 0X01}, //写单位hz
  {0XFE, 0X06, mcunum, num, 0X12, 0X02}, //写单位usv
  {0XFE, 0X06, mcunum, num, 0X12, 0X03}, //写单位ugy
  {0XFE, 0X06, mcunum, num, 0X12, 0X04}, //写单位mrh
  {0XFE, 0X06, mcunum, num, 0X18, 0X01}, //写射线类型X
  {0XFE, 0X06, mcunum, num, 0X18, 0X02}, //写射线类型N
  {0XFE, 0X06, mcunum, num, 0X18, 0X03}, //写射线类型γ
};
byte N3com3[7] = {0XFE, 0X06, mcunum, num, 0X17/*,0X00-FF*/}; //写探头编号****** 1组数据0-255编号
byte N3com4[5][7] =
{
  {0XFE, 0X06, mcunum, num, 0X24/*,0X01-06*/}, //读上下限    ******量程1-6
  {0XFE, 0X06, mcunum, num, 0X20/*,0X01-06*/}, //读本底（本地数为0.00）
  {0XFE, 0X06, mcunum, num, 0X22/*,0X01-06*/}, //读灵敏度
  {0XFE, 0X06, mcunum, num, 0X21/*,0X01-06*/}, //读死时间
};
byte N3com5[3][10] =
{
  {0XFE, 0X09, mcunum, num, 0X13/*,0X00-FF*4组*/}, //写失效阈值     ****** 4组数据
  {0XFE, 0X09, mcunum, num, 0X15/*,0X00-FF*4组*/}, //写校准时间
};
byte N3com6[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X14, 0X01/*,0X00-FF*4组*/}, //写第一报警  ******* 4组数据
  {0XFE, 0X0A, mcunum, num, 0X14, 0X02/*,0X00-FF*4组*/}, //写第二报警
  {0XFE, 0X0A, mcunum, num, 0X14, 0X03/*,0X00-FF*4组*/}, //写低报警
};
byte N3com7[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X20/*0X01-060X00-FF*4组*/}, //写本底   *******量程1-6+++4组数据
  {0XFE, 0X0A, mcunum, num, 0X32/*0X01-060X00-FF*4组*/}, //写灵敏度
  {0XFE, 0X0A, mcunum, num, 0X31/*0X01-060X00-FF*4组*/}, //写死时间
};
byte N3com8[16] = {0XFE, 0X0E, mcunum, num, 0X20/*,0X01-06*//*,0X00-FF*8组*/}; //写上下限   **** 量程1-6++++8组数据

byte N4com1[9][6] =
{
  {0XFE, 0X05, mcunum, num, 0X02},    //读单位(显示hz或者cps)
  {0XFE, 0X05, mcunum, num, 0X08},    //读射线类型
  {0XFE, 0X05, mcunum, num, 0X07},    //读编号
  {0XFE, 0X05, mcunum, num, 0X00},    //读转化前的数据/原始数据
  {0XFE, 0X05, mcunum, num, 0X01},    //读转化后的数据/实时数据
  {0XFE, 0X05, mcunum, num, 0X03},    //读失效阈值
  {0XFE, 0X05, mcunum, num, 0X05},    //读校准时间
  {0XFE, 0X05, mcunum, num, 0X60},    //切换到用户状态
  {},
};
byte N4com2[13][7] =
{
  {0XFE, 0X06, mcunum, num, 0X04, 0X03}, //读低报警项
  {0XFE, 0X06, mcunum, num, 0X04, 0X01}, //读第一报警
  {0XFE, 0X06, mcunum, num, 0X04, 0X02}, //读第二报警
  {0XFE, 0X06, mcunum, num, 0X61, 0X01}, //切换到工厂状态
  {0XFE, 0X06, mcunum, num, 0X21, 0X01}, //读死时间

  {0XFE, 0X06, mcunum, num, 0X12, 0X01}, //写单位hz
  {0XFE, 0X06, mcunum, num, 0X12, 0X02}, //写单位usv
  {0XFE, 0X06, mcunum, num, 0X12, 0X03}, //写单位ugy
  {0XFE, 0X06, mcunum, num, 0X12, 0X04}, //写单位mrh
  {0XFE, 0X06, mcunum, num, 0X18, 0X01}, //写射线类型X
  {0XFE, 0X06, mcunum, num, 0X18, 0X02}, //写射线类型N
  {0XFE, 0X06, mcunum, num, 0X18, 0X03}, //写射线类型γ
};
byte N4com3[7] = {0XFE, 0X06, mcunum, num, 0X17/*,0X00-FF*/}; //写探头编号****** 1组数据0-255编号
byte N4com4[5][7] =
{
  {0XFE, 0X06, mcunum, num, 0X24/*,0X01-06*/}, //读上下限    ******量程1-6
  {0XFE, 0X06, mcunum, num, 0X20/*,0X01-06*/}, //读本底（本地数为0.00）
  {0XFE, 0X06, mcunum, num, 0X22/*,0X01-06*/}, //读灵敏度
  {0XFE, 0X06, mcunum, num, 0X21/*,0X01-06*/}, //读死时间
};
byte N4com5[3][10] =
{
  {0XFE, 0X09, mcunum, num, 0X13/*,0X00-FF*4组*/}, //写失效阈值     ****** 4组数据
  {0XFE, 0X09, mcunum, num, 0X15/*,0X00-FF*4组*/}, //写校准时间
};
byte N4com6[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X14, 0X01/*,0X00-FF*4组*/}, //写第一报警  ******* 4组数据
  {0XFE, 0X0A, mcunum, num, 0X14, 0X02/*,0X00-FF*4组*/}, //写第二报警
  {0XFE, 0X0A, mcunum, num, 0X14, 0X03/*,0X00-FF*4组*/}, //写低报警
};
byte N4com7[4][11] =
{
  {0XFE, 0X0A, mcunum, num, 0X20/*0X01-060X00-FF*4组*/}, //写本底   *******量程1-6+++4组数据
  {0XFE, 0X0A, mcunum, num, 0X32/*0X01-060X00-FF*4组*/}, //写灵敏度
  {0XFE, 0X0A, mcunum, num, 0X31/*0X01-060X00-FF*4组*/}, //写死时间
};
byte N4com8[16] = {0XFE, 0X0E, mcunum, num, 0X20/*,0X01-06*//*,0X00-FF*8组*/}; //写上下限   **** 量程1-6++++8组数据

void setup()
{
  Serial.begin(115200);
  Serial1.begin(9600);  //TX=PA9,RX=PA10
  Serial2.begin(9600);  //TX=PA2,RX=PA3
  Serial3.begin(115200);  //TX=PB10,RX=PB11
  pinMode(SET, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(ENTER, INPUT_PULLUP);
}
void loop()
{ 
  N = 0XFF; N1 = 0X0C; N2 = 0X0C; N3 = 0X0C; N4 = 0X0C;
  /* //正在开机
    N = EEPROM.read(0); //主机编号

    N1 = EEPROM.read(1); BH1 = EEPROM.read(2); LC1 = EEPROM.read(3);
    N1SJ1 = EEPROM.read(20); N1SJ2 = EEPROM.read(21); N1SJ3 = EEPROM.read(22); N1SJ4 = EEPROM.read(23); N1SJ5 = EEPROM.read(24); N1SJ6 = EEPROM.read(25); N1SJ7 = EEPROM.read(26); N1SJ8 = EEPROM.read(27);
    N1SJ9 = EEPROM.read(28); N1SJ10 = EEPROM.read(29); N1SJ11 = EEPROM.read(30); N1SJ12 = EEPROM.read(31); N1SJ13 = EEPROM.read(32); N1SJ14 = EEPROM.read(33); N1SJ15 = EEPROM.read(34);
    N1SJ16 = EEPROM.read(35); N1SJ17 = EEPROM.read(36); N1SJ18 = EEPROM.read(37); N1SJ19 = EEPROM.read(38); N1SJ20 = EEPROM.read(39); N1SJ21 = EEPROM.read(40); N1SJ22 = EEPROM.read(41);
    //开机15%
    N2 = EEPROM.read(4); BH2 = EEPROM.read(5); LC2 = EEPROM.read(6);
    N2SJ1 = EEPROM.read(50); N2SJ2 = EEPROM.read(51); N2SJ3 = EEPROM.read(52); N2SJ4 = EEPROM.read(53); N2SJ5 = EEPROM.read(54); N2SJ6 = EEPROM.read(55); N2SJ7 = EEPROM.read(56); N2SJ8 = EEPROM.read(57);
    N2SJ9 = EEPROM.read(58); N2SJ10 = EEPROM.read(59); N2SJ11 = EEPROM.read(60); N2SJ12 = EEPROM.read(61); N2SJ13 = EEPROM.read(62); N2SJ14 = EEPROM.read(63); N2SJ15 = EEPROM.read(64);
    N2SJ16 = EEPROM.read(65); N2SJ17 = EEPROM.read(66); N2SJ18 = EEPROM.read(67); N2SJ19 = EEPROM.read(68); N2SJ20 = EEPROM.read(69); N2SJ21 = EEPROM.read(70); N2SJ22 = EEPROM.read(71);
    //开机30%
    N3 = EEPROM.read(7); BH3 = EEPROM.read(8); LC3 = EEPROM.read(9);
    N3SJ1 = EEPROM.read(80); N3SJ2 = EEPROM.read(81); N3SJ3 = EEPROM.read(82); N3SJ4 = EEPROM.read(83); N3SJ5 = EEPROM.read(84); N3SJ6 = EEPROM.read(85); N3SJ7 = EEPROM.read(86); N3SJ8 = EEPROM.read(87);
    N3SJ9 = EEPROM.read(88); N3SJ10 = EEPROM.read(89); N3SJ11 = EEPROM.read(90); N3SJ12 = EEPROM.read(91); N3SJ13 = EEPROM.read(92); N3SJ14 = EEPROM.read(93); N3SJ15 = EEPROM.read(94);
    N3SJ16 = EEPROM.read(95); N3SJ17 = EEPROM.read(96); N3SJ18 = EEPROM.read(97); N3SJ19 = EEPROM.read(98); N3SJ20 = EEPROM.read(99); N3SJ21 = EEPROM.read(100); N3SJ22 = EEPROM.read(101);
    //开机45%
    N4 = EEPROM.read(10); BH4 = EEPROM.read(11); LC4 = EEPROM.read(12);
    N4SJ1 = EEPROM.read(110); N4SJ2 = EEPROM.read(111); N4SJ3 = EEPROM.read(112); N4SJ4 = EEPROM.read(113); N4SJ5 = EEPROM.read(114); N4SJ6 = EEPROM.read(115); N4SJ7 = EEPROM.read(116); N4SJ8 = EEPROM.read(117);
    N4SJ9 = EEPROM.read(118); N4SJ10 = EEPROM.read(119); N4SJ11 = EEPROM.read(120); N4SJ12 = EEPROM.read(121); N4SJ13 = EEPROM.read(122); N4SJ14 = EEPROM.read(123); N4SJ15 = EEPROM.read(124);
    N4SJ16 = EEPROM.read(125); N4SJ17 = EEPROM.read(126); N4SJ18 = EEPROM.read(127); N4SJ19 = EEPROM.read(128); N4SJ20 = EEPROM.read(129); N4SJ21 = EEPROM.read(130); N4SJ22 = EEPROM.read(131);
    //开机65%
  */
  N1BCC12(N, N1); N1BCC3(N, N1, BH1); N1BCC4(N, N1, LC1); N1BCC5(N, N1, N1SJ1, N1SJ2, N1SJ3, N1SJ4); N1BCC6(N, N1, N1SJ5, N1SJ6, N1SJ7, N1SJ8); N1BCC7(N, N1, N1SJ9, N1SJ10, N1SJ11, N1SJ12, N1SJ13); N1BCC8(N, N1, N1SJ14, N1SJ15, N1SJ16, N1SJ17, N1SJ18, N1SJ19, N1SJ20, N1SJ21, N1SJ22);
  N2BCC12(N, N2); N2BCC3(N, N2, BH1); N2BCC4(N, N2, LC1); N2BCC5(N, N2, N2SJ1, N2SJ2, N2SJ3, N2SJ4); N2BCC6(N, N2, N2SJ5, N2SJ6, N2SJ7, N2SJ8); N2BCC7(N, N2, N2SJ9, N2SJ10, N2SJ11, N2SJ12, N2SJ13); N2BCC8(N, N2, N2SJ14, N2SJ15, N2SJ16, N2SJ17, N2SJ18, N2SJ19, N2SJ20, N2SJ21, N2SJ22);
  N3BCC12(N, N3); N3BCC3(N, N3, BH1); N3BCC4(N, N3, LC1); N3BCC5(N, N3, N3SJ1, N3SJ2, N3SJ3, N3SJ4); N3BCC6(N, N3, N3SJ5, N3SJ6, N3SJ7, N3SJ8); N3BCC7(N, N3, N3SJ9, N3SJ10, N3SJ11, N3SJ12, N3SJ13); N3BCC8(N, N3, N3SJ14, N3SJ15, N3SJ16, N3SJ17, N3SJ18, N3SJ19, N3SJ20, N3SJ21, N3SJ22);
  N4BCC12(N, N4); N4BCC3(N, N4, BH1); N4BCC4(N, N4, LC1); N4BCC5(N, N4, N4SJ1, N4SJ2, N4SJ3, N4SJ4); N4BCC6(N, N4, N4SJ5, N4SJ6, N4SJ7, N4SJ8); N4BCC7(N, N4, N4SJ9, N4SJ10, N4SJ11, N4SJ12, N4SJ13); N4BCC8(N, N4, N4SJ14, N4SJ15, N4SJ16, N4SJ17, N4SJ18, N4SJ19, N4SJ20, N4SJ21, N4SJ22);
  //delay();
  //开机100%  切换到2号图
  while (1)
  {
    Serial1.write(&N1com1[4], 6); //读实时数据
    delay(5);
    Serial1.readBytes(data, 14);
    char t1 = data[5];
    char s1 = data[6];
    //upstr();LCD显示data里的数据   5温度   6状态  7量程  8单位  9&10&11&12为实时数据DATA
    //将此时的数据放入flash缓存为历史数据
    updata(0X01, 0x0D, data);
    uptem(0X01, 0x2D, t1);
    upstate(0X01, 0X34, s1);
    SwitchingSC(0X01);

    Serial1.write(&N2com1[4], 6); //读实时数据
    delay(5);
    Serial1.readBytes(data, 14);
    char t2 = data[5];
    char s2 = data[6];
    //upstr();LCD显示data里的数据   5温度   6状态  7量程  8单位  9&10&11&12为实时数据
    //将此时的数据放入flash缓存为历史数据
    updata(0X01, 0x0A, data);
    uptem(0X01, 0x22, t2);
    upstate(0X01, 0X33, s2);

    Serial1.write(&N3com1[4], 6); //读实时数据
    delay(5);
    Serial1.readBytes(data, 14);
    char t3 = data[5];
    char s3 = data[6];
    //upstr();LCD显示data里的数据   5温度   6状态  7量程  8单位  9&10&11&12为实时数据
    //将此时的数据放入flash缓存为历史数据
    updata(0X01, 0x10, data);
    uptem(0X01, 0x2E, t3);
    upstate(0X01, 0X2A, s3);

    Serial1.write(&N4com1[4], 6); //读实时数据
    delay(5);
    Serial1.readBytes(data, 14);
    char t4 = data[5];
    char s4 = data[6];
    //upstr();LCD显示data里的数据   5温度   6状态  7量程  8单位  9&10&11&12为实时数据
    //将此时的数据放入flash缓存为历史数据
    updata(0X01, 0x32, data);
    uptem(0X01, 0x2F, t4);
    upstate(0X01, 0X13, s4);

    if (digitalRead(SET) == LOW)
    {
      delay(50);
      if (digitalRead(SET) == LOW)
      {
        int key[3];
        blankR(0X02,0X0B);
        blankR(0X02,0X0C);
        blankR(0X02,0X0D);
        upchar(0X02, 0X08, 0);
        upchar(0X02, 0X09, 0);
        upchar(0X02, 0X0A, 0);
        
        SwitchingSC(0X02);//显示在屏幕上
        //屏幕上第一位实时显示i
        upR(0X02,0X0B);
        key[0] = KEYIN(0X02, 0X08); //第一位确定
        delay(200);
        blankR(0X02,0X0B);
        upR(0X02,0X0C);
        //屏幕上第二位实时显示i
        key[1] = KEYIN(0X02, 0X09); //第二位确定
        //屏幕上第三位实时显示i的值
        delay(200);
        blankR(0X02,0X0C);
        upR(0X02,0X0D);
        key[2] = KEYIN(0X02, 0X0A); //第三位确定
        delay(200);
        blankR(0X02,0X0D);
        if (key[0] == 1 && key[1] == 1 && key[2] == 1) //用户模式
        {
          USERSET();
        }
        else if (key[0] == 9 && key[1] == 9 && key[2] == 9) //工厂模式
        {
          ADMINSET();
        }
        else
        {
          SwitchingSC(0X03);//切换显示密码错误界面
        }
      }
    }
  }
}

//Serial1.write(&command1[0],6);//读单位
// delay(10);
// Serial1.readBytes(data,7);
//Serial.write(&data[0],7);
