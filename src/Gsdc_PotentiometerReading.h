#ifndef _Gsdc_PotentiometerReading_h_
#define _Gsdc_PotentiometerReading_h_

#include <stdint.h>

class Gsdc_PotentiometerReading
{
private: 
  int _potPosition;
  uint8_t _translatedAngle;
  bool _moved;
  int ReadSmoothedInput();
public:
  Gsdc_PotentiometerReading(int pot_position, uint8_t translated_angle, bool moved) 
  {
     _potPosition = pot_position;
     _translatedAngle = translated_angle;
     _moved = moved;
  }

  int GetPosition();
  uint8_t GetTranslatedAngle();
  bool MovementWasDetected();
};

#endif