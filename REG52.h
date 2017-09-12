/*--------------------------------------------------------------------------
REG52.H

Header file for generic 80C52 and 80C32 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG52_H__
#define __REG52_H__

/*  BYTE Registers  */
__sfr __at  0x80 P0;
__sfr __at  0x90 P1;
__sfr __at  0xA0 P2;
__sfr __at  0xB0 P3;
__sfr __at  0xD0 PSW;
__sfr __at  0xE0 ACC;
__sfr __at  0xF0 B;
__sfr __at  0x81 SP;
__sfr __at  0x82 DPL;
__sfr __at  0x83 DPH;
__sfr __at  0x87 PCON;
__sfr __at  0x88 TCON;
__sfr __at  0x89 TMOD;
__sfr __at  0x8A TL0;
__sfr __at  0x8B TL1;
__sfr __at  0x8C TH0;
__sfr __at  0x8D TH1;
__sfr __at  0xA8 IE;
__sfr __at  0xB8 IP;
__sfr __at  0x98 SCON;
__sfr __at  0x99 SBUF;

__sbit __at 0x80 P0_0;
__sbit __at 0x81 P0_1;
__sbit __at 0x82 P0_2;
__sbit __at 0x83 P0_3;
__sbit __at 0x84 P0_4;
__sbit __at 0x85 P0_5;
__sbit __at 0x86 P0_6;
__sbit __at 0x87 P0_7;

__sbit __at 0x90 P1_0; 
__sbit __at 0x91 P1_1;
__sbit __at 0x92 P1_2;
__sbit __at 0x93 P1_3;
__sbit __at 0x94 P1_4;
__sbit __at 0x95 P1_5;
__sbit __at 0x96 P1_6;
__sbit __at 0x97 P1_7;

__sbit __at 0xA0 P2_0;
__sbit __at 0xA1 P2_1;
__sbit __at 0xA2 P2_2;
__sbit __at 0xA3 P2_3;
__sbit __at 0xA4 P2_4;
__sbit __at 0xA5 P2_5;
__sbit __at 0xA6 P2_6;
__sbit __at 0xA7 P2_7;

__sbit __at 0xB0 P3_0;
__sbit __at 0xB1 P3_1;
__sbit __at 0xB2 P3_2;
__sbit __at 0xB3 P3_3;
__sbit __at 0xB4 P3_4;
__sbit __at 0xB5 P3_5;
__sbit __at 0xB6 P3_6;
__sbit __at 0xB7 P3_7;

/*  8052 Extensions  */
__sfr __at  0xC8 T2CON;
__sfr __at  0xCA RCAP2L;
__sfr __at  0xCB RCAP2H;
__sfr __at  0xCC TL2;
__sfr __at  0xCD TH2;


/*  BIT Registers  */
/*  PSW  */
__sbit __at  0xD7 CY;
__sbit __at  0xD6 AC;
__sbit __at  0xD5 F0;
__sbit __at  0xD4 RS1;
__sbit __at  0xD3 RS0;
__sbit __at  0xD2 OV;
__sbit __at  0xD0 P; //8052 only

/*  TCON  */
__sbit __at  0x8F TF1;
__sbit __at  0x8E TR1;
__sbit __at  0x8D TF0;
__sbit __at  0x8C TR0;
__sbit __at  0x8B IE1;
__sbit __at  0x8A IT1;
__sbit __at  0x89 IE0;
__sbit __at  0x88 IT0;

/*  IE  */
__sbit __at  0xAF EA;
__sbit __at  0xAD ET2; //8052 only
__sbit __at  0xAC ES;
__sbit __at  0xAB ET1;
__sbit __at  0xAA EX1;
__sbit __at  0xA9 ET0;
__sbit __at  0xA8 EX0;

/*  IP  */
__sbit __at  0xBD PT2;
__sbit __at  0xBC PS;
__sbit __at  0xBB PT1;
__sbit __at  0xBA PX1;
__sbit __at  0xB9 PT0;
__sbit __at  0xB8 PX0;

/*  P3  */
__sbit __at  0xB7 RD;
__sbit __at  0xB6 WR;
__sbit __at  0xB5 T1;
__sbit __at  0xB4 T0;
__sbit __at  0xB3 INT1;
__sbit __at  0xB2 INT0;
__sbit __at  0xB1 TXD;
__sbit __at  0xB0 RXD;

/*  SCON  */
__sbit __at  0x9F SM0;
__sbit __at  0x9E SM1;
__sbit __at  0x9D SM2;
__sbit __at  0x9C REN;
__sbit __at  0x9B TB8;
__sbit __at  0x9A RB8;
__sbit __at  0x99 TI;
__sbit __at  0x98 RI;

/*  P1  */
__sbit __at  0x91 T2EX; // 8052 only
__sbit __at  0x90 T2; // 8052 only
             
/*  T2CON  */
__sbit __at  0xCF TF2;
__sbit __at  0xCE EXF2;
__sbit __at  0xCD RCLK;
__sbit __at  0xCC TCLK;
__sbit __at  0xCB EXEN2;
__sbit __at  0xCA TR2;
__sbit __at  0xC9 C_T2;
__sbit __at  0xC8 CP_RL2;

#endif
