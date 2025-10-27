#define Sv1 36
#define Sv2 34
#define Sv3 35

int pos1 = servo_down, pos2 = servoL_open, pos3 = servoR_open;
//________ตัวอย่างการใช้งานการใช้งาน SERVO ____________

//Servo(100,90, 80, 3);

//ServoUp(3);    // ยกขึ้น เร็ว (delay 5ms)
//ServoDown(3); // ลง ความเร็วทีละ 5 (delay 5ms)

//ServoOpen(3); //เปิดอ้า ความเร็วทีละ 5 (delay 5ms)
//ServoOpenMax(3); //อ้าลูกใหญ่
//ServoCloseSmall(3); //เก็บลูกเล็ก
//ServoCloseBig(3); //เก็บลูกใหญ่
// -------------------- ฟังก์ชันหลัก --------------------
void Servo(int target1, int target2, int target3, int spd) {

  MotorStop();
  while (pos1 != target1 || pos2 != target2 || pos3 != target3) {
    if (pos1 < target1) pos1++;
    else if (pos1 > target1) pos1--;

    if (pos2 < target2) pos2++;
    else if (pos2 > target2) pos2--;

    if (pos3 < target3) pos3++;
    else if (pos3 > target3) pos3--;

    servo(Sv1, pos1);
    servo(Sv2, pos2);
    servo(Sv3, pos3);

    delay(spd);  // หน่วงเวลา
  }
  pos1 = target1;
  pos2 = target2;
  pos3 = target3;
  delay(300);
}

// -------------------- ฟังก์ชันย่อยพิเศษ (มีพารามิเตอร์) --------------------


/*
void arm_ready(int spd)  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
{
  Servo(servo_down, servoL_open - readyL, servoR_open - readyR, spd);
}

void arm_behind(int spd)  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
{
  Servo(servo_down, servoL_open + behindL, servoR_open + behindR, spd);
}
void arm_open_down(int spd) {
  Servo(pos1, servoL_open, servoR_open, spd);
  delay(100);
  Servo(servo_down, pos2, pos3, spd);
}
void arm_down_open(int spd) {
  Servo(servo_down, pos2, pos3, spd);
  delay(100);
  Servo(pos1, servoL_open, servoR_open, spd);
}
void arm_open_up(int spd) {
  Servo(pos1, servoL_open, servoR_open, spd);
  delay(100);
  Servo(servo_down + up, pos2, pos3, spd);
}
void arm_up_open(int spd) {
  Servo(servo_down + up, pos2, pos3, spd);
  delay(100);
  Servo(pos1, servoL_open, servoR_open, spd);
}
void arm_down_close(int spd) {
  Servo(servo_down, pos2, pos3, spd);
  delay(100);
  Servo(pos1, servoL_open - closeL, servoR_open - closeR, spd);
}

void arm_up_close(int spd) {
  Servo(servo_down + up, pos2, pos3, spd);
  delay(100);
  Servo(pos1, servoL_open - closeL, servoR_open - closeR, spd);
}
void arm_big_box(int spd) {
  Servo(servo_down, pos2 - closeBigL, pos3 - closeBigR, spd);
}

void arm_big_box_up(int spd) {
  Servo(servo_down, pos2 - closeBigL, pos3 - closeBigR, spd);
  delay(100);
  Servo(servo_down + up, pos2 , pos3, spd);
}



*/






// ปิดเล็ก
void ServoCloseSmall(int spd) {
  Servo(pos1, CloseLSmall, CloseRSmall, spd);
}

// ปิดใหญ่
void ServoCloseBig(int spd) {
  Servo(pos1, CloseL, CloseR, spd);
}

// เปิดปกติ
void ServoOpen(int spd) {
  Servo(pos1, OpenL, OpenR, spd);
}

// เปิดอีกแบบ (Open2)
void ServoOpen2(int spd, bool smooth) {
  Servo(pos1, OpenL2, OpenR2, spd);
}

// เปิดสุด (Max)
void ServoOpenMax(int spd) {
  Servo(pos1, OpenLMax, OpenRMax, spd);
}

// ยกขึ้น
void ServoUp(int spd) {
  Servo(Up, pos2, pos3, spd);
}

// ลง
void ServoDown(int spd) {
  Servo(Down, pos2, pos3, spd);
}

void ServoOpenLeft(int spd) {
  Servo(pos1, LeftOpen1, LeftOpen2, spd);
}

void ServoOpenRight(int spd) {
  Servo(pos1, RightOpen1, RightOpen2, spd);
}

void Servo(int x, int y, int z) {
  servo(Sv1, x);
  servo(Sv2, y);
  servo(Sv3, z);
  pos1 = x;
  pos2 = y;
  pos3 = z;
}






// int readyL = 65, readyR = 70;        // ฟังก์ชันองศาของ arm_ready()  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
// int behindL = 40, behindR = 45;      //ฟังก์ชันองศาของ arm_behind()  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
// int up = 95;                         //ยกแขนขึ้น
// int closeL = 91, closeR = 91;        //หุบลูกเล็ก close
// int closeBigL = 75, closeBigR = 85;  //หุบลูกใหญ่ big_box



// void arm_ready()  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
// {
//   servo(36, servo_down);
//   servo(34, servoL_open - readyL);
//   servo(35, servoR_open - readyR);
//   pos1 = servo_down, pos2 = servoL_open - readyL, pos3 = servoR_open - readyR;
// }

// void arm_behind()  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
// {
//   servo(36, servo_down);
//   servo(34, servoL_open + behindL);
//   servo(35, servoR_open + behindR);
//   pos1 = servo_down, pos2 = servoL_open + behindL, pos3 = servoR_open + behindR;
// }
// void arm_open_down() {
//   servo(34, servoL_open);
//   servo(35, servoR_open);
//   delay(300);
//   servo(36, servo_down);
//   pos1 = servo_down, pos2 = servoL_open, pos3 = servoR_open;
// }
// void arm_down_open() {
//   servo(36, servo_down);
//   delay(300);
//   servo(34, servoL_open);
//   servo(35, servoR_open);
//   pos1 = servo_down, pos2 = servoL_open, pos3 = servoR_open;
// }
// void arm_open_up() {
//   servo(34, servoL_open);
//   servo(35, servoR_open);
//   delay(300);
//   servo(36, servo_down + up);

//   pos1 = servo_down + up, pos2 = servoL_open, pos3 = servoR_open;
// }
// void arm_up_open() {
//   servo(36, servo_down + up);
//   delay(300);
//   servo(34, servoL_open);
//   servo(35, servoR_open);

//   pos1 = servo_down + up, pos2 = servoL_open, pos3 = servoR_open;
// }
// void arm_down_close() {
//   servo(36, servo_down);
//   delay(100);
//   servo(34, servoL_open - closeL);
//   servo(35, servoR_open - closeR);

//   pos1 = servo_down, pos2 = servoL_open - closeL, pos3 = servoR_open - closeR;
// }

// void arm_up_close() {
//   servo(36, servo_down + up);
//   delay(100);
//   servo(34, servoL_open - closeL);
//   servo(35, servoR_open - closeR);
//   pos1 = servo_down + up, pos2 = servoL_open - closeL, pos3 = servoR_open - closeR;
// }
// void arm_big_box() {
//   servo(36, servo_down);
//   servo(34, servoL_open - closeBigL);
//   servo(35, servoR_open - closeBigR);
//   pos1 = servo_down, pos2 = servoL_open - closeBigL, pos3 = servoR_open - closeBigR;
// }

// void arm_big_box_up() {
//   servo(34, servoL_open - closeBigL);
//   servo(35, servoR_open - closeBigR);
//   delay(300);
//   servo(36, servo_down + up);

//   pos1 = servo_down + up, pos2 = servoL_open - closeBigL, pos3 = servoR_open - closeBigR;
// }

// void arm_up() {
//   servo(36, pos1 = servo_down + up);
// }

// void arm_down() {
//   servo(36, pos1 = servo_down);
// }

// void arm_close() {
//   servo(34, pos2 = servoL_open - closeL);
//   servo(35, pos3 = servoR_open - closeR);
// }
// void arm_open() {
//   servo(34, pos2 = servoL_open);
//   servo(35, pos3 = servoR_open);
// }

// void arm_big() {
//   servo(34, pos2 = servoL_open - closeBigL);
//   servo(35, pos3 = servoR_open - closeBigR);
// }

// void arm_ready(int spd)  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
// {
//   Servo(servo_down, servoL_open - readyL, servoR_open - readyR, spd);
// }

// void arm_behind(int spd)  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
// {
//   Servo(servo_down, servoL_open + behindL, servoR_open + behindR, spd);
// }
// void arm_open_down(int spd) {
//   Servo(pos1, servoL_open, servoR_open, spd);
//   delay(100);
//   Servo(servo_down, pos2, pos3, spd);
// }
// void arm_down_open(int spd) {
//   Servo(servo_down, pos2, pos3, spd);
//   delay(100);
//   Servo(pos1, servoL_open, servoR_open, spd);
// }
// void arm_open_up(int spd) {
//   Servo(pos1, servoL_open, servoR_open, spd);
//   delay(100);
//   Servo(servo_down + up, pos2, pos3, spd);
// }
// void arm_up_open(int spd) {
//   Servo(servo_down + up, pos2, pos3, spd);
//   delay(100);
//   Servo(pos1, servoL_open, servoR_open, spd);
// }
// void arm_down_close(int spd) {
//   Servo(servo_down, pos2, pos3, spd);
//   delay(100);
//   Servo(pos1, servoL_open - closeL, servoR_open - closeR, spd);
// }

// void arm_up_close(int spd) {
//   Servo(servo_down + up, pos2, pos3, spd);
//   delay(100);
//   Servo(pos1, servoL_open - closeL, servoR_open - closeR, spd);
// }
// void arm_big_box(int spd) {
//   Servo(servo_down, servoL_open - closeBigL, servoR_open - closeBigR, spd);
// }

// void arm_big_box_up(int spd) {
//   Servo(servo_down, servoL_open - closeBigL, servoR_open - closeBigR, spd);
//   delay(100);
//   Servo(servo_down + up, pos2, pos3, spd);
// }





// void arm_up(int spd) {
//   Servo(servo_down + up, pos2, pos3, spd);
//   delay(100);
// }

// void arm_down(int spd) {
//   Servo(servo_down, pos2, pos3, spd);
//   delay(100);
// }

// void arm_close(int spd) {
//   Servo(pos1, servoL_open - closeL, servoR_open - closeR, spd);
//   delay(100);
// }
// void arm_open(int spd) {
//   Servo(pos1, servoL_open, servoR_open, spd);
//   delay(100);
// }

// void arm_big(int spd) {
//   Servo(pos1, servoL_open - closeBigL, servoR_open - closeBigR, spd);
//   delay(100);
// }