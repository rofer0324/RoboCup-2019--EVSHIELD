#include <Wire.h>
#include <EVShield.h>
EVShield evshield(0x34, 0x36);

void setup() {
  evshield.init( SH_HardwareI2C);
  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() & 1000 < 3) {
    }
  }
  evshield.bank_a.motorReset();
}

void loop() {
 
  // put your main code here, to run repeatedly:
 evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, V); //Atras
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, V);
  delay(1000);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 35); //DERECHA
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 35);
  delay(1700);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //ADELANTE
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  delay(1900);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 35); //IZQUIERDA
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 35);
  delay(1600);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //ADELANTE
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  delay(1400);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 35); //IZQUIERDA
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 35);
  delay(1300);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //ADELANTE
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  delay(1400);
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 35); //DERECHA
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 35);
  delay(1500);
}
