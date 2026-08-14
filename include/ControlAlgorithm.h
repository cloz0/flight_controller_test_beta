#ifndef CONTROL_ALGORITHM_H
#define CONTROL_ALGORITHM_H

class ControlAlgorithm {
  private:

  float kpRoll;
    float kpPitch;

    float hedefRoll;
    float hedefPitch;

  public:

  ControlAlgorithm();

    float hesaplaRollTepkisi(float gercekRoll);
    float hesaplaPitchTepkisi(float gercekPitch);
};

#endif