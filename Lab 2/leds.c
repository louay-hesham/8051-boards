

#include <REG52.H>                /* special function register declarations   */
                                  /* for the intended 8051 derivative         */



#define input P3
#define left_sw P3^5
#define fara7_3omda_sw P3^6
#define right_sw P3^7
#define output P2

void delay();
unsigned char rot_left(unsigned char LEDs);
unsigned char rot_right(unsigned char LEDs);
void left_right (unsigned char LEDs);
void delay_milli();
unsigned char position[4] = {0xE7,0xDB,0xBD,0x7E};

void main (void) {
unsigned char LEDs = 0x7F;
	
	
	
		//delay();
		//LEDs = rot_right(LEDs);
		//output = LEDs;
	
			

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

void delay_milli() {
	unsigned char i,j,k;
	for (i=3; i>0; i--) {
		for (j=255; j>0; j--) {
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


void left_right (unsigned char LEDs) {
	
	int i,j,k;
	
	for ( i=7; i>0; i--) {
	LEDs = rot_right(LEDs);
		output = LEDs;
		delay_milli();
	}
	for ( j=7; j>0; j--) {
	LEDs = rot_left(LEDs);
		output = LEDs;
		delay_milli();
	}

	for ( k=0; k<=3; k++) {
	
			delay_milli();
			LEDs = position[k];	
			output = LEDs;
			
	}		
  		 	for ( k=3; k>=0; k--){
	
				delay_milli();
				LEDs = position[k];	
			output = LEDs;
			
	}		
	

}
