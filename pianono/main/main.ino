#include "pitches.h"
#define BUZZER_PIN 8

struct Button {
  int pin;
  int tone;
};

Button buttons[] {
  {2, NOTE_C2},
  {3, NOTE_E2},
  {4, NOTE_G2},
  {5, NOTE_C3}
};

void setup() {}

void loop() {
  for (Button button : buttons) {
    if (digitalRead(button.pin)) {
      tone(BUZZER_PIN, button.tone, 50);
    }
  }
}
