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
    clockDisplay->displayDate(1, 2, 2013);
    lastUpdate = millis();
  }
}
