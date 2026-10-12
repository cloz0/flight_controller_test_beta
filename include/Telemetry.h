#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <WiFi.h>
#include <WiFiUdp.h>

class Telemetry {
  private:
    // Wi-Fi Ağ Ayarları (Access Point)
    const char* agAdi;
    const char* sifre;

    // Hedef Bilgisayar Ayarları (CachyOS IP'si ve Port)
    const char* hedefIP;
    uint16_t udpPort;

    // UDP paketlerini yönetecek nesnemiz
    WiFiUDP udp;

  public:
    // Kurucu metot (Sistem açıldığında değişkenleri tanımlar)
    Telemetry();

    // Wi-Fi ağını havada yayınlamaya başlar
    void baslat();

    // Sensör verilerini alıp UDP paketi olarak bilgisayara fırlatır
    void veriGonder(float roll, float pitch, float irtifa);
};

#endif