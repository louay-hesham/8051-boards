

#include <REG52.H>                /* special function register declarations   */
                                  /* for the intended 8051 derivative         */



#define input P3
#define output P2

void delay_500();
void delay_200();
void delay_100();
unsigned char rot_left(unsigned char LEDs);
unsigned char rot_right(unsigned char LEDs);
void left_right ();

unsigned char position[4] = {0xE7,0xDB,0xBD,0x7E};
unsigned char LEDs = 0x7F;
sbit right_sw = P3^7;
sbit left_sw = P3^6;
sbit fara7_3omda_sw = P3^5;

void main (void) {
	input = 0xFF;
	output = LEDs;
	while (1) {
		if (!right_sw) {
			delay_200();
			LEDs = rot_right(LEDs);
			output = LEDs;
		} else if (!left_sw) {
			delay_200();
			LEDs = rot_left(LEDs);
			output = LEDs;
		} else if (!fara7_3omda_sw) {
			delay_200();
			left_right();
			delay_500();
			LEDs = 0x7F;
			output = LEDs;
		}
	}	
}



void delay_500() {
	unsigned char i,j,k;
	for (i=7; i>0; i--) {
		for (j=255; j>0; j--) {
			for (k=255; k>0; k--) {
			}
		}
	}
}

void delay_200() {
	unsigned char i,j,k;
	for (i=3; i>0; i--) {
		for (j=255; j>0; j--) {
			for (k=255; k>0; k--) {
			}
		}
	}
}

void delay_100() {
	unsigned char i,j,k;
	for (i=3; i>0; i--) {
		for (j=128; j>0; j--) {
			for (k=255; k>0; k--) {
			}
		}
	}
}

unsigned char rot_left(unsigned char LEDs) {
	return (LEDs << 1) | (LEDs >> 7);
}

unsigned char rot_right(unsigned char LEDs) {
	return (LEDs >> 1) | (LEDs << 7);
}


void left_right () {
	
	int i,j;
	LEDs = 0xFE;
	output = LEDs;
	for ( j=2; j>0; j--) {
		for ( i=7; i>0; i--) {
			LEDs = rot_left(LEDs);
			output = LEDs;
			delay_500();
		}
		for ( i=7; i>0; i--) {
			LEDs = rot_right(LEDs);
			output = LEDs;
			delay_500();
		}
	}

	for ( j=2; j>0; j--) {
		for ( i=4; i>0; i--) {
			delay_100();
			LEDs = position[4-i];	
			output = LEDs;
		}		
		for ( i=3; i>=0; i--){
			delay_100();
			LEDs = position[i];	
			output = LEDs;
		}		
	}
}
