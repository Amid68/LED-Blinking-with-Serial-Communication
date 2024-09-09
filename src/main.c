#include <avr/io.h>
#include "usart/usart.h"
#include "timer/timer.h"
#include "delay/delay.h"

#define LED_PIN PB0
#define SERIAL_DELAY 1000

int main(void) {
    DDRB |= (1 << LED_PIN); 

    usart_init(F_CPU / 16 / 9600 - 1);  

    timer1_init(); 

    // Main loop
    while (1) {
        usart_transmit_string("Hello, World!\r\n");  
        delay_ms(SERIAL_DELAY);                     
    }
}