#ifndef ACUTATOR_H
#define ACUTATOR_H

#include <Arduino.h>

class Actuator {

    private:
        const int pinSolKanat = 25;
        const int pinSagKanat = 26;
        const int pinBurun = 27;
        const int pinKuyruk = 14;

    public:
        Actuator();

        void baslat();

        void showTime();

        void tepkiVer(float rollAci, float pitchAci);
};


#endif