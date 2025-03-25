#include <pic14/pic12f683.h>
#include <stdint.h>

// Delay Macro
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
    // Set GPIO pins functionality, GP5 is our input and GP3 is strictly input
    TRISIO = 0b00100000; 
    // Initialize outputs in 0
	GPIO = 0x00;

    // Infinite loop
    while (1){
        // Operate LEDs if dice is thrown (signal goes up in GP5)
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

// Delay function, empty for loops
void delay (unsigned int time){
    unsigned int i, j;
    for (i = 0; i < time; i++){
        for (j = 0; j < time; j++){}
    }
}

/* -------------------
 * LFSR Algorithm PRNG
 * -------------------
 * Arbitrary feedback polynomial = 0xB8
 * Arbitrary seed = 0x9F
 */
uint8_t lfsr (){
    // Declare feedback polynomial
    uint8_t feedback_pol = 0xB8;

    // Isolate LSB
    uint8_t lsb = throw & 1;

    // Shift out LSB
    throw >>= 1; 
    if (lsb) {
        // XOR with feedback polynomial
        throw ^= feedback_pol; 
    }

    // Limit return to 1-6 range
    return throw % 6 + 1;
}