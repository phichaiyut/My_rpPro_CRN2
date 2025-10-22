void RobotSetup() {
  SetBalanceSpeedForward();   //ฟังก์ชั่นตั้งค่าความสมดุลมอเตอร์ในแต่ละความเร็ว
  SetBalanceSpeedBackward();  //ฟังก์ชั่นตั้งค่าความสมดุลมอเตอร์ในแต่ละความเร็ว
  SetKpKd();                  //ฟังก์ชั่นตั้งค่า KP KD ในแต่ละความเร็ว
  SetKpKdBack();              //ฟังก์ชั่นตั้งค่า KP KD ในแต่ละความเร็ว
}

void SetKpKd() {  //เดินหน้า
  Set_KP_KD(SPD_10, 8, 16);
  Set_KP_KD(SPD_20, 9, 18);
  Set_KP_KD(SPD_30, 10, 28);
  Set_KP_KD(SPD_40, 15, 15);
  Set_KP_KD(SPD_50, 20, 36);
  Set_KP_KD(SPD_60, 25, 50);
  Set_KP_KD(SPD_70, 26, 52);
  Set_KP_KD(SPD_80, 30, 60);
  Set_KP_KD(SPD_90, 33, 66);
  Set_KP_KD(SPD_100, 36, 72);
}

void SetKpKdBack() {  //ถอยหลัง
  Set_KP_KD_Back(SPD_10, 8, 16);
  Set_KP_KD_Back(SPD_20, 9, 18);
  Set_KP_KD_Back(SPD_30, 10, 20);
  Set_KP_KD_Back(SPD_40, 14, 28);
  Set_KP_KD_Back(SPD_50, 19, 38);
  Set_KP_KD_Back(SPD_60, 20, 40);
  Set_KP_KD_Back(SPD_70, 23, 46);
  Set_KP_KD_Back(SPD_80, 28, 56);
  Set_KP_KD_Back(SPD_90, 31, 62);
  Set_KP_KD_Back(SPD_100, 33, 66);
}



void SetBalanceSpeedForward() {  //เดินหน้า
  //ข้างไหนแรงกว่าไปข้างเพิ่มข้างนั้น
  //______________________________setBalanceSpeed(SPD_10,ข้างซ้าย, ข้างขวา);__________________________________
  setBalanceSpeed(SPD_10, 0, 0);   //ความเร็ว 10
  setBalanceSpeed(SPD_20, 0, 0);   //ความเร็ว 20
  setBalanceSpeed(SPD_30, 0, 0);   //ความเร็ว 30
  setBalanceSpeed(SPD_40, 0, 0);   //ความเร็ว 40
  setBalanceSpeed(SPD_50, 0, 0);   //ความเร็ว 50
  setBalanceSpeed(SPD_60, 0, 0);   //ความเร็ว 60
  setBalanceSpeed(SPD_70, 0, 0);   //ความเร็ว 70
  setBalanceSpeed(SPD_80, 0, 0);   //ความเร็ว 80
  setBalanceSpeed(SPD_90, 0, 0);   //ความเร็ว 90
  setBalanceSpeed(SPD_100, 0, 0);  //ความเร็ว 100
}


void SetBalanceSpeedBackward() {  //ถอยหลัง
  //ข้างไหนแรงกว่าไปข้างเพิ่มข้างนั้น
  //______________________setBalanceBackSpeed(SPD_10, ข้างซ้าย, ข้างขวา);____________________________________________
  setBalanceBackSpeed(SPD_10, 0, 0);   //ความเร็ว 10
  setBalanceBackSpeed(SPD_20, 0, 0);   //ความเร็ว 20
  setBalanceBackSpeed(SPD_30, 0, 0);   //ความเร็ว 30
  setBalanceBackSpeed(SPD_40, 0, 0);   //ความเร็ว 40
  setBalanceBackSpeed(SPD_50, 0, 0);   //ความเร็ว 50
  setBalanceBackSpeed(SPD_60, 0, 0);   //ความเร็ว 60
  setBalanceBackSpeed(SPD_70, 0, 0);   //ความเร็ว 70
  setBalanceBackSpeed(SPD_80, 0, 0);   //ความเร็ว 80
  setBalanceBackSpeed(SPD_90, 0, 0);   //ความเร็ว 90
  setBalanceBackSpeed(SPD_100, 0, 0);  //ความเร็ว 100
}
