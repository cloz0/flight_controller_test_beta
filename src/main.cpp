#include <Arduino.h>
#include "Sensor.h"
#include "Actuator.h"
#include "ControlAlgorithm.h"
#include "Telemetry.h" // 1. Telsizin kimlik kartını ekledik

Sensor ucakSensorleri;
Actuator ucakKaslari;
ControlAlgorithm ucakBeyni;
Telemetry ucakTelsizi; // 2. Telsiz nesnemizi oluşturduk

// Zamanlama için değişkenler
unsigned long oncekiZaman = 0;
const int donguGecikmesi = 100;

void setup() {
    Serial.begin(115200);
    Serial.println("--- ESP32 Ucus Kontrolcusu Baslatiliyor ---");

    ucakSensorleri.baslat();
    ucakKaslari.baslat(); 
    ucakKaslari.showTime(); 
    
    // 3. Telsizi (Wi-Fi ağını) başlatıyoruz
    ucakTelsizi.baslat();

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
        float anlikIrtifa = ucakSensorleri.getIrtifa();

        ucakKaslari.tepkiVer(rollTepkisi, pitchTepkisi);

        // 4. Telsizi Kullan (Verileri UDP ile havaya fırlat)
        ucakTelsizi.veriGonder(anlikRoll, anlikPitch, anlikIrtifa);

        // Senin orijinal ekran çıktıların (Hiç dokunulmadı)
        Serial.print("Roll: "); 
        Serial.print(anlikRoll);
        Serial.print(" | Roll Tepkisi: "); 
        Serial.print(rollTepkisi);
    
        Serial.print(" || Pitch: "); 
        Serial.print(anlikPitch);
        Serial.print(" | Pitch Tepkisi: "); 
        Serial.print(pitchTepkisi);

        Serial.print(" || Irtifa: ");
        Serial.println(anlikIrtifa);
    }
}