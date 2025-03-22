#include <pic14/pic12f683.h>
#include 

// Deactivate Watchdog Timer
typedef unsigned int word;
word __at 0x2007 __CONFIG = (_WDTE_OFF); 

/* --------------------
*  Fuction declarations
*  --------------------
*/ 
void delay (unsigned int time);
uint8_t lfsr (uint8_t seed, uint8_t min,uint8_t max);


int main (){
    // Set GPIO pins functionality, GP5 is strictly input
    TRISIO = 0b00100000; 
    // Initialize outputs in 0
	GPIO = 0x00; 
    
    // Basic variables
    uint8_t  throw = 1;

    // Generate random number

    // Modify GPIO outputs based on number
    switch (throw){
        case 1: 
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
    }

    return 0;
}

void delay (unsigned int time){
    unsigned int i, j;
    for (i = 0; i < time; i++){
        for (j = 0; j < time; j++)
    }
}

uint8_t lfsr (uint8_t seed, uint8_t min,uint8_t max){

}