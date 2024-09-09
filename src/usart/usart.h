#ifndef USART_H
#define USART_H

void usart_init(uint16_t ubrr_value);
void usart_transmit_char(char data);
void usart_transmit_string(const char* str);

#endif
