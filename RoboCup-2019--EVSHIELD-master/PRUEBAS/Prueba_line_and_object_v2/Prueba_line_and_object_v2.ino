#include <Wire.h>
#include <EVShield.h>
#include <EVShieldAGS.h>
#include <EVs_EV3Color.h>
#include <EVs_LightSensorArray.h>

EVs_EV3Color myColor;
EVShield evshield(0x34, 0x36);


EVs_LightSensorArray lsa (0x14);

int V = 30;
int v = 30;
int P = 0;
int I = 0;
int D = 0;
int kp = 10;
int kd = 22;
int LE = 0;
int e = 0;
int vel;
int FG = 0;
int VE;
#define RV digitalRead(2)
#define LDR analogRead(A0)
const int buz = 10;

void setup() {
  pinMode(buz, OUTPUT);
  char str[256];
  Serial.begin(115200);

  evshield.init( SH_HardwareI2C);
  lsa.init( &evshield, SH_BAS1);

  myColor.init( &evshield, SH_BAS1 );
  myColor.setMode(MODE_Color_ReflectedLight);

  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() & 1000 < 3) {
    }
  }
  evshield.bank_a.motorReset();
}


void loop() {
  FG = 0;
  noTone(buz);
  int light;
  char str[256];
  uint8_t *cal;

  cal = lsa.getCalibrated();


  if (cal[0] < 10) e = -3;
  if (cal[1] < 10) e = -2;
  if (cal[2] < 10) e = -1;
  if (cal[3] < 10) e = 0;
  if (cal[4] < 10) e = 0;
  if (cal[5] < 10) e = 1;
  if (cal[6] < 10) e = 2;
  if (cal[7] < 10) e = 3;
  P = kp * e;
  D = kd * e - LE;
  vel = P + D;
  LE = e;
  int vd = V + vel;
  int vi = V - vel;
  if (vd > v) vd = v;
  if (vi > v) vi = v;
  if (RV == 0) FG = 1;
  if (light > 100) FG = 2; //LDR < 160 maybe

  switch (FG) {

    case 1:
      esquivo();
      break;

    case 2:
      evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Float);
      tone(buz, 1000);
      delay(500);
      noTone(buz);
      break;

    default:
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, vd);
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, vi);
      break;
  }
  Serial.print("Reflected Light: "); Serial.println(light);
  delay(5);

}
