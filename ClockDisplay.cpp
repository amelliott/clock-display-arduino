#include "ClockDisplay.h"
#include "Arduino.h"

ConsoleClockDisplay::ConsoleClockDisplay()
{
    Serial.begin(115200);
}

ConsoleClockDisplay::~ConsoleClockDisplay()
{
}

void ConsoleClockDisplay::displayTime(int hour, int minute, int second)
{
    char displayString[9];
    sprintf(displayString, "%02d:%02d:%02d", hour, minute, second);
    Serial.println(displayString);
    
}

void ConsoleClockDisplay::displayDate(int month, int day, int year)
{
    char displayString[9];
    sprintf(displayString, "%02d-%02d-%04d", month, day, year);
    Serial.println(displayString);
}

void ConsoleClockDisplay::clear()
{
    Serial.println("");
}
