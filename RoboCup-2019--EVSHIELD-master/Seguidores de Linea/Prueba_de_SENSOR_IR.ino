#include <Wire.h>
#include <EVShield.h>

EVShield evshield(0x34, 0x36);

int V = 15;

void setup() {
  Serial.begin(115200);

  evshield.init( SH_HardwareI2C);

  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() & 1000 < 3) {
    }
  }
  evshield.bank_a.motorReset();
  evshield.bank_b.motorReset();

}


void loop() {
  int RV = digitalRead(2);
  Serial.println(RV); //NEGRO 1 -- REFLEJO 0
  delay(1);

  if (RV == 0) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, V); //Atras
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, V);
    delay(2000);
  } else {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  }
}
