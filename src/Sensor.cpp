#include "Sensor.h"
#include <Arduino.h>

Sensor::Sensor() {
    rollAci = 0.0;
    pitchAci = 0.0;
    irtifa = 0.0;
}

void Sensor::baslat() {

    if (!mpu.begin()) {
            Serial.println("MPU6050 sensor not found!");
            while (1);
        }

    if (!bmp.begin(0x76)) {
        Serial.println("BMP280 sensor not found!");
        while (1);
    }

    
    Serial.println("Sensors initialized successfully.");

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void Sensor::guncelle() {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    rollAci = -atan2(a.acceleration.y, a.acceleration.z) * 180.0 / PI;        //$\text{Roll} = \arctan\left(\frac{a_y}{a_z}\right) \times \left(\frac{180}{\pi}\right)$
    pitchAci = atan2(-a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180.0 / PI;     //$\text{Pitch} = \arctan\left(\frac{-a_x}{\sqrt{a_y^2 + a_z^2}}\right) \times \left(\frac{180}{\pi}\right)$

    irtifa = bmp.readAltitude(1013.25);
}

float Sensor::getRollAci() {
    return rollAci;
}

float Sensor::getPitchAci() {
    return pitchAci;
}

float Sensor::getIrtifa() {
    return irtifa;
}
