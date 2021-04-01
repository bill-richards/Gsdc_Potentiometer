#include "Gsdc_Potentiometer.h"

////////////////////
// STATIC MEMBERS //
////////////////////
float Gsdc_Potentiometer::EMA_a = 0.2;      // 0.0 ~ 1.0 where lower value = more samples and slower speed: default 0.2
int Gsdc_Potentiometer::EMA_S = 0;

int Gsdc_Potentiometer::GetSmoothedPositionValue(uint8_t data_pin)
{
  int value = analogRead(data_pin);
  EMA_S = (EMA_a*value) + ((1-EMA_a)*EMA_S); 
  return EMA_S;
}


//////////////////////
// INSTANCE MEMBERS //
//////////////////////
Gsdc_Potentiometer::Gsdc_Potentiometer(uint8_t dataPin) 
{ 
  _dataPin = dataPin; 
  _lastKnownPotentiometerReading = 0;
}

Gsdc_PotentiometerReading Gsdc_Potentiometer::GetPosition()
{
  bool potentiometerMoved = false;
  int potentiometerCurrentValue = Gsdc_Potentiometer::GetSmoothedPositionValue(_dataPin);
  long angleOfServoRotation = map(potentiometerCurrentValue, 0, 1023, 0, 180);

  if(potentiometerCurrentValue != _lastKnownPotentiometerReading) 
  {
    _lastKnownPotentiometerReading = potentiometerCurrentValue;
    potentiometerMoved = true;
  }

  return Gsdc_PotentiometerReading(_lastKnownPotentiometerReading, angleOfServoRotation, potentiometerMoved);
}
