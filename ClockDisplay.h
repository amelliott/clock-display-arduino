
class ClockDisplay {
    public:
        virtual void displayTime() = 0;
};

class ConsoleClockDisplay : public ClockDisplay {
    public:
        ConsoleClockDisplay();
        ~ConsoleClockDisplay();
        void displayTime();
};

