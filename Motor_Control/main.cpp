#include "mbed.h"


// Define the Input pins
DigitalIn  START(p5);       //start button, start=1
DigitalIn  STOP(p6);        //stop button, stop=1
DigitalIn  GUARD(p7);       //machine guard sensor, guard closed=1
DigitalIn  TEMP(p8);        //temperature sensor, excess=1  

//Define the Output pins
DigitalOut READY(p9);       //motor ready to run, guard closed,temperature OK
DigitalOut RUNNING(p10);    //motor running, running=1
DigitalOut FAULT(p11); //machine guard is open, while motor running 
DigitalOut TEMP_EXCESS(p12);//excess temperature



int main()
{
    while (1){
        while((GUARD==0)||TEMP==1)){
            RUNNING=FAULT=TEMP_EXCESS=0; //clear all displays
            READY=!READY;
            wait(0.2);
        }
        READY=1;                         //motor is ready to run
        while(START==0)                  //wait for start to be pressed
            wait(0.01);
        //Now start and run the motor,
	    //stay in this loop until need to exit 
		while((GUARD==1)&&(TEMP==0)&&(STOP==0)){ 
		READY=0; 
		RUNNING=1;   
		wait(0.2);  //diagnostic 
		} 
	//here if motor to stop, determine and act on cause 
		if (GUARD==0){ 
			RUNNING=0; 
			FAULT=1; 
			wait(0.5); 
			FAULT=0; 
			} 
		if (TEMP==1){ 
			RUNNING=0; 
			TEMP_EXCESS=1; 
			wait(0.5); 
			TEMP_EXCESS=0;
			}
		if (STOP==1) 
			RUNNING=0; //loop will return to start 
	}   //end of while(1) 
}       //end of main()

