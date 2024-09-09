#include <avr/io.h>
#include "delay.h"

void delay_ms(uint16_t milliseconds) {
    TCCR0A = 0;                         
    TCCR0B |= (1 << CS01) | (1 << CS00); 

    while (milliseconds--) {
        TCNT0 = 0;                      
        while (TCNT0 < 250);              
    }
}