#include <avr/io.h>
#include "USART.h"

void USART_init()
{
  UBRR0H = 0;
  UBRR0L = 1;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  // 1 start bit, 8 data bits, 1 stop bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void USART_send(uint8_t data)
{
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  UDR0 = data;
}