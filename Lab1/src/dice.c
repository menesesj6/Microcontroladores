#include <pic14/pic12f683.h>
#include <stdint.h>

#define WAIT 500

// Deactivate Watchdog Timer
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF); 

/* --------------------
*  Fuction declarations
*  --------------------
*/ 
void delay (unsigned int time);
uint8_t lfsr ();

// Initial dice value => Seed for LFSR
volatile uint8_t throw = 0x9F;

void main (){
    // Set GPIO pins functionality, GP3 is strictly input
    TRISIO = 0b00100000; 
    // Initialize outputs in 0
	GPIO = 0x00;

    // Infinite loop
    while (1){
        // Function if dice is thrown (signal goes up in GP5)
        if (GP5) {

            // Generate random number
            uint8_t roll = lfsr();

            // Modify GPIO outputs based on number to output on LEDs
            switch (roll){
                case 1: 
                    GPIO = 0x02;
                    delay(WAIT);
                    GPIO = 0x00; 
                    break;
                case 2:
                    GPIO = 0x01; 
                    delay(WAIT);
                    GPIO = 0x00; 
                    break;
                case 3:
                    GPIO = 0x06; 
                    delay(WAIT);
                    GPIO = 0x00; 
                    break;
                case 4:
                    GPIO = 0x11; 
                    delay(WAIT);
                    GPIO = 0x00; 
                    break;
                case 5:
                    GPIO = 0x13; 
                    delay(WAIT);
                    GPIO = 0x00; 
                    break;
                case 6:
                    GPIO = 0x15; 
                    delay(WAIT);
                    GPIO = 0x00; 
                    break;
                default:
                    break;
            }
        }
    }
}

void delay (unsigned int time){
    unsigned int i, j;
    for (i = 0; i < time; i++){
        for (j = 0; j < time; j++){}
    }
}

uint8_t lfsr (){
    uint8_t feedback_pol = 0xB8;
    uint8_t lsb = throw & 1;
    throw >>= 1; 
    if (lsb) {
        throw ^= feedback_pol; 
    }
    return throw % 6 + 1;
}