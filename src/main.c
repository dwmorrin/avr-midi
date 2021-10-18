#include <util/delay.h>
#include <Midi.h>

int main()
{
  Midi_init();
  struct MidiMessage msg;
  MidiMessage_init(&msg, 1);
  uint8_t note_on = 0;
  for (;;)
  {
    if (note_on)
      MidiMessage_note_on(&msg, 40, 127);
    else
      MidiMessage_note_off(&msg, 40, 127);

    MidiMessage_send(&msg);
    note_on = !note_on;
    _delay_ms(500);
  }
}