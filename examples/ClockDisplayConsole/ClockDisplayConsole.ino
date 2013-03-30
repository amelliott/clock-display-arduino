#include "ClockDisplay.h"

ClockDisplay * clockDisplay;
int lastUpdate = millis();

void setup()
{
  clockDisplay = new ClockDisplayConsole();
}

void loop()
{
  if (millis() - lastUpdate > 1000)
  {
    clockDisplay->displayTime(12, 34, 56);
    lastUpdate = millis();
  }
}
