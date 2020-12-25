//
//    FILE: AM2322.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.1
// PURPOSE: demo sketch for AM2322 I2C humidity & temperature sensor
//
// HISTORY:
// 0.1.0   2017-12-11 initial version
// 0.1.1   2020-05-03 updated to 0.2.0 version of lib.
//


#include <AM232X.h>
#define LED 3
float Humidity;
float Temperature;
AM232X AM2322;

void setup()
{
  Wire.begin();
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("LIBRARY VERSION: ");
  Serial.println(AM232X_LIB_VERSION);
  Serial.println();

  Serial.println("Type,\t\tStatus\t\t******************SENSOR******************\t  LED");
}

void loop()
{
  // READ DATA
  Serial.print("AM2322,\t");
  int status = AM2322.read();
  switch (status)
  {
    case AM232X_OK:
      Serial.print(" OK,\t\t");
      break;
    default:
      Serial.print(status);
      Serial.print("\t");
      break;
  }

  // DISPLAY DATA, sensor only returns one decimal.
  Humidity = (AM2322.getHumidity());
  Temperature = (AM2322.getTemperature());

  Serial.print("Humidity : ");
  Serial.print(Humidity);
  Serial.print(" (%)  Temperature : ");
  Serial.print(Temperature);
  Serial.print(" (C)");
  if (Temperature >= 40) {
    digitalWrite(LED, HIGH);
    Serial.print("  เปิดไฟ\n");
  } else {
    digitalWrite(LED, LOW);
    Serial.print("  ปิดไฟ\n");
  }
  delay(500);



}

// -- END OF FILE --
