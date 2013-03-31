#include "ClockState.h"
#include "Arduino.h"
#include "Time.h"

void ClockState::onEncoderLeft()
{
}

void ClockState::onEncoderRight()
{
}

SetTimeState::SetTimeState()
{
    increment = 0;
    lastUpdate = 0;
    curHour = 0;
    curMinute = 0;
}

SetTimeState::~SetTimeState()
{
}

void SetTimeState::enter()
{
    increment = 1;
    lastUpdate = millis();
    curHour = hour();
    curMinute = minute();
}

void SetTimeState::exit()
{
    // set clock
    setTime(curHour, curMinute, second(), day(), month(), year());
}

void SetTimeState::onEncoderLeft()
{
    setIncrement();
    curMinute -= increment;
    if (curMinute < 0)
    {
        curMinute = 59 + curMinute % 60;
        --curHour;
        if (curHour < 0)
        {
            curHour = 23;
        }
    }
}

void SetTimeState::onEncoderRight()
{
    setIncrement();
    curMinute += increment;
    if (curMinute > 59)
    {
        curMinute %= 60;
        ++curHour;
        if (curHour == 24)
        {
            curHour = 0;
        }
    }
}

void SetTimeState::setIncrement()
{
    int time = millis();
    if ((time - lastUpdate) < 100) {
        //Serial.println("FAST");
        increment = 10;
    }
    else if ((time - lastUpdate) > 500) {
        //Serial.println("SLOW");
        increment = 1;
    }
    lastUpdate = time;
}

int SetTimeState::getHour()
{
    return curHour;
}

int SetTimeState::getMinute()
{
    return curMinute;
}

DisplayTimeState::DisplayTimeState()
{
}

DisplayTimeState::~DisplayTimeState()
{
}

void DisplayTimeState::enter()
{
}

void DisplayTimeState::exit()
{
}

int DisplayTimeState::getHour()
{
    return hour();
}

int DisplayTimeState::getMinute()
{
    return minute();
}

void DisplayTimeState::tick()
{
    display->displayTime(getHour(), getMinute(), 0);
}

void DisplayTimeState::setDisplay(ClockDisplay* clockDisplay)
{
    display = clockDisplay;
}
