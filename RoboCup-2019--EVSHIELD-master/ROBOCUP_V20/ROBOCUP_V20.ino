#include <Wire.h>
#include <EVShield.h>
#include <EVs_LightSensorArray.h>

EVShield evshield(0x34, 0x36);

EVs_LightSensorArray lsa (0x14);

int V = 30;
int v = 30;
int kp = 10;
int P = 0;
int I = 0;
int D = 0;
int kd = 33;
int LE = 0;
int e = 0;
int vel;
int FG = 0;
int buz = 10;

int RE = 0;
int H = 0;

int Bo1 = 3;
int Bo2 = 5;

#define RV digitalRead(2)
byte test = 1;
void setup() {
  pinMode(buz, OUTPUT);
  pinMode(Bo1, INPUT);
  pinMode(Bo2, INPUT);
  char str[256];
  Serial.begin(115200);
  delay(500);

  evshield.init( SH_HardwareI2C);
  lsa.init( &evshield, SH_BAS1);

  while (test == 1) {
    evshield.bank_a.ledSetRGB(0, 0, 255);
    evshield.waitForButtonPress(BTN_LEFT);
    lsa.calibrateWhite();
    delay(100);
    evshield.bank_b.ledSetRGB(0, 0, 255);
    evshield.waitForButtonPress(BTN_RIGHT);
    lsa.calibrateBlack();
    delay(100);
    test = 2;
  }

  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() & 1000 < 3) {
      evshield.bank_a.ledSetRGB(0, 255, 255);
      delay(100);
      evshield.bank_a.ledSetRGB(0, 0, 0);
    }
  }

  evshield.bank_a.motorReset();
}
#define DELAY_T 0

void loop() {
  noTone(buz);
  FG = 0;
  char aa[80];
  char str[256];
  uint8_t  result;
  char str2[20];
  uint8_t *cal;

  cal = lsa.getCalibrated();
  if (cal[0] < 20) e = -4;
  if (cal[1] < 30) e = -2;
  if (cal[2] < 30) e = -1;
  if (cal[3] < 30) e = 0;
  if (cal[4] < 30) e = 0;
  if (cal[5] < 30) e = 1;
  if (cal[6] < 30) e = 2;
  if (cal[7] < 20) e = 4;

  if (RV == 0) FG = 1;
  if (cal[0] > 30 && cal[1] > 30 && cal[2] > 30 && cal[3] > 30 && cal[4] > 30 && cal[5] > 30 && cal[6] > 30 && cal[7] > 30) FG = 3;
  if (cal[0] > 80 && cal[1] > 80 && cal[2] > 80 && cal[3] > 80 && cal[4] > 80 && cal[5] > 80 && cal[6] > 80 && cal[7] > 80) FG = 2;

  switch (FG) {

    case 1:
      esquivo();
      break;

    case 2:
      evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
      tone(buz, 500);
      delay(500);
      noTone(buz);
      delay(500);
      Rescue();
      break;

    case 3:
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 20);
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 20);
      break;
    case 4:
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 20);
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 20);
      delay(500);

      break;

    case 5:
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 20);
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 20);
       delay(500);
      break;
    default:
      P = kp * e;
      D = kd * e - LE;
      vel = P + D;
      LE = e;
      int vd = V + vel;
      int vi = V - vel;
      if (vd > v) vd = v;
      if (vi > v) vi = v;
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, vd);
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, vi);
      break;

  }
}
