#include "ClockState.h"
#include "Arduino.h"
#include "Time.h"

void ClockState::setDisplay(ClockDisplay* timeDisplay)
{
    display = timeDisplay;
}

void ClockState::tick()
{
    display->displayTime(getHour(), getMinute(), getSecond());
}

SetTimeState::SetTimeState()
{
    increment = 0;
    lastUpdate = 0;
    curHour = 0;
    curMinute = 0;
    curSecond = 0;  // stays 0
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
    setTime(curHour, curMinute, curSecond, day(), month(), year());
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
    tick();
}

void SetTimeState::setIncrement()
{
    int time = millis();
    if ((time - lastUpdate) < 100) {
        increment = 10;
    }
    else if ((time - lastUpdate) > 500) {
        increment = 1;
    }
    lastUpdate = time;
    tick();
}

int SetTimeState::getHour()
{
    return curHour;
}

int SetTimeState::getMinute()
{
    return curMinute;
}

int SetTimeState::getSecond()
{
    return curSecond;
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

int DisplayTimeState::getSecond()
{
    return second();
}