void Rescue() {

  while (true) {
    evshield.bank_a.motorReset();
    evshield.bank_b.motorReset();
    evshield.bank_b.motorRunDegrees(SH_Motor_2, SH_Direction_Forward, 30, 100, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
    evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Float);
    delay(500);
    while (true) {
Res:
      RE = 0;
      if (digitalRead(3) == 1) RE = 1;
      if (digitalRead(5) == 1) RE = 2;
      if (digitalRead(3) == 1 && digitalRead(5) == 1) RE = 3;


      switch (RE) {

        case 1:
          evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 80);
          evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 0);
          break;
        case 2:
          evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 0);
          evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 80);
          break;
        case 3:
          evshield.bank_a.motorReset();
          evshield.bank_a.motorRunRotations(SH_Motor_Both, SH_Direction_Forward, 30, 8, SH_Completion_Dont_Wait, SH_Next_Action_Brake);
          delay(600);
          evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Brake);
          evshield.bank_b.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse, 30, 360, SH_Completion_Wait_For, SH_Next_Action_Brake);
          delay(1000);
          evshield.bank_b.motorRunDegrees(SH_Motor_2, SH_Direction_Forward, 20, 60, SH_Completion_Wait_For, SH_Next_Action_Brake);
          delay(500);
          evshield.bank_b.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse, 20, 60, SH_Completion_Wait_For, SH_Next_Action_Brake);
          delay(200);
          while (true) {
            H = 0;
            if (digitalRead(3) == 0 && digitalRead(5) == 0) {
              evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 30);
              evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 30);
            } else {
              evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Float);

              if (digitalRead(6) == 0 && RV == 0) H = 1;
              if (digitalRead(9) == 0 && RV == 0) H = 2;
              if (RV == 0)H = 2;
              switch (H) {
                case 1:
                  while (true) {
                    evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Float);
                  }
                  goto Res;
                  break;
                case 2:
                  while (true) {
                    evshield.bank_a.motorStop(SH_Motor_Both, SH_Next_Action_Float);
                    tone(buz, 600);
                    delay(1000);
                    noTone(buz);
                  }
                  goto Res;
                  break;
              }
            }


          }


          break;
        default:
          evshield.bank_b.motorReset();
          evshield.bank_b.motorStop(SH_Motor_1, SH_Next_Action_Float);
          evshield.bank_a.motorRunUnlimited(SH_Motor_1, SH_Direction_Reverse, 30);
          evshield.bank_a.motorRunUnlimited(SH_Motor_2, SH_Direction_Reverse, 60);
          break;
      }
    }
  }

}
