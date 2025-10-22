#include <my_rpProV2.h>
#include <MyRP_PRO_CHEA2.h>
//----------------------------------------------------------------------------->> ตั้งค่ามือจับ
int servo_down = 50;    //-------------------->> ตั้งค่า มื่อจับลงขนานกับพื้น
int servoL_open = 120;  //-------------------->> ตั้งค่า กางฝ่ามือด้านซ้าย
int servoR_open = 120;   //-------------------->> ตั้งค่า กางฝ่ามือด้านขวา
//----------------------------------------------------------------------------->> ตั้งค่ามือจับ

void setup() {
  setup_rp2350_pro();
  set_motor();
  RobotSetup();


  RefLineValue(300);        // ค่าในการจับเส้น เซนเซอร์หน้า หลัง
  RefCenterLineValue(300);  // ค่าในการจับเส้น เซนเซอร์คู่กลาง
  TrackLineColor(0);        // 0 >> พื้นขาวเส้นดำ ||  1 >> พื้นดำเส้นขาว

  SetToCenterSpeed(30);  // ความเร็วเข้ากลางหุ่น
  SetTurnSpeed(40);      // ความเร็วเลี้ยวเข้าแยก
  // SetRobotPID(0.014, 0.04);  // ค่า PID

  ModeSpdPID(1, 100, -5);

  TurnSpeedLeft(25, 80, 50);
  TurnSpeedRight(80, 25, 50);

  Dottedline(0);  //ไม่มีเส้นประใส่ 0 มีเส้นประใส่ 1

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
  // SerialDistance(); //
  //____________________ตั้งค่า องศา เซอร์โว_______________________________
  setOpen(70, 110);        //เปิดอ้า
  setOpenMax(50, 120);     //อ้าใหญ่ๆ
  setClose(120, 65);       //ปิดลูกใหญ่
  setCloseSmall(150, 35);  //หุบลูกเล็ก
  setUpDown(140, 50);      //ตอนยกขึ้น  ยกลง
  setOpenLeft(60, 65);     //อ้าด้านซ้าย
  setOpenRight(120, 110);  //อ้าด้านขวา
  //____________________สิ้นสุดการตั้งค่า เซอร์โว____________________________________________

  //------------------------->>  ส่วนของคำสั่งในการเตรียมแขนกล
  //arm_up_close();  //--->> ยกแขนขึ้นหุบฝ่ามือเข้า
  arm_down_open();  //--->> แขนลงกางฝ่ามือออก
                    //------------------------->>  ส่วนของคำสั่งในการเตรียมแขนกล

// readSerialCommand();  //สำหรับตั้งค่าเซอร์โวผ่าน Serial
  sw();  //--->> คำสั่งรอกดปุ่ม
  ////------------------------------------------------------------------------------>> รันคำสั่งต่าง ๆ ที่นี่
  Mission();


  ////------------------------------------------------------------------------------>> จบการรันคำสั่งต่าง ๆ
  MotorStop();

  servo_36.detach();
  servo_34.detach();
  servo_35.detach();
}

void loop() {
  // Serial.print( analogRead(46) );   Serial.print( "   " );   Serial.println( analogRead(47) );
  // Serial.println(my.gyro('z'));
  // delay(10);
  // Serial.print(sensorMin_A[0]);
}
