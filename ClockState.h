#include "ClockDisplay.h"

class ClockState {
    public:
        ClockState() { };
        ~ClockState() { };
        virtual void enter() = 0;
        virtual void exit() = 0;
        virtual void onEncoderLeft() {};
        virtual void onEncoderRight() {};
        virtual int getHour() = 0;
        virtual int getMinute() = 0;
        virtual int getSecond() = 0;
        virtual void tick();
        virtual void setDisplay(ClockDisplay* timeDisplay);
    protected:
        ClockDisplay* display;
};

class SetTimeState : public ClockState {
    public:
        SetTimeState();
        ~SetTimeState();
        void enter();
        void exit();
        void onEncoderRight();
        void onEncoderLeft();
        int getHour();
        int getMinute();
        int getSecond();
    private:
        void setIncrement();
        volatile int increment;
        volatile int lastUpdate;
        volatile int curHour;
        volatile int curMinute;
        volatile int curSecond;
};

class DisplayTimeState : public ClockState {
    public:
        DisplayTimeState();
        ~DisplayTimeState();
        void enter();
        void exit();
        int getHour();
        int getMinute();
        int getSecond();
};
