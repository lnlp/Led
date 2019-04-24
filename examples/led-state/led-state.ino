// led-state.ino

#include "Led.h"

// This example demonstrates how to save and restore LED state (whether it is on or off).

// led(pin, activeLevel)
// activeLevel is the logic level (Led::ActiveLevel::High or Led::ActiveLevel::Low) when the LED is on.
// It is assumed that your board has a builtin LED (connected to pin LED_BUILTIN).
// (If not, change the pin number and/or connect an external LED.)

Led led(LED_BUILTIN, Led::ActiveLevel::Low);  //For active-low LED.
// Led led(LED_BUILTIN, Led::ActiveLevel::High);  //For active-high LED.

void doLedStuff()
{
  led.toggle();
  delay(1000);   

  led.flash();
  delay(1000);   
}

void setup() 
{
  led.on();
}

void loop() 
{
  delay(2000);

  // Save current LED state.
  Led::State savedState = led.state();

  doLedStuff();

  // Restore saved state.
  led.setState(savedState);
}