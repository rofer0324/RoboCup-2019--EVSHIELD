#include <Wire.h>
#include <EVShield.h>
#include <EVs_LightSensorArray.h>

EVShield evshield(0x34, 0x36);

EVs_LightSensorArray lsa (0x14);

int V = 30;
int v = 30;
int P = 0;
int I = 0;
int D = 0;
int kp = 10; //10

int kd = 22; //22
int LE = 0;
int e = 0;
int vel;

void setup() {
  char str[256];
  Serial.begin(115200);
  // delay(2000);

  evshield.init( SH_HardwareI2C);
  lsa.init( &evshield, SH_BAS1);

  while (!evshield.getButtonState(BTN_GO)) {
    if (millis() & 1000 < 3) {
      Serial.println("perrra");
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
 if(vd > v) vd = v;
 if(vi > v) vi = v;
 
  evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, vd);
  evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, vi);
  
  Serial.println(e);
  delay(5);
}
