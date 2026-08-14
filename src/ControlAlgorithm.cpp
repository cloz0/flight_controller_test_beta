#include "ControlAlgorithm.h"


ControlAlgorithm::ControlAlgorithm() {

    kpRoll = 1.0;
    kpPitch = 1.0;

    hedefRoll = 0.0;
    hedefPitch = 0.0;
}

float ControlAlgorithm::hesaplaRollTepkisi(float gercekRoll) {

    float hata = hedefRoll - gercekRoll;
  
    float pTepkisi = hata * kpRoll;
  
    return pTepkisi;
}

float ControlAlgorithm::hesaplaPitchTepkisi(float gercekPitch) {

    float hata = hedefPitch - gercekPitch;
    float pTepkisi = hata * kpPitch;
  
    return pTepkisi;
}