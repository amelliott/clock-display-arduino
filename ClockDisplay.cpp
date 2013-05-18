#include "ClockDisplay.h"
#include "Arduino.h"
#include "Time.h"

ConsoleClockDisplay::ConsoleClockDisplay()
{
    Serial.begin(115200);
    blinking = false;
}

ConsoleClockDisplay::~ConsoleClockDisplay()
{
}

void ConsoleClockDisplay::displayTime()
{
    char displayString[9];
    if (blinking && second() % 2 == 1)
        sprintf(displayString, "OFF");
    else
        sprintf(displayString, "%02d:%02d:%02d", hour(), minute(), second());
    Serial.println(displayString);
    
}

void ConsoleClockDisplay::startBlink()
{
    blinking = true;
}

void ConsoleClockDisplay::stopBlink()
{
    blinking = false;
}
