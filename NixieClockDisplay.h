#include "ClockDisplay.h"
#include "NixieTube.h"

class NixieClockDisplay : public ClockDisplay {
    public:
        NixieClockDisplay();
        NixieClockDisplay(int, int, int, int);
        ~NixieClockDisplay();
        void displayTime();
        void displayDate();
        void startBlink();
        void stopBlink();
    private:
        bool needToBlink();
        void updateDisplay(char*);
        bool blinking;
        char displayString[9];
        NixieTube* tube;
};

