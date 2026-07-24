#include <Actuator.h>

Actuator::Actuator() {
}

void Actuator::baslat() {
    pinMode(pinSolKanat, OUTPUT);
    pinMode(pinSagKanat, OUTPUT);
    pinMode(pinBurun, OUTPUT);
    pinMode(pinKuyruk, OUTPUT);

    analogWrite(pinSolKanat, 0);
    analogWrite(pinSagKanat, 0);
    analogWrite(pinBurun, 0);
    analogWrite(pinKuyruk, 0);

}

void Actuator::tepkiVer(float rollAci , float pitchAci) {

    int solPwm = 0;
    int sagPwm = 0;
    int burunPwm = 0;
    int kuyrukPwm = 0;

    if (rollAci > 2.0){
        sagPwm = map(rollAci, 2.0, 45.0, 0, 255);
    }

    else if (rollAci < -2.0) {
        solPwm = map(abs(rollAci), 2.0, 45.0, 0, 255);
    }
    

    if (pitchAci > 2.0) {
        kuyrukPwm = map(pitchAci, 2.0, 45.0, 0, 255);
    }

    else if (pitchAci < -2.0) {
        burunPwm = map(abs(pitchAci), 2.0, 45.0, 0, 255);
    }

    solPwm = constrain(solPwm, 0, 255);
    sagPwm = constrain(sagPwm, 0, 255);
    burunPwm = constrain(burunPwm, 0, 255);
    kuyrukPwm = constrain(kuyrukPwm, 0, 255);

    analogWrite(pinSolKanat, solPwm);
    analogWrite(pinSagKanat, sagPwm);
    analogWrite(pinBurun, burunPwm);
    analogWrite(pinKuyruk, kuyrukPwm);
}