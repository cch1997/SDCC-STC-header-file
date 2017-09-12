#ifndef __my_STC12C5A60S2_H_
#define __my_STC12C5A60S2_H_

/////////////////////////////////////////////////

//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ���ں����⹦�ܼĴ��� C51 Core SFRs
//                                          7     6      5       4     3    2    1     0   Reset Value
__sfr __at 0xE0 ACC; //Accumulator                                                              0000,0000
__sfr __at 0xF0 B; //B Register                                                               0000,0000
__sfr __at 0xD0 PSW; //Program Status Word      CY    AC    F0    RS1   RS0    OV    F1    P    0000,0000
//-----------------------------------
__sbit __at 0xD7 CY;
__sbit __at 0xD6 AC;
__sbit __at 0xD5 F0;
__sbit __at 0xD4 RS1;
__sbit __at 0xD3 RS0;
__sbit __at 0xD2 OV;
__sbit __at 0xD0 P;
//-----------------------------------
__sfr __at 0x81 SP; //Stack Pointer                                                            0000,0111
__sfr __at 0x82 DPL; //Data Pointer Low Byte                                                    0000,0000
__sfr __at 0x83 DPH; //Data Pointer High Byte                                                   0000,0000
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ��ϵͳ�������⹦�ܼĴ���
//                                          7     6      5    4     3      2    1     0     Reset Value
__sfr __at 0x87 PCON; //Power Control        SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000
//                                        7     6       5      4     3      2      1      0   Reset Value
__sfr __at 0x8E AUXR; //Auxiliary Register  T0x12 T1x12 UART_M0x6 BRTR S2SMOD BRTx12 EXTRAM S1BRS  0000,0000
//-----------------------------------
__sfr __at 0xA2 AUXR1; //Auxiliary Register 1  -  PCA_P4  SPI_P4  S2_P4  GF2    ADRJ   -    DPS  0000,0000
/*
PCA_P4:
    0, ȱʡPCA ��P1 ��
    1��PCA/PWM ��P1 ���л���P4 ��: ECI ��P1.2 �л���P4.1 �ڣ�
                                   PCA0/PWM0 ��P1.3 �л���P4.2 ��
                                   PCA1/PWM1 ��P1.4 �л���P4.3 ��
SPI_P4:
    0, ȱʡSPI ��P1 ��
    1��SPI ��P1 ���л���P4 ��: SPICLK ��P1.7 �л���P4.3 ��
                               MISO ��P1.6 �л���P4.2 ��
                               MOSI ��P1.5 �л���P4.1 ��
                               SS ��P1.4 �л���P4.0 ��
S2_P4: 
    0, ȱʡUART2 ��P1 ��
    1��UART2 ��P1 ���л���P4 ��: TxD2 ��P1.3 �л���P4.3 ��
                                 RxD2 ��P1.2 �л���P4.2 ��
GF2: ͨ�ñ�־λ

ADRJ:
    0, 10 λA/D ת������ĸ�8 λ����ADC_RES �Ĵ���, ��2 λ����ADC_RESL �Ĵ���
    1��10 λA/D ת����������2 λ����ADC_RES �Ĵ����ĵ�2 λ, ��8 λ����ADC_RESL �Ĵ���

DPS: 0, ʹ��ȱʡ����ָ��DPTR0
     1��ʹ����һ������ָ��DPTR1
*/
//-----------------------------------
__sfr __at 0x8F WAKE_CLKO; //���ӵ� __sfr __at WAK1_CLKO
/*
      7            6          5          4          3       2       1      0         Reset Value
   PCAWAKEUP  RXD_PIN_IE  T1_PIN_IE  T0_PIN_IE  LVD_WAKE    _    T1CLKO  T0CLKO      0000,0000B

b7 - PCAWAKEUP : PCA �жϿɻ��� powerdown��
b6 - RXD_PIN_IE : �� P3.0(RXD) �½�����λ RI ʱ�ɻ��� powerdown(�������Ӧ�ж�)��
b5 - T1_PIN_IE : �� T1 ���½�����λ T1 �жϱ�־ʱ�ɻ��� powerdown(�������Ӧ�ж�)��
b4 - T0_PIN_IE : �� T0 ���½�����λ T0 �жϱ�־ʱ�ɻ��� powerdown(�������Ӧ�ж�)��
b3 - LVD_WAKE : �� CMPIN �ŵ͵�ƽ��λ LVD �жϱ�־ʱ�ɻ��� powerdown(�������Ӧ�ж�)��
b2 - 
b1 - T1CLKO : ���� T1CKO(P3.5) ����� T1 ������壬Fck1 = 1/2 T1 �����
b0 - T0CLKO : ���� T0CKO(P3.4) ����� T0 ������壬Fck0 = 1/2 T1 �����
*/
//-----------------------------------
__sfr __at 0x97 CLK_DIV; //Clock Divder          -     -      -       -     -  CLKS2 CLKS1 CLKS0 xxxx,x000
//-----------------------------------
__sfr __at 0xA1 BUS_SPEED; //Stretch register      -     -    ALES1   ALES0   -   RWS2  RWS1  RWS0 xx10,x011
/*
ALES1 and ALES0:
00 : The P0 address setup time and hold time to ALE negative edge is one clock cycle
01 : The P0 address setup time and hold time to ALE negative edge is two clock cycles.
10 : The P0 address setup time and hold time to ALE negative edge is three clock cycles. (default)
11 : The P0 address setup time and hold time to ALE negative edge is four clock cycles.

RWS2,RWS1,RWS0:
  000 : The MOVX read/write pulse is 1 clock cycle. 
  001 : The MOVX read/write pulse is 2 clock cycles.
  010 : The MOVX read/write pulse is 3 clock cycles.
  011 : The MOVX read/write pulse is 4 clock cycles. (default)
  100 : The MOVX read/write pulse is 5 clock cycles.
  101 : The MOVX read/write pulse is 6 clock cycles.
  110 : The MOVX read/write pulse is 7 clock cycles.
  111 : The MOVX read/write pulse is 8 clock cycles.
*/
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ���ж����⹦�ܼĴ���
//�е��жϿ��ơ��жϱ�־λɢ�����������⹦�ܼĴ����У���Щλ��λ��ַ�ж���
//�����е�λ��λѰַ����������� ��һ�� 1T 8051ϵ�� ��Ƭ������ָ��
//                                           7     6     5    4     3    2    1    0   Reset Value
__sfr __at 0xA8 IE;  //�жϿ��ƼĴ���        EA  ELVD  EADC   ES   ET1  EX1  ET0  EX0  0x00,0000
//-----------------------
__sbit __at 0xAF EA;
__sbit __at 0xAE ELVD; //��ѹ����ж�����λ
__sbit __at 0xAD EADC; //ADC �ж�����λ
__sbit __at 0xAC ES;
__sbit __at 0xAB ET1;
__sbit __at 0xAA EX1;
__sbit __at 0xA9 ET0;
__sbit __at 0xA8 EX0;
//-----------------------
__sfr __at IE2 0xAF IE2;  //Auxiliary Interrupt   -     -     -    -     -    -  ESPI  ES2  0000,0000B
//-----------------------
//                                          7     6     5    4    3    2    1    0    Reset Value
__sfr __at IP 0xB8 IP; //�ж����ȼ���λ      PPCA  PLVD  PADC  PS   PT1  PX1  PT0  PX0   0000,0000
//--------
__sbit __at PPCA 0xBF PPCA;  //PCA ģ���ж����ȼ�
__sbit __at PLVD 0xBE PLVD;  //��ѹ����ж����ȼ�
__sbit __at PADC 0xBD PADC;  //ADC �ж����ȼ�
__sbit __at PS   0xBC PS;
__sbit __at PT1  0xBB PT1;
__sbit __at PX1  0xBA PX1;
__sbit __at PT0  0xB9 PT0;
__sbit __at PX0  0xB8 PX0;
//-----------------------
//                                         7      6      5     4     3     2     1     0    Reset Value
__sfr __at IPH  0xB7 IPH; //�ж����ȼ���λ       PPCAH  PLVDH  PADCH  PSH  PT1H  PX1H  PT0H  PX0H   0000,0000
__sfr __at IP2  0xB5 IP2; //                       -      -      -     -     -     -   PSPI   PS2   xxxx,xx00
__sfr __at IPH2 0xB6 IPH2; //                       -      -      -     -     -     -   PSPIH  PS2H  xxxx,xx00
//-----------------------
//��һ�� 1T 8051ϵ�� ��Ƭ��I/O �����⹦�ܼĴ���
//                                      7     6     5     4     3     2     1     0         Reset Value
__sfr __at  0x80 P0; //8 bitPort0          P0.7  P0.6  P0.5  P0.4  P0.3  P0.2  P0.1  P0.0       1111,1111
__sbit __at 0x80 P00;
__sbit __at 0x81 P01;
__sbit __at 0x82 P02;
__sbit __at 0x83 P03;
__sbit __at 0x84 P04;
__sbit __at 0x85 P05;
__sbit __at 0x86 P06;
__sbit __at 0x87 P07;
__sfr __at  0x94 P0M0; //                                                                         0000,0000
__sfr __at  0x93 P0M1; //                                                                         0000,0000
__sfr __at  0x90 P1; //8 bitPort1          P1.7  P1.6  P1.5  P1.4  P1.3  P1.2  P1.1  P1.0       1111,1111
__sbit __at 0x90 P10;
__sbit __at 0x91 P11;
__sbit __at 0x92 P12;
__sbit __at 0x93 P13;
__sbit __at 0x94 P14;
__sbit __at 0x95 P15;
__sbit __at 0x96 P16;
__sbit __at 0x97 P17;
__sfr __at 0x92 P1M0; //                                                                         0000,0000
__sfr __at 0x91 P1M1; //                                                                         0000,0000
__sfr __at 0x9D P1ASF; //P1 analog special function
__sfr __at 0xA0 P2; //8 bitPort2          P2.7  P2.6  P2.5  P2.4  P2.3  P2.2  P2.1  P2.0       1111,1111
__sbit __at 0xA0 P20;
__sbit __at 0xA1 P21;
__sbit __at 0xA2 P22;
__sbit __at 0xA3 P23;
__sbit __at 0xA4 P24;
__sbit __at 0xA5 P25;
__sbit __at 0xA6 P26;
__sbit __at 0xA7 P27;
__sfr __at 0x96 P2M0; //                                                                         0000,0000
__sfr __at 0x95 P2M1; //                                                                         0000,0000
__sfr __at 0xB0 P3; //8 bitPort3          P3.7  P3.6  P3.5  P3.4  P3.3  P3.2  P3.1  P3.0       1111,1111
__sbit __at 0xB0 P30;
__sbit __at 0xB1 P31;
__sbit __at 0xB2 P32;
__sbit __at 0xB3 P33;
__sbit __at 0xB4 P34;
__sbit __at 0xB5 P35;
__sbit __at 0xB6 P36;
__sbit __at 0xB7 P37;
__sfr __at 0xB2 P3M0; //                                                                         0000,0000
__sfr __at 0xB1 P3M1; //                                                                         0000,0000
__sfr __at 0xC0 P4; //8 bitPort4          P4.7  P4.6  P4.5  P4.4  P4.3  P4.2  P4.1  P4.0       1111,1111
__sbit __at 0xC0 P40;
__sbit __at 0xC1 P41;
__sbit __at 0xC2 P42;
__sbit __at 0xC3 P43;
__sbit __at 0xC4 P44;
__sbit __at 0xC5 P45;
__sbit __at 0xC6 P46;
__sbit __at 0xC7 P47;
__sfr __at  0xB4 P4M0; //                                                                         0000,0000
__sfr __at  0xB3 P4M1; //                                                                         0000,0000
//                                      7      6         5         4      3     2     1     0     Reset Value
__sfr __at  0xBB P4SW; //Port-4 switch        -   LVD_P4.6  ALE_P4.5  NA_P4.4   -     -     -     -       x000,xxxx

__sfr __at  0xC8 P5; //8 bitPort5           -     -       -      -    P5.3  P5.2  P5.1  P5.0    xxxx,1111
__sbit __at 0xC8 P50;
__sbit __at 0xC9 P51;
__sbit __at 0xCA P52;
__sbit __at 0xCB P53;
__sfr __at  0xCA P5M0; //                                                                         0000,0000
__sfr __at  0xC9 P5M1; //                                                                         0000,0000
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ����ʱ�����⹦�ܼĴ���
//                                          7     6     5     4     3     2     1     0     Reset Value
__sfr __at  0x88 TCON; //T0/T1 Control           TF1   TR1   TF0   TR0   IE1   IT1   IE0   IT0    0000,0000
//-----------------------------------
__sbit __at 0x8F TF1;
__sbit __at 0x8E TR1;
__sbit __at 0x8D TF0;
__sbit __at 0x8C TR0;
__sbit __at 0x8B IE1;
__sbit __at 0x8A IT1;
__sbit __at 0x89 IE0;
__sbit __at 0x88 IT0;
//-----------------------------------
__sfr __at 0x89 TMOD; //T0/T1 Modes             GATE1 C/T1  M1_1  M1_0  GATE0 C/T0  M0_1  M0_0   0000,0000
__sfr __at 0x8A TL0; //T0 Low Byte                                                              0000,0000
__sfr __at 0x8C TH0; //T0 High Byte                                                             0000,0000
__sfr __at 0x8B TL1; //T1 Low Byte                                                              0000,0000
__sfr __at 0x8D TH1; //T1 High Byte                                                             0000,0000
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ�����п����⹦�ܼĴ���
//                                          7     6     5     4     3     2     1     0     Reset Value
__sfr __at 0x98 SCON; //Serial Control         SM0/FE SM1   SM2   REN   TB8   RB8    TI    RI    0000,0000
//-----------------------------------
__sbit __at 0x9F SM0;  //SM0/FE
__sbit __at 0x9E SM1;
__sbit __at 0x9D SM2;
__sbit __at 0x9C REN;
__sbit __at 0x9B TB8;
__sbit __at 0x9A RB8;
__sbit __at 0x99 TI;
__sbit __at 0x98 RI;
//-----------------------------------
__sfr __at 0x99 SBUF; //Serial Data Buffer                                                     xxxx,xxxx
__sfr __at 0xB9 SADEN; //Slave Address Mask                                                    0000,0000
__sfr __at 0xA9 SADDR; //Slave Address                                                         0000,0000
//-----------------------------------
//                                7      6      5      4      3      2     1     0        Reset Value
__sfr __at 0x9A S2CON; //S2 Control  S2SM0  S2SM1  S2SM2  S2REN  S2TB8  S2RB8  S2TI  S2RI      00000000B
__sfr __at 0x9B S2BUF; //S2 Serial Buffer                                                      xxxx,xxxx
__sfr __at 0x9C BRT; //S2 Baud-Rate Timer                                                    0000,0000
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ�����Ź���ʱ�����⹦�ܼĴ���
__sfr __at 0xC1 WDT_CONTR; //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
//-----------------------

//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ��PCA/PWM ���⹦�ܼĴ���
//                                         7     6     5     4     3     2     1     0     Reset Value
__sfr __at 0xD8 CCON;   //PCA ���ƼĴ�����    CF    CR    -     -     -     -    CCF1  CCF0   00xx,xx00
//-----------------------
__sbit __at 0xDF CF; //PCA�����������־,��Ӳ���������λ,�����������0��
__sbit __at 0xDE CR; //1:���� PCA ����������, �����������0��
//-
//-
__sbit __at 0xD9 CCF1; //PCA ģ��1 �жϱ�־, ��Ӳ����λ, �����������0��
__sbit __at 0xD8 CCF0; //PCA ģ��0 �жϱ�־, ��Ӳ����λ, �����������0��
//-----------------------
__sfr __at 0xD9 CMOD; //PCA ����ģʽ�Ĵ�����   CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,x000
/*
CIDL: idle ״̬ʱ PCA �������Ƿ��������, 0: ��������, 1: ֹͣ������

CPS2: PCA ����������Դѡ��λ 2��
CPS1: PCA ����������Դѡ��λ 1��
CPS0: PCA ����������Դѡ��λ 0��
   CPS2   CPS1   CPS0
    0      0      0    ϵͳʱ��Ƶ�� fosc/12��
    0      0      1    ϵͳʱ��Ƶ�� fosc/2��
    0      1      0    Timer0 �����
    0      1      1    �� ECI/P3.4 ��������ⲿʱ�ӣ���� fosc/2��
    1      0      0    ϵͳʱ��Ƶ�ʣ�  Fosc/1
    1      0      1    ϵͳʱ��Ƶ��/4��Fosc/4
    1      1      0    ϵͳʱ��Ƶ��/6��Fosc/6
    1      1      1    ϵͳʱ��Ƶ��/8��Fosc/8

ECF: PCA����������ж�����λ, 1--���� CF(CCON.7) �����жϡ�
*/
//-----------------------
__sfr __at 0xE9 CL; //PCA ��������λ                                                        0000,0000
__sfr __at 0xF9 CH; //PCA ��������λ                                                        0000,0000
//-----------------------
//                                         7     6      5      4     3     2     1     0     Reset Value
__sfr __at 0xDA CCAPM0; //PCA ģ��0 PWM �Ĵ���  -   ECOM0  CAPP0  CAPN0  MAT0  TOG0  PWM0  ECCF0   x000,0000
__sfr __at 0xDB CCAPM1; //PCA ģ��1 PWM �Ĵ���  -   ECOM1  CAPP1  CAPN1  MAT1  TOG1  PWM1  ECCF1   x000,0000

//ECOMn = 1:����ȽϹ��ܡ�
//CAPPn = 1:���������ش�����׽���ܡ�
//CAPNn = 1:�����½��ش�����׽���ܡ�
//MATn  = 1:��ƥ���������ʱ, ���� CCON �е� CCFn ��λ��
//TOGn  = 1:��ƥ���������ʱ, CEXn ����ת��
//PWMn  = 1:�� CEXn ����Ϊ PWM �����
//ECCFn = 1:���� CCON �е� CCFn �����жϡ�

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   δ�����κι��ܡ�
//  x      1      0     0     0     0     x   0x21   16λCEXn�����ش�����׽���ܡ�
//  x      0      1     0     0     0     x   0x11   16λCEXn�½��ش�����׽���ܡ�
//  x      1      1     0     0     0     x   0x31   16λCEXn����(�ϡ�����)������׽���ܡ�
//  1      0      0     1     0     0     x   0x49   16λ�����ʱ����
//  1      0      0     1     1     0     x   0x4d   16λ�������������
//  1      0      0     0     0     1     0   0x42   8λ PWM��

//ECOMn  CAPPn  CAPNn  MATn  TOGn  PWMn  ECCFn
//  0      0      0     0     0     0     0   0x00   �޴˲���
//  1      0      0     0     0     1     0   0x42   ��ͨ8λPWM, ���ж�
//  1      1      0     0     0     1     1   0x63   PWM����ɵͱ�߿ɲ����ж�
//  1      0      1     0     0     1     1   0x53   PWM����ɸ߱�Ϳɲ����ж�
//  1      1      1     0     0     1     1   0x73   PWM����ɵͱ�߻��ɸ߱�Ͷ��ɲ����ж�

//-----------------------
__sfr __at 0xEA CCAP0L; //PCA ģ�� 0 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
__sfr __at 0xFA CCAP0H; //PCA ģ�� 0 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
__sfr __at 0xEB CCAP1L; //PCA ģ�� 1 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
__sfr __at 0xFB CCAP1H; //PCA ģ�� 1 �Ĳ�׽/�ȽϼĴ����� 8 λ��                                    0000,0000
//-----------------------
//                                                       7   6   5   4   3   2    1     0    Reset Value
__sfr __at 0xF2 PCA_PWM0; //PCA ģ��0 PWM �Ĵ�����            -   -   -   -   -   -  EPC0H EPC0L   xxxx,xx00
__sfr __at 0xF3 PCA_PWM1; //PCA ģ��1 PWM �Ĵ�����            -   -   -   -   -   -  EPC1H EPC1L   xxxx,xx00
//PCA_PWMn:    7      6      5      4      3      2      1      0
//             -      -      -      -      -      -    EPCnH  EPCnL
//B7-B2: ����
//B1(EPCnH): �� PWM ģʽ�£��� CCAPnH ��� 9 λ����
//B0(EPCnL): �� PWM ģʽ�£��� CCAPnL ��� 9 λ����
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ�� ADC ���⹦�ܼĴ���
//                                            7        6      5       4         3      2    1    0   Reset Value
__sfr __at 0xBC ADC_CONTR; //A/D ת�����ƼĴ��� ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHS0 0000,0000
__sfr __at 0xBD ADC_RES;  //A/D ת�������8λ ADCV.9 ADCV.8 ADCV.7 ADCV.6 ADCV.5 ADCV.4 ADCV.3 ADCV.2    0000,0000
__sfr __at 0xBE ADC_RESL;  //A/D ת�������2λ                                           ADCV.1 ADCV.0    0000,0000
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ�� SPI ���⹦�ܼĴ���
//                                      7     6     5     4     3     2     1     0    Reset Value
__sfr __at 0xCE SPCTL; //SPI Control Register  SSIG  SPEN  DORD  MSTR  CPOL  CPHA  SPR1  SPR0  0000,0100
__sfr __at 0xCD SPSTAT; //SPI Status Register   SPIF  WCOL   -     -     -     -     -     -    00xx,xxxx
__sfr __at 0xCF SPDAT; //SPI Data Register                                                     0000,0000
//--------------------------------------------------------------------------------
//��һ�� 1T 8051ϵ�� ��Ƭ�� IAP/ISP ���⹦�ܼĴ���
__sfr __at 0xC2 IAP_DATA;
__sfr __at 0xC3 IAP_ADDRH;
__sfr __at 0xC4 IAP_ADDRL;
//                                                7    6    5      4    3    2    1     0    Reset Value
__sfr __at 0xC5 IAP_CMD; //IAP Mode Table          0    -    -      -    -    -   MS1   MS0   0xxx,xx00
__sfr __at 0xC6 IAP_TRIG;
__sfr __at 0xC7 IAP_CONTR; //IAP Control Register  IAPEN SWBS SWRST CFAIL  -   WT2  WT1   WT0   0000,x000
//--------------------------------------------------------------------------------

/////////////////////////////////////////////////

#endif

