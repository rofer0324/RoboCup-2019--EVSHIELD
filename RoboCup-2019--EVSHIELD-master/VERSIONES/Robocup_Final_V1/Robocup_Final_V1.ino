#include <Wire.h>
#include <EVShield.h>
#include <EVShieldAGS.h>
#include <EVs_EV3Color.h>

EVShield     evshield(0x34, 0x36);

EVs_EV3Color myColor1;
EVs_EV3Color myColor2;
int buz = 10;
int s1;
int s2;
#define RV digitalRead(2)
#define IR1 digitalRead(6)
#define IR2 digitalRead(9)
int RE = 0;
int H = 0;
int Y;
void setup()
{
  pinMode(buz, OUTPUT);

  Serial.begin(115200);

  evshield.init( SH_HardwareI2C );

  myColor1.init( &evshield, SH_BBS1 );
  myColor2.init( &evshield, SH_BBS2 );
  myColor1.setMode(MODE_Color_ReflectedLight);
  myColor2.setMode(MODE_Color_ReflectedLight);

  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() % 1000 < 3) {
    }
  }
  evshield.bank_a.motorReset();

}

void loop()
{
M:
  myColor1.setMode(MODE_Color_ReflectedLight);
  myColor2.setMode(MODE_Color_ReflectedLight);

  s1 = myColor1.getVal();
  s2 = myColor2.getVal();

  if (RV == 0) {
    esquivo();
  }
  if (s1 > 95 || s2 > 95) {
    evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
    tone(buz, 500);
    delay(500);
    noTone(buz);
    delay(500);
    Rescue();

  } else if (s1 > 30 && s2 > 30) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_Both, SH_Direction_Reverse, 30);
  } else if (s2 > 30) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 15);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 30);
  } else if (s1 > 30) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 30);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 15);
  } else  {
    evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);

    verde();
  }
  Serial.print(s1);
  Serial.print(" \n ");
  Serial.println(s2);

}
