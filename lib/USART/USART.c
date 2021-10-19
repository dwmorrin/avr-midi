#include <avr/io.h>
#include "USART.h"

void USART_init()
{
#ifdef ARDUINO_AVR_CIRCUIT_PLAYGROUND_CLASSIC
  UBRR1H = 0;
  UBRR1L = MIDI_USART_UBRR;
  UCSR1A = (1 << U2X1); // double speed mode
  UCSR1B = (1 << RXEN1) | (1 << TXEN1);
  // 1 start bit, 8 data bits, 1 stop bit, no parity bit
  UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
#else
  UBRR0H = 0;
  UBRR0L = MIDI_USART_UBRR;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  // 1 start bit, 8 data bits, 1 stop bit, no parity bit
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
#endif
}

void USART_send(uint8_t data)
{
#ifdef ARDUINO_AVR_CIRCUIT_PLAYGROUND_CLASSIC
  while (!(UCSR1A & (1 << UDRE1)))
    ;
  UDR1 = data;
#else
  while (!(UCSR0A & (1 << UDRE0)))
    ;
  UDR0 = data;
#endif
}