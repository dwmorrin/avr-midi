#ifndef MIDI_USART_H
#define MIDI_USART_H

#include <stdint.h>

#define MIDI_USART_BAUDRATE 31250

// see datasheet for formula
// UBRR0 = f_clk / (16 * MIDI_USART_BAUDRATE) - 1
#ifdef ARDUINO_AVR_CIRCUIT_PLAYGROUND_CLASSIC
// @ 8 MHz - x1 speed = 15, x2 speed = 31
#define MIDI_USART_UBRR 31
#else
// 168 @ 1 MHz
#define MIDI_USART_UBRR 1
#endif

void USART_init();
void USART_send(uint8_t data);
#endif