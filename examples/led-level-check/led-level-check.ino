// led-level-check.ino

#include "Led.h"

// This program helps to verify if a LED is active-low or active-high.

// Whether a LED is active-low or active-high depends on the hardware configuration.
// The proper level must be specified in the constructor, otherwise on and off will be reversed.

// led(pin, activeLevel)
// activeLevel is the logic level (Led::ActiveLevel::High or Led::ActiveLevel::Low) when the LED is on.
// It is assumed that your board has a builtin LED (connected to pin LED_BUILTIN).
// (If not, change the pin number and/or connect an external LED.)

Led led(LED_BUILTIN, Led::ActiveLevel::Low);  //For active-low LED.
// Led led(LED_BUILTIN, Led::ActiveLevel::High);  //For active-high LED.

void printLedInfo()
{
  Serial.println("\n\nLED Level Check\n");
  Serial.println("This program helps to verify if a LED is active-low or active-high.\n");  
  Serial.println("Parameters specified in the Led constructor:");
  Serial.print("Pin:          ");
  Serial.println(led.pin());
  Serial.print("ActiveLevel:  Led::ActiveLevel::");
  Serial.println(led.activeLevel() == Led::ActiveLevel::Low ? "Low" : "High");  
}

void setup() 
{
  Serial.begin(115200);
  printLedInfo();
  led.on();
  Serial.print("\nIf the LED is on then it is active-");
  Serial.print(led.activeLevel() == Led::ActiveLevel::Low ? "low" : "high");
  Serial.println(" and the correct level was specified.");
  Serial.print("If it is off then try to specify level Led::ActiveLevel::");
  Serial.print(led.activeLevel() == Led::ActiveLevel::Low ? "High" : "Low");
  Serial.println(" instead.");
}

void loop() 
{ 
}