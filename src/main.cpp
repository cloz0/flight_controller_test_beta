#include <Arduino.h>
#include "Sensor.h"
#include "Actuator.h"

Sensor ucakSensorleri;
Actuator ucakKaslari;

// Zamanlama için değişkenler
unsigned long oncekiZaman = 0;
const int donguGecikmesi = 100;

void setup() {
    Serial.begin(115200);
    Serial.println("--- ESP32 Ucus Kontrolcusu Baslatiliyor ---");

    // Sensörleri ve LED pinlerini fiziksel olarak uyandır
    ucakSensorleri.baslat();
    ucakKaslari.baslat(); // LED pinlerini OUTPUT yaptık ve sönük başlattık

    ucakKaslari.showTime(); // LED'leri yanıp söndürerek sistemin hazır olduğunu göster
    
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

        // Değerleri bilgisayar ekranında da görmek için yazdırıyoruz
        Serial.print("Roll: ");
        Serial.print(anlikRoll);
        Serial.print(" | Pitch: ");
        Serial.println(anlikPitch);
        Serial.print(" | Irtifa: ");
        Serial.println(ucakSensorleri.getIrtifa());

        ucakKaslari.tepkiVer(anlikRoll, anlikPitch);
    }
}