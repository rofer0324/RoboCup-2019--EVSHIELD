void verde() {
  while (true) {
    myColor1.setMode(MODE_Color_MeasureColor);
    myColor2.setMode(MODE_Color_MeasureColor);

    s1 = myColor1.getVal();
    s2 = myColor2.getVal();
    delay(1000);
    if (s1 == 3) {
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 0);
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 30);
      delay(600);
    } else if (s2 == 3) {
      evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 30);
      evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 0);
      delay(600);
    } else if(s1 != 3 && s2 != 3){
        myColor1.setMode(MODE_Color_ReflectedLight);
        myColor2.setMode(MODE_Color_ReflectedLight);
        evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
        delay(500);

        if (s1 < 5 ) {
          evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
          delay(200);
          evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Forward, 20);
          evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 20);
          delay(300);
        } else if(s2 < 5) {
          evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
          delay(200);
          evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 20);
          evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Forward, 20);
          delay(300);
        }else{
           evshield.bank_a.motorRunUnlimited(SH_Motor_Both, SH_Direction_Reverse, 10);
           delay(60);
        }
      

    
M:
    break;
  }
}
}
