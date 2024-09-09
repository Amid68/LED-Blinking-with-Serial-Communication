#include <avr/io.h>
#include "usart.h"

void usart_init(uint16_t ubrr_value) {
	UBRR0H = (ubrr_value >> 8);
	UBRR0L = ubrr_value;
	UCSR0B = (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void usart_transmit_char(char data) {
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

void usart_transmit_string(const char* str) {
	while (*str) { usart_transmit_char(*str++); }
}
