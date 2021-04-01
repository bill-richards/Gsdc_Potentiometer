#ifndef _Gsdc_Potentiometer_h_
#define _Gsdc_Potentiometer_h_

#include <Arduino.h>
#include "Gsdc_PotentiometerReading.h"

class Gsdc_Potentiometer
{
private:
  static float EMA_a; 
  static int EMA_S;

  int _lastKnownPotentiometerReading;
  uint8_t _dataPin;

public:
  Gsdc_Potentiometer(uint8_t dataPin);
  Gsdc_PotentiometerReading GetPosition();

  static int GetSmoothedPositionValue(uint8_t dataPin);
};

#endif