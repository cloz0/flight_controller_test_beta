#ifndef Sensor_h
#define Sensor_h

#include <Adafruit_BMP280.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

class Sensor {
    private:
        Adafruit_BMP280 bmp;
        Adafruit_MPU6050 mpu;

        float rollAci;
        float pitchAci;
        float irtifa;

    public:
        Sensor();

        void baslat();
        void guncelle();

        float getRollAci();
        float getPitchAci();
        float getIrtifa();
        
};

#endif