#include "Gsdc_PotentiometerReading.h"

int Gsdc_PotentiometerReading::GetPosition() { return _potPosition; }
uint8_t Gsdc_PotentiometerReading::GetTranslatedAngle() {return _translatedAngle; }
bool Gsdc_PotentiometerReading::MovementWasDetected() { return _moved; }