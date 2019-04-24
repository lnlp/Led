#include "Led.h"

Led::Led(
    const uint8_t pin, 
    const ActiveLevel activeLevel,  // LOW or HIGH, the logic level for LED to be off.
    const State initialState,
    const uint8_t pinmode)      // OUTPUT, some Arduino cores also support OUTPUT_OPEN_DRAIN.
{
    pin_ = pin;
    activeLevel_ = activeLevel;
    // Initialize state_ to inverse of initialState otherwise 
    // setState(initialState) will not set state. 
    state_ = (initialState == State::Off ? State::On : State::Off); 
    pinMode(pin, pinmode);
    setState(initialState);
}


Led::State Led::state() const
{
    return state_;
} 


void Led::setState(const State state)
{
    // Only perform actions when state is different from current state_.
    if (state != state_)
    {
        if (state == State::On)
            digitalWrite(pin_, static_cast<uint8_t>(activeLevel_));        // LOW or HIGH
        else
            digitalWrite(pin_, static_cast<uint8_t>(activeLevel_) ^ 1);    // For On use inverse of value for Off.
        state_ = state;
    }
}


uint8_t Led::pin() const
{
    return pin_;
}    


Led::ActiveLevel Led::activeLevel() const
{
    return activeLevel_;
}


void Led::on()
{
    setState(State::On);
}


void Led::off()
{
    setState(State::Off);
}    


bool Led::isOn() const
{
    return (state_ == State::On ? true : false);
}


bool Led::isOff() const
{
    return !isOn();
}


void Led::toggle()
{
    setState(state_ == State::On ? State::Off : State::On);
}


void Led::flash(
    const uint8_t count, 
    const uint16_t onTimeMs, 
    const uint16_t offTimeMs, 
    const uint16_t leadOffTimeMs, 
    const uint16_t trailOffTimeMs)
{
    // Simple flash implementation.
    // Synchronous, caller has to wait for completion.
    // leadOffTimeMs and trailOffTimeMs are only
    // used if LED is currently on.
    
    State savedState = state_;

    if (savedState == Led::State::On)
    {
        setState(State::Off);
        delay(leadOffTimeMs);
    }

    for (uint8_t flash = 0; flash < count; ++flash)
    {
        setState(State::On);
        delay(onTimeMs);

        if (flash < count - 1)
        {
            setState(State::Off);
            delay(offTimeMs);                
        }
    }

    if (savedState == Led::State::On)
    {
        setState(State::Off);
        delay(trailOffTimeMs);
    }
    setState(savedState);
}





