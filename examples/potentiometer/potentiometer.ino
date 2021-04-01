#include <Gsdc_Potentiometer.h>


#define POT_PIN A0

Gsdc_Potentiometer _myPotentiometer = Gsdc_Potentiometer(POT_PIN);

void setup() 
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Potentiometer Demo");
}

void loop()
{
    Gsdc_PotentiometerReading pot_reading = _myPotentiometer.GetPosition();

    if(pot_reading.MovementWasDetected())
    {
      uint8_t newAngle = pot_reading.GetTranslatedAngle();
      int pot_position = pot_reading.GetPosition();
      Serial.print((String)"Current poition ["+pot_position+"] : Translated Angle ["+newAngle+"]");
    }

    delay(50);
}
