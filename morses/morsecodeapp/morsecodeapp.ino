#include "letters.hpp"
#include "display.hpp"

int buttonPin = 3; 
int buttonState = 0;
int lastButtonState = 0;
unsigned long startPressTime = 0;
unsigned long startReleaseTime = 0;

String letterBuffer = "";
String translatedBuffer = "";

int displayCount = 4;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(buttonPin, INPUT);

  setupLeds(displayCount);
  displayString("9y", displayCount);
}

void printLetterBuffer() {
  Letter result = findLetter(letterBuffer.c_str());

  if (result.representation != ' ') {
    // todo
    return;
  }

  Serial.println(result.representation);
}

// handles when the button is clicked
void handleClick(unsigned long pressTime) {
  // long
  if (pressTime > 130) {
    letterBuffer.concat("_");
  } else if (pressTime <= 130) {
    letterBuffer.concat(".");
  }

  if (letterBuffer.length() == 5) {
    printLetterBuffer();
    letterBuffer = "";
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    if (lastButtonState == LOW) {
      startPressTime = millis();
    }

    startReleaseTime = millis();
  } else {
    if (lastButtonState == HIGH) {
      unsigned long pressTime = millis() - startPressTime;
      if (pressTime > 20) {
        handleClick(pressTime);
      }
    }
  }

  if (millis() - startReleaseTime > 500) {
    printLetterBuffer();
    letterBuffer = "";
  }

  lastButtonState = buttonState;
}