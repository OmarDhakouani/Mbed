#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6 
#define BUTTON_3 p7 
#define BUTTON_4 p8 

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11

//Define outputs
DigitalOut rled(RED_LED);
DigitalOut yled(YELLOW_LED);
DigitalOut bled(BLUE_LED);

//Define interrupt inputs
InterruptIn b1(BUTTON_1);
InterruptIn b2(BUTTON_2);
InterruptIn b3(BUTTON_3);
InterruptIn b4(BUTTON_4);


//Define ISRs for the interrupts
void button_1_handler(){
	rled= !rled;
}

void button_2_handler(){
    yled= !yled;	
}

void button_3_handler(){
	bled= !bled;
}

void button_4_handler(){
	rled=yled=bled=1;
}

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
	//Initially turn off all LEDs
    rled=yled=bled=0;
	//Interrupt handlers
	//Attach the address of the ISR to the rising edge
	b1.rise(&button_1_handler);
	b2.rise(&button_2_handler);
	b3.rise(&button_3_handler);
	b4.rise(&button_4_handler);
	
	//wait 100 ms(sleep mode)
	while(1)
		wait_ms(100);
}
