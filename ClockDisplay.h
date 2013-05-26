#ifndef CLOCK_DISPLAY_H
#define CLOCK_DISPLAY_H

class ClockDisplay {
    public:
        virtual void displayTime() = 0;
        virtual void displayDate() = 0;
        virtual void startBlink() = 0;
        virtual void stopBlink() = 0;
};

class ConsoleClockDisplay : public ClockDisplay {
    public:
        ConsoleClockDisplay();
        ~ConsoleClockDisplay();
        void displayTime();
        void displayDate();
        void startBlink();
        void stopBlink();
    private:
        bool needToBlink();
        void updateDisplay(char*);
        bool blinking;
        char displayString[9];
};

#endif
