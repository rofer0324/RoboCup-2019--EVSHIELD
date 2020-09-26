#include <Wire.h>
#include <EVShield.h>
#include <EVs_LightSensorArray.h>

EVShield evshield(0x34, 0x36);

EVs_LightSensorArray lsa (0x14);

int V = 20;

// 1 BLANCO -- 0 NEGRO //

// REVERSE == ADELANTE -- FORWARD == ATRAS //


void setup() {
  Serial.begin(115200);

  evshield.init( SH_HardwareI2C);
  lsa.init( &evshield, SH_BAS1);

  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() & 1000 < 3) {
    }
  }
  evshield.bank_a.motorReset();
  evshield.bank_b.motorReset();
}

void loop() {
  char str[256];
  uint8_t *cal;
  int i;

  int S1 = cal[0];
  int S2 = cal[1];
  int S3 = cal[2];
  int S4 = cal[3];
  int S5 = cal[4];
  int S6 = cal[5];
  int S7 = cal[6];
  int S8 = cal[7];

  cal = lsa.getCalibrated();


  if ((S1 > 10) && (S2 > 10) && (S3 > 10) && (S4 < 3) && (S5 < 3) && (S6 > 10) && (S7 > 10) && (S8 > 10)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  }
  if ((S1 < 3) && (S2 < 3) && (S3 < 3) && (S4 > 10) && (S5 > 10) && (S6 > 10) && (S7 > 10) && (S8 > 10)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 0);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V); //IZQUIERDA
    delay(500);
  }
  if ((S1 > 10) && (S2 > 10) && (S3 > 10) && (S4 > 10) && (S5 > 10) && (S6 < 3) && (S7 < 3) && (S8 < 3)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //DERECHA
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 0);
    delay(500);
  }  
  if ((S1 < 3) && (S2 < 3) && (S3 < 3) && (S4 < 3) && (S5 < 3) && (S6 < 3) && (S7 > 10) && (S8 > 10)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 0);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
    delay(500);
  }
  if ((S1 > 10) && (S2 > 10 ) && (S3 < 3 ) && (S4 < 3 ) && (S5 < 3) && (S6 < 3) && (S7 < 3) && (S8 < 3)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 0);
    delay(500);
  } /*else {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, V);
  }*/
}
