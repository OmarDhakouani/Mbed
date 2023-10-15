
#include "mbed.h"
//initialize Led pin as output
DigitalOut LED(D10);

// Blinking rate in milliseconds
#define BLINKING_RATE_MS 500


int main()
{
    while(true){
        LED= !LED;
        thread_sleep_for(BLINKING_RATE_MS);
        LED= !LED;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
