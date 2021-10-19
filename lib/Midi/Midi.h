#ifndef MIDI_H
#define MIDI_H
/**
 * Baud rate: 31250 +/- 1%
 * Status Bytes
 * 
 * Note off: 0x80
 * Note on:  0x90
 * 
 * Wiring note: 
 * 5 pin DIN #s go 1-4-2-5-3
 * uC Vcc should go to 4 (MIDI current source)
 * Tx pin should go to 5 (MIDI current sink)
 */

#include <stdint.h>

struct MidiMessage
{
  uint8_t status; // high nibble = command, low nibble = channel
  uint8_t data1;
  uint8_t data2;
};

// Starts USART
void Midi_init();
// channel is 1-16
void MidiMessage_init(struct MidiMessage *msg, uint8_t channel);
// channel is 1-16
void MidiMessage_channel(struct MidiMessage *msg, uint8_t channel);
void MidiMessage_note_on(struct MidiMessage *msg, uint8_t note, uint8_t velocity);
void MidiMessage_note_off(struct MidiMessage *msg, uint8_t note, uint8_t velocity);
void MidiMessage_send(struct MidiMessage *msg);
#endif