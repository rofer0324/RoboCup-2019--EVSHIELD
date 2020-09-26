void esquivo() {
  evshield.bank_a.motorRunDegrees(SH_Motor_Both, SH_Direction_Forward, V, 180, SH_Completion_Wait_For, SH_Next_Action_Float);
  evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Forward, V, 680, SH_Completion_Dont_Wait, SH_Next_Action_Float);
  evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse, V, 680, SH_Completion_Wait_For, SH_Next_Action_Float);

  evshield.bank_a.motorRunDegrees(SH_Motor_Both, SH_Direction_Reverse, V, 600, SH_Completion_Wait_For, SH_Next_Action_Float);

  evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse, V, 680, SH_Completion_Dont_Wait, SH_Next_Action_Float);
  evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Forward, V, 680, SH_Completion_Wait_For, SH_Next_Action_Float);

  evshield.bank_a.motorRunDegrees(SH_Motor_Both, SH_Direction_Reverse, V, 1400, SH_Completion_Wait_For, SH_Next_Action_Float);

  evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Reverse, V, 680, SH_Completion_Dont_Wait, SH_Next_Action_Float);
  evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Forward, V, 680, SH_Completion_Wait_For, SH_Next_Action_Float);

  evshield.bank_a.motorRunDegrees(SH_Motor_Both, SH_Direction_Reverse, V, 500, SH_Completion_Wait_For, SH_Next_Action_Float);

  evshield.bank_a.motorRunDegrees(SH_Motor_1, SH_Direction_Forward, V, 700, SH_Completion_Dont_Wait, SH_Next_Action_Float);
  evshield.bank_a.motorRunDegrees(SH_Motor_2, SH_Direction_Reverse, V, 700, SH_Completion_Wait_For, SH_Next_Action_Float);
}
