#ifndef MIDI_USART_H
#define MIDI_USART_H

#include <stdint.h>

#define MIDI_USART_BAUDRATE 31250

/**
 * datasheet formulas on page 147
 * 31250 = 1e6 / (16 * (UBRR + 1))
 * 31250 * (16 * (UBRR + 1)) = 1e6
 * 31250 * (16 * UBRR + 16) = 1e6
 * 500000 * UBRR + 500000 = 1e6
 * 500000 * UBRR = 500000
 * UBRR = 1
 */

void USART_init();
void USART_send(uint8_t data);
#endif