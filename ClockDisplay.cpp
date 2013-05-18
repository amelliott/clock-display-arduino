#include "ClockDisplay.h"
#include "Arduino.h"
#include "Time.h"

ConsoleClockDisplay::ConsoleClockDisplay()
{
    Serial.begin(115200);
}

ConsoleClockDisplay::~ConsoleClockDisplay()
{
}

void ConsoleClockDisplay::displayTime()
{
    char displayString[9];
    sprintf(displayString, "%02d:%02d:%02d", hour(), minute(), second());
    Serial.println(displayString);
    
}

