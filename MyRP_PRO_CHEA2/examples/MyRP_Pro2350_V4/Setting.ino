void _setting() {
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