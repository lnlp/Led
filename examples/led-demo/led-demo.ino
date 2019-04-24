// led-demo.ino

#include "Led.h"

// led(pin, activeLevel, initialState = Led::State::Off, pinmode = OUTPUT)
// activeLevel is the logic level (Led::ActiveLevel::High or Led::ActiveLevel::Low) when the LED is on.
// It is assumed that your board has a builtin LED (connected to pin LED_BUILTIN).
// (If not, change the pin number and/or connect an external LED.)

Led led(LED_BUILTIN, Led::ActiveLevel::Low);  //For active-low LED.
// Led led(LED_BUILTIN, Led::ActiveLevel::High);  //For active-high LED.

void printLedInfo()
{
  Serial.println("\n\nLED Demo\n");
  Serial.print("LED is currently (initially) ");  
  Serial.println(led.isOn() ? "on." : "off.");
  Serial.print("Is connected to pin ");
  Serial.print(led.pin());
  Serial.print(".\nIs active-");
  Serial.println(led.activeLevel() == Led::ActiveLevel::Low ? "low." : "high.");  
}

void setup() 
{
  Serial.begin(115200);
  printLedInfo();
  delay(5000);  //Some delay so the initial LED state can be verified.
  Serial.println("\nDemo is running");
}

void loop() 
{
  led.on();
  delay(3000);

  led.toggle();
  delay(2500);   

  // Default (double) flash while LED is off.
  led.flash();
  delay(2500);  

  // 3 standard flashes while LED is off.
  led.flash(3);
  delay(2500);  

  // 4 custom (longer) flashes while LED is off.
  led.flash(4, 400, 200);   
  delay(2500);

  led.on();
  delay(3000);

  // Default (double) flash while LED is on.
  led.flash();
  delay(3000);

  // 3 custom flashes with custom lead off and trail off times while LED is on.
  led.flash(3, 400, 200, 300, 300);   
  delay(4000);

  led.off();
  delay(5000);
}