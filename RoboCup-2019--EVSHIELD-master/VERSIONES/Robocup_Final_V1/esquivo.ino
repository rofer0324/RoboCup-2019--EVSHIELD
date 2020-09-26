void esquivo() {
  while (true) {
    evshield.bank_a.motorRunUnlimited(SH_Motor_Both, SH_Direction_Forward, 20);
    delay(1500);
    evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
    delay(500);
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 25);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 30);
    delay(1325);
    evshield.bank_a.motorRunUnlimited(SH_Motor_Both, SH_Direction_Reverse, 30);
    delay(2800);
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 30);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 25);
    delay(1477);
    evshield.bank_a.motorRunUnlimited(SH_Motor_Both, SH_Direction_Reverse, 30);
    delay(4000);
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 30);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 25);
    delay(1477);
    evshield.bank_a.motorRunUnlimited(SH_Motor_Both, SH_Direction_Reverse, 30);
    delay(2400);
    evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 25);
    evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 30);
    delay(1900);
    evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
    break;
  }
}
