#include <pic14/pic12f683.h>
#include <stdint.h>

// Deactivate Watchdog Timer
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF); 

/* --------------------
*  Fuction declarations
*  --------------------
*/ 
void delay (unsigned int time);
uint8_t lfsr (uint8_t start, uint8_t min,uint8_t max);

void main (){
    // Set GPIO pins functionality, GP3 is strictly input
    TRISIO = 0b00100000; 
    // Initialize outputs in 0
	GPIO = 0x00; 
    
    // Initial value of dice
    uint8_t throw = 0x9F;

    // Infinite loop
    while (1){
        // Function if dice is thrown (signal goes up in GP5)
        if (GP5) {
            // Generate random number
            throw = lfsr(throw, 1, 6);

            // Modify GPIO outputs based on number to output on LEDs
            switch (throw){
                case 1: 
                    GPIO = 0x02;
                    delay(500);
                    GPIO = 0x00; 
                    break;
                case 2:
                    GPIO = 0x01; 
                    delay(500);
                    GPIO = 0x00; 
                    break;
                case 3:
                    GPIO = 0x06; 
                    delay(500);
                    GPIO = 0x00; 
                    break;
                case 4:
                    GPIO = 0x11; 
                    delay(500);
                    GPIO = 0x00; 
                    break;
                case 5:
                    GPIO = 0x13; 
                    delay(500);
                    GPIO = 0x00; 
                    break;
                case 6:
                    GPIO = 0x15; 
                    delay(500);
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

uint8_t lfsr (uint8_t start, uint8_t min, uint8_t max){
    while (1){
        uint8_t bit = ((start >> 7) ^ (start >> 6) ^ (start >> 5) ^ (start >> 4) ^ (start >> 3)) & 1;
        start = (start << 1) | bit;
        return (start % 6) + 1;
    }
}