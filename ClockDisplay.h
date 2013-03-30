
class TimeProvider;

class ClockDisplay {
    //enum HourMode {12Hour, 24Hour};

    public:
        virtual void displayTime(int hour, int minute, int second) = 0;
        virtual void displayDate(int month, int day, int year) = 0;
        virtual void setTimeProvider(TimeProvider* provider) = 0;
        //virtual void setHourMode(HourMode mode) = 0;
};

class ClockDisplayConsole : public ClockDisplay {
    public:
        ClockDisplayConsole();
        ~ClockDisplayConsole();
        void displayTime(int hour, int minute, int second);
        void displayDate(int month, int day, int year);
        void setTimeProvider(TimeProvider* provider);
};