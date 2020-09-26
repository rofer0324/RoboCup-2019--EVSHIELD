#include <Wire.h>
#include <EVShield.h>
#include <EVs_LightSensorArray.h>

EVShield evshield(0x34, 0x36);

EVs_LightSensorArray lsa (0x14);

int V = 15;

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
}

void loop() {

  char str[256];
  uint8_t *cal;
  int i;

  int S1 = cal[0];
  int S3 = cal[2];
  int S6 = cal[5];
  int S8 = cal[7];

  cal = lsa.getCalibrated();

  if ((S3 < 5) && (S6 < 5)) {
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //ADELANTE
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  }
  if ((S1 < 5) && (S3 < 5) && (S6 > 10) && (S8 > 10)) {
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, V); //IZQUIERDA
  }
  if ((S1 > 10) && (S3 > 10) && (S6 < 5) && (S8 < 5)) {
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, V); //DERECHA
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  }
  if ((S1 < 5) && (S3 > 5) && (S6 > 5) && (S8 > 10)) {
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //PICO IZ
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, V);
  }
  if ((S1 > 10) && (S3 > 5) && (S6 > 5) && (S8 < 5)) {
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, V); //PICO DER
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  }
}
