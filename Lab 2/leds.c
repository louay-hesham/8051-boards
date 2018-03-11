

#include <REG52.H>                /* special function register declarations   */
                                  /* for the intended 8051 derivative         */



#define input P3
#define left_sw P3^5
#define fara7_3omda_sw P3^6
#define right_sw P3^7
#define output P2

void delay();
unsigned char rot_left(unsigned char LEDs);

void main (void) {
	unsigned char LEDs = 0x7F;
	while(1) {
		delay();
		LEDs = rot_left(LEDs);
		output = LEDs;
	}
}

void delay() {
	unsigned char i,j,k;
	for (i=7; i>0; i--) {
		for (j=255; j>0; j--) {
			for (k=255; k>0; k--) {
			}
		}
	}
}

unsigned char rot_left(unsigned char LEDs) {
	return (LEDs << 1) | (LEDs >> 7);
}


