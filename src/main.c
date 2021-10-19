#include <avr/io.h>
#include <util/delay.h>
#include <Midi.h>
#include <USART.h>

int main()
{
#ifdef ARDUINO_AVR_CIRCUIT_PLAYGROUND_CLASSIC
  // turn red LED on
  DDRC |= (1 << DDC7);
  PORTC |= (1 << PC7);
#endif
  Midi_init();
  struct MidiMessage msg;
  MidiMessage_init(&msg, 1);
  uint8_t note_on = 0;
  for (;;)
  {
#ifdef ARDUINO_AVR_CIRCUIT_PLAYGROUND_CLASSIC
    // blink red LED
    PORTC ^= (1 << PC7);
#endif
    if (note_on)
      MidiMessage_note_on(&msg, 40, 127);
    else
      MidiMessage_note_off(&msg, 40, 127);

    MidiMessage_send(&msg);
    note_on = !note_on;
    _delay_ms(500);
  }
}