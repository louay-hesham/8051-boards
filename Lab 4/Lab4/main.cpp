#include <at89c51xd2.h>
#include <stdio.h>

sbit 	IN	= P1^0;
sbit	LED	= P1^7;

void SetupSerial()
{
/*
	------------------------------------------------
  Setup the serial port for 9600 baud at 22.1184MHz.
  ------------------------------------------------
*/
    SCON  = 0x50;		        		/* SCON: mode 1, 8-bit UART, enable rcvr      */
    TMOD |= 0x20;               /* TMOD: timer 1, mode 2, 8-bit reload        */
    
	  /*  TH1 = ( 256 - ((22.1184MHZ / 12 ) / 32) / BaudRate ) = 256 - 6 = 250  */
	  TH1   = 250;                /* TH1:  reload value for 9600 baud @ 22.1184MHz   */
    TR1   = 1;                  /* TR1:  timer 1 run                          */
	  TI    = 1;  
}




void main()
{
	 unsigned char key = ' ';
	
	
	 SetupSerial();

	
	 while(1)
	 {
		 key = getchar();
		 
		 
		 switch(key)
		 {
			 case 'R':
			 case 'r':
									
									break;
			 
			 case 'S':
			 case 's':
				 
									break;
			 
		 }	
		 		 
	 }
	
}