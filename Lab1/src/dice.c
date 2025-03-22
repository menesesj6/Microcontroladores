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


int main (){
    // Set GPIO pins functionality, GP5 is strictly input
    TRISIO = 0b00100000; 
    // Initialize outputs in 0
	GPIO = 0x00; 
    
    // Basic variables
    uint8_t  throw;

    // Generate random number


    // Modify GPIO outputs based on number
    switch (throw){
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        default:
            break;
    }

    return 0;
}

void delay (unsigned int time){

}