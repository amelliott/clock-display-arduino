#include "ClockDisplay.h"
#include "Arduino.h"

ClockDisplayConsole::ClockDisplayConsole()
{
    Serial.begin(115200);
}

ClockDisplayConsole::~ClockDisplayConsole()
{
}

void ClockDisplayConsole::displayTime(int hour, int minute, int second)
{
    char displayString[9];
    sprintf(displayString, "%02d:%02d:%02d", hour, minute, second);
    Serial.println(displayString);
    
}

void ClockDisplayConsole::displayDate(int month, int day, int year)
{
    char displayString[9];
    sprintf(displayString, "%02d-%02d-%04d", month, day, year);
    Serial.println(displayString);
}

void ClockDisplayConsole::setTimeProvider(TimeProvider* provider)
{
}

