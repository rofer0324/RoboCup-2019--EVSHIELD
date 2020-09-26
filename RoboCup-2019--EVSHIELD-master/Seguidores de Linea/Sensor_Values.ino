#include <Wire.h>
#include <EVShield.h>
#include <EVs_LightSensorArray.h>

EVShield    evshield(0x34,0x36);

EVs_LightSensorArray lsa (0x14);

void setup()
{
  Serial.begin(115200);  
  evshield.init( SH_HardwareI2C );
  lsa.init( &evshield, SH_BAS1 );
  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() % 1000 < 3) {
      Serial.println("Press GO button to continue");
    }
  }
}

void loop()
{
  char str[256];               
  uint8_t *cal;         
  int  i;               
  
  cal = lsa.getCalibrated();
  for (i=0; i< 8; i++)
  {    
    sprintf (str, "LSArray: sensor array: %d = %d", i, cal[i] );
    Serial.println(str);
  }
  delay(1000);
}
