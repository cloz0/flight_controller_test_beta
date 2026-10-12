#include "Telemetry.h"

// 1. Kurucu Metot
Telemetry::Telemetry() {
  agAdi = "test";
  sifre = "Ucus2026!"; 
  udpPort = 4242; 
}

// 2. Başlatma Metodu
void Telemetry::baslat() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(agAdi, sifre);

  Serial.print("--- Wi-Fi Agi Kuruldu! ---");
  Serial.print("Ag Adi: ");
  Serial.println(agAdi);
  Serial.print("Ucak IP Adresi: ");
  Serial.println(WiFi.softAPIP()); 

  udp.begin(udpPort);
}

// 3. Gönderme Metodu
void Telemetry::veriGonder(float roll, float pitch, float irtifa) {
  String paket = String(roll) + "," + String(pitch) + "," + String(irtifa);

  // İŞTE ÇÖZÜM BURADA: Metin (String) yerine doğrudan IPAddress nesnesi kullanıyoruz!
  // Sonu 255 olduğu için ağdaki herkese (Broadcast) fırlatır, bilgisayarın affetmez yakalar.
  IPAddress pcIP(192, 168, 4, 255); 

  udp.beginPacket(pcIP, udpPort);
  udp.print(paket);
  udp.endPacket();
}