#include <Arduino.h>
#include "Sensor.h"
#include "Actuator.h"
#include "ControlAlgorithm.h"

Sensor ucakSensorleri;
Actuator ucakKaslari;
ControlAlgorithm ucakBeyni;

// Zamanlama için değişkenler
unsigned long oncekiZaman = 0;
const int donguGecikmesi = 100;

void setup() {
    Serial.begin(115200);
    Serial.println("--- ESP32 Ucus Kontrolcusu Baslatiliyor ---");

    ucakSensorleri.baslat();
    ucakKaslari.baslat(); 
    ucakKaslari.showTime(); 
    
    Serial.println("Sistem hazir!...");
    delay(100); 
}

void loop() {
    unsigned long suankiZaman = millis();

    if (suankiZaman - oncekiZaman >= donguGecikmesi) {
        oncekiZaman = suankiZaman;

        ucakSensorleri.guncelle();

        float anlikRoll = ucakSensorleri.getRollAci();
        float anlikPitch = ucakSensorleri.getPitchAci();

        float rollTepkisi = ucakBeyni.hesaplaRollTepkisi(anlikRoll);
        float pitchTepkisi = ucakBeyni.hesaplaPitchTepkisi(anlikPitch);

        ucakKaslari.tepkiVer(rollTepkisi, pitchTepkisi);

        Serial.print("Roll: "); 
        Serial.print(anlikRoll);
        Serial.print(" | Roll Tepkisi (Hata): "); 
        Serial.print(rollTepkisi);
    
        Serial.print(" || Pitch: "); 
        Serial.print(anlikPitch);
        Serial.print(" | Pitch Tepkisi (Hata): "); 
        Serial.println(pitchTepkisi);
    }
}