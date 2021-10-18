#include <stdint.h>
#include <USART.h>

#include "Midi.h"

void Midi_init()
{
  USART_init();
}

void MidiMessage_init(struct MidiMessage *msg, uint8_t channel)
{
  msg->status = channel - 1;
  msg->data1 = 0;
  msg->data2 = 0;
}

void MidiMessage_channel(struct MidiMessage *msg, uint8_t channel)
{
  msg->status &= ~0x0F;       // clear old channel
  msg->status |= channel - 1; // set new channel
}

void MidiMessage_note_on(struct MidiMessage *msg, uint8_t note, uint8_t velocity)
{
  msg->status |= 0x90;
  msg->data1 = note;     // 0-127
  msg->data2 = velocity; // 0-127
}

void MidiMessage_note_off(struct MidiMessage *msg, uint8_t note, uint8_t velocity)
{
  msg->status |= 0x80;
  msg->data1 = note;     // 0-127
  msg->data2 = velocity; // 0-127
}

void MidiMessage_send(struct MidiMessage *msg)
{
  USART_send(msg->status);
  USART_send(msg->data1);
  USART_send(msg->data2);
}