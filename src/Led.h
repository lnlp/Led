/* Led.h
 *
 * Description:  Arduino library for controlling LEDs via GPIOs in a simple and straightforward way.
 *               Makes controlling LEDs easy using clean and simple code (e.g. on, off, toggle, flash).
 * 
 * Author:       Leonel Lopes Parente
 * License:      MIT (see LICENSE file in repository root)
 * 
 */

#ifndef LED_H_
#define LED_H_

#include <Arduino.h>

class Led 
{
public:
    enum class State {Off, On};
    enum class ActiveLevel {Low = LOW, High = HIGH};

	Led(
        const uint8_t pin, 
        const ActiveLevel activeLevel,
        const State initialState = State::Off,
        const uint8_t pinmode = OUTPUT);   // Certain MCUs/Arduino cores also support OUTPUT_OPEN_DRAIN.

	State state() const;      
    void setState(const State state);

    bool isOn() const;
    bool isOff() const;
    uint8_t pin() const;
    ActiveLevel activeLevel() const;

    void on();
    void off();
    void toggle();
    void flash(
        const uint8_t count = 2, 
        const uint16_t onTimeMs = 160, 
        const uint16_t offTimeMs = 160, 
        const uint16_t leadOffTimeMs = 200, 
        const uint16_t trailOffTimeMs = 300);

private:
    uint8_t pin_;
    ActiveLevel activeLevel_;
	State state_;
    Led();  // Disable parameterless public constructor.    
};    

#endif  // LED_H_