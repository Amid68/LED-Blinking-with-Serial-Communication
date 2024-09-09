#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

#define LED_PIN PB0

void timer1_init(void) {
	TCCR1A = 0;
	TCCR1B |= (1 << WGM12);
	OCR1A = 15624;
	TCCR1B |= (1 << CS12) | (1 << CS10);
	TIMSK1 |= (1 << OCIE1A);
	sei();
}

ISR(TIMER1_COMPA_vect) {
	PORTB ^= (1 << LED_PIN);
}
