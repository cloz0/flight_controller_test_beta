#include <Arduino.h>
#include "Sensor.h"

Sensor ucakSensorleri;

unsigned long oncekiZaman = 0;
const int gonguGecikmesi = 100;

void setup() {

    Serial.begin(115200);

    Serial.println("Baslatiliyor...");

    ucakSensorleri.baslat();

    Serial.println("Sistem baslatildi.");
    delay(2000);
}

void loop() {

    unsigned long simdikiZaman = millis();

    if (simdikiZaman - oncekiZaman >= gonguGecikmesi) {
        oncekiZaman = simdikiZaman;

        ucakSensorleri.guncelle();

        float rollAci = ucakSensorleri.getRollAci();
        float pitchAci = ucakSensorleri.getPitchAci();
        float irtifa = ucakSensorleri.getIrtifa();

        Serial.print("Roll Aci: ");
        Serial.print(rollAci);
        Serial.print(" | Pitch Aci: ");
        Serial.print(pitchAci);
        Serial.print(" | Irtifa: ");
        Serial.println(irtifa);
    }
}