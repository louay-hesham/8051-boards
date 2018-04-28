#include <at89c51xd2.h>

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
    TI = 0;
    RI = 0;  
}

void __putchar(unsigned char ch)
{
		SBUF = ch;
		while(TI == 0);
		TI = 0;
}

unsigned char __getchar()
{
		unsigned char ch;
	  while(RI == 0);
	  ch = SBUF;
	  RI = 0;
	  return ch;
}

void printString(const char *s)
{
		while(*s)
			__putchar(*(s++));	
}

unsigned char ToASCII(unsigned char val)
{
			if( val	>= 0  &&  val <=9 )
					return val + '0';
			else if ( val	>= 0x0A && 	val <= 0x0F) 
					return val + 'A' - 10;	
			else
				return ' ';
}

void main()
{
	 unsigned char key = ' ';
	 unsigned char half_port;

	
	 SetupSerial();
	 
	 // 191 bytes of code without the printString function
	
	 // 224 bytes of code with the printString function
	 printString("\r\nTesting Serial UART\r\n");
	
	 P1 = 0x0F;
	
	 while(1)
	 {
		 key = __getchar();
		 
		 switch(key)
		 {
			 case 'R':
			 case 'r':
									half_port = P1 & 0x0F;
								  __putchar( ToASCII(half_port));									
									P1 = (~half_port << 4) | 0x0F; 
									break;
			 
		 }	
		 		 
	 }
	
}