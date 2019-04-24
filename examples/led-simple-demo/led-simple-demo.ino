// led-simple-demo.ino

#include "Led.h"

// led(pin, activeLevel)
// activeLevel is the logic level (Led::ActiveLevel::High or Led::ActiveLevel::Low) when the LED is on.
// It is assumed that your board has a builtin LED (connected to pin LED_BUILTIN).
// (If not, change the pin number and/or connect an external LED.)

Led led(LED_BUILTIN, Led::ActiveLevel::Low);  //For active-low LED.
// Led led(LED_BUILTIN, Led::ActiveLevel::High);  //For active-high LED.

void setup() 
{
  delay(1000);
}

void loop() 
{
  led.on();
  delay(2500);

  led.toggle();
  delay(2500);

  led.on();
  delay(2500);  

  led.off();
  delay(2500);   

  led.flash();
  delay(2500);  
}