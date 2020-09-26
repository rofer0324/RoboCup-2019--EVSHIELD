#include <Wire.h>
#include <EVShield.h>
#include <EVs_LightSensorArray.h>

EVShield evshield(0x34, 0x36);

EVs_LightSensorArray lsa (0x14);

int V = 20;
// 1 BLANCO -- 0 NEGRO //

// REVERSE == ADELANTE -- FORWARD == ATRAS //

int S1;
int S2;
int S3;
int S4;
int S5;
int S6;
int S7;
int S8;


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

  cal = lsa.getCalibrated();

  if (cal[0] < 10) S1 = 0;
  if (cal[1] < 10) S2 = 0;
  if (cal[2] < 10) S3 = 0;
  if (cal[3] < 10) S4 = 0;
  if (cal[4] < 10) S5 = 0;
  if (cal[5] < 10) S6 = 0;
  if (cal[6] < 10) S7 = 0;
  if (cal[7] < 10) S8 = 0;

  if (cal[0] > 10) S1 = 1;
  if (cal[1] > 10) S2 = 1;
  if (cal[2] > 10) S3 = 1;
  if (cal[3] > 10) S4 = 1;
  if (cal[4] > 10) S5 = 1;
  if (cal[5] > 10) S6 = 1;
  if (cal[6] > 10) S7 = 1;
  if (cal[7] > 10) S8 = 1;


  if ((S1 == 1) && (S2 == 1) && (S3 == 1) && (S4 == 0) && (S5 == 0) && (S6 == 1) && (S7 == 1) && (S8 == 1)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V);
  }
  if ((S1 == 0) && (S2 == 0) && (S3 == 0) && (S4 == 1) && (S5 == 1) && (S6 == 1) && (S7 == 1) && (S8 == 1)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 0);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, V); //IZQUIERDA
    delay(500);
  }
  if ((S1 ==  1) && (S2 ==  1) && (S3 ==  1) && (S4 == 1 ) && (S5 == 1 ) && (S6 == 0) && (S7 == 0) && (S8 == 0)) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, V); //DERECHA
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 0);
    delay(500);
  } 
  /*else {
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, V);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, V);
  }*/
}



/*A ESTO HAZLE UNA COPIA Y SUBELO -- ESTA ES LA IDEA, SE QUE TU LO HACES DE FORMA EFICIENTE xd (Soy manco, lo sé) SO ESTE ES LA ESTRUCTURA, CON ESTO SIGUE
                          LINEA PERO COMO MANCO Y LA IDEA ES QUE SIGA LINEA COMO LAMBORGHINO, SO DIVIERTE!! */
