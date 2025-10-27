void _setting() {
  set_value_calibate(1000); // เซตค่า Recalibate 
  RefLineValue(400);        // ค่าในการจับเส้น เซนเซอร์หน้า หลัง
  RefCenterLineValue(800);  // ค่าในการจับเส้น เซนเซอร์คู่กลาง
  TrackLineColor(0);        // 0 >> พื้นขาวเส้นดำ ||  1 >> พื้นดำเส้นขาว

  SetToCenterSpeed(30);  // ความเร็วเข้ากลางหุ่น
  SetTurnSpeed(40);      // ความเร็วเลี้ยวเข้าแยก
  // SetRobotPID(0.014, 0.04);  // ค่า PID

  ModeSpdPID(1, 100, -5);

  TurnSpeedLeft(25, 80, 50);
  TurnSpeedRight(80, 25, 50);

  Dottedline(0);  //ไม่มีเส้นประใส่ 0 มีเส้นประใส่ 1
  mode_soft_start(1);          // 0 >> ออกตัวไม่สมูท || 1 >> ออกตัวสมูท
  
  Delay_c_F(1500);
  Delay_c_B(1500);

  set_position_line(3500);  // 1500 ฝั่งซ้าย   3500 ตรงกลาง  5500 ฝั่งขวา  // หรือใส่ค่าเท่าไรก็ได้ แต่ให้อยู่ในช่วง 0 - 7000;

  //////////////////////////////เช็คค่าเซนเซอร์//////////////////////////
  // SerialDistance();                // Serial Monitor เซนเซอร์วัดระยะ
  // Serial_FrontSensor();  // Serial Monitor เซนเซอร์หน้า
  // Serial_BackSensor();             // Serial Monitor เซนเซอร์หลัง
  // Serial_CenterSensor();           // Serial Monitor เซนเซอร์กลาง
  // SerialCalibrate_FrontSensor();   // Serial Monitor เซนเซอร์หน้า คาริเบทแล้ว
  // SerialCalibrate_BackSensor();  // Serial Monitor เซนเซอร์หลัง คาริเบทแล้ว
  // SerialCalibrate_CenterSensor();  // Serial Monitor เซนเซอร์กลาง คาริเบทแล้ว
  // SerialPositionF(); //Serial Monitor อ่านค่าตำแหน่งของเส้น เซนเซอร์หน้า
  // SerialPositionB(); //Serial Monitor อ่านค่าตำแหน่งของเส้น เซนเซอร์หลัง
 
  //____________________ตั้งค่า องศา เซอร์โว_______________________________
  setOpen(40, 50);        //เปิดอ้า
  setOpenMax(120, 120);     //อ้าใหญ่ๆ
  setClose(35, 35);       //ปิดลูกใหญ่
  setCloseSmall(20, 20);  //หุบลูกเล็ก
  setUpDown(50, 145);      //ตอนยกขึ้น  ยกลง
  setOpenLeft(120, 35);     //อ้าด้านซ้าย
  setOpenRight(35, 120);  //อ้าด้านขวา
  //____________________สิ้นสุดการตั้งค่า เซอร์โว____________________________________________
}



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
  Set_KP_KD_Back(SPD_50, 20, 38);
  Set_KP_KD_Back(SPD_60, 20, 40);
  Set_KP_KD_Back(SPD_70, 23, 46);
  Set_KP_KD_Back(SPD_80, 28, 56);
  Set_KP_KD_Back(SPD_90, 31, 62);
  Set_KP_KD_Back(SPD_100, 33, 66);
}



void SetBalanceSpeedForward() {  //เดินหน้า
  //ข้างไหนแรงกว่าไปข้างเพิ่มข้างนั้น
  //______________________________setBalanceSpeed(SPD_10,ข้างซ้าย, ข้างขวา);__________________________________
  setBalanceSpeed(SPD_10,0, 0);   //ความเร็ว 10
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
