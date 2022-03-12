#include "states.h"
#include <Arduino.h>
#include "constants.h"
#include <CurieBLE.h>

class Ble {
    public:
        Ble(){};
        void loop(States* states);
        void setup();

    private:
};