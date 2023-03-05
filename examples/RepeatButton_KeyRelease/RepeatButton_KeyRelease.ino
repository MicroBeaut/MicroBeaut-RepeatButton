/*
  RepeatButton_KeyRelease.ino
  Created:  4-Mar-2023
  Author:   MicroBeaut
*/

/*
  The KeyRelease event occurs when released a key.
*/

#include "RepeatButton.h"

#define buttonPin 2                 // Define the button input pin.

RepeatButton button;                // Decalre the RepeatButton object

void OnKeyReleased(ButtonEvents e); // Declare the OnKeyReleased Callback Function

void setup() {
  Serial.begin(115200);
  button.buttonMode(buttonPin, INPUT_PULLUP); // Set the button mode
  button.onKeyReleased(OnKeyReleased);        // Configure the callback function event on the key released
  pinMode(LED_BUILTIN, OUTPUT);               // Set the LED_BUILTIN mode
}

void loop() {
  button.repeatButton();                      // Executing the Repeat button function
  if (button.isKeyReleased()) {
    digitalWrite(LED_BUILTIN, HIGH);          // Turned LED ON
  } else {
    digitalWrite(LED_BUILTIN, LOW);           // Turned LED OFF
  }
}

void OnKeyReleased(ButtonEvents e) {
  Serial.println("Event on Key Released");    // Print message event on key Released
}