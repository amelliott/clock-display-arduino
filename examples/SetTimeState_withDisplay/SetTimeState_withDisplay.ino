#include "Arduino.h"
#include "Encoder.h"
#include "Button.h"
#include "Time.h"
#include "ClockState.h"
//#include "NixieTube.h"

//NixieTube tube(10, 11, 12, 9, 4);

Encoder * setEncoder;
Button * setButton;

ClockState * curState;
SetTimeState setTimeState;
DisplayTimeState timeDisplayState;

ClockDisplay * clockDisplay;

void setup_timers() {
  cli();
  // set utimer
  SIM_SCGC6 |= SIM_SCGC6_PIT; // Activates the clock for PIT
  // Turn on PIT
  PIT_MCR = 0;
  sei();
}

void start_timer(float period) {
  PIT_LDVAL1 = floor(F_BUS * period - .5);
  PIT_TCTRL1 = 3;
  NVIC_ENABLE_IRQ(IRQ_PIT_CH1); // Another step to enable PIT channel 1 interrupts
}

void stop_timer() {
  NVIC_DISABLE_IRQ(IRQ_PIT_CH1);
  PIT_TCTRL1 = 0;
}

void setup()
{
  clockDisplay = new ConsoleClockDisplay();
  timeDisplayState.setDisplay(clockDisplay);
  setTimeState.setDisplay(clockDisplay);
  setSyncProvider(Teensy3Clock.get);
  curState = &timeDisplayState;
  curState->enter();
  setEncoder = EncoderManager::registerEncoder(4, 5, onEncoderLeft, onEncoderRight);
  setButton = ButtonManager::registerButton(0, 25, onSetButtonPressed);
  setup_timers();
  start_timer(1);
}

void pit1_isr(void) {
  PIT_TFLG1 = 1;
  curState->tick();
}

void loop()
{
}

void onEncoderRight()
{
  curState->onEncoderRight();
}

void onEncoderLeft()
{
  curState->onEncoderLeft();
}

void onSetButtonPressed()
{
  curState->exit();
  if (curState == &timeDisplayState)
  {
    Serial.println("Entering SetTimeState");
    curState = &setTimeState;
  }
  else if (curState == &setTimeState)
  {
    Serial.println("Entering TimeDisplayState");
    curState = &timeDisplayState;
  }
  curState->enter();
}

