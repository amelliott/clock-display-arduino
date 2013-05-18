
class ClockDisplay {
    public:
        virtual void displayTime() = 0;
        virtual void startBlink() = 0;
        virtual void stopBlink() = 0;
};

class ConsoleClockDisplay : public ClockDisplay {
    public:
        ConsoleClockDisplay();
        ~ConsoleClockDisplay();
        void displayTime();
        void startBlink();
        void stopBlink();
    private:
        bool blinking;
};

