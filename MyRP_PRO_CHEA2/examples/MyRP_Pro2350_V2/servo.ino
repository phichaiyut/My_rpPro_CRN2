
int servo_down = 50;      //-------------------->> ตั้งค่า มื่อจับลงขนานกับพื้น
int servoL_open = 170;      //-------------------->> ตั้งค่า กางฝ่ามือด้านซ้าย
int servoR_open = 10;  //-------------------->> ตั้งค่า กางฝ่ามือด้านขวา


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

    servo(36, pos1);
    servo(34, pos2);
    servo(35, pos3);

    delay(spd);  // หน่วงเวลา
  }
  pos1 = target1;
  pos2 = target2;
  pos3 = target3;
 delay(300);
}

// -------------------- ฟังก์ชันย่อยพิเศษ (มีพารามิเตอร์) --------------------

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

void ServoOpen() {
  MotorStop();
  servo(34, OpenL);
  servo(35, OpenR);
}

void ServoClose() {
  MotorStop();
  servo(34, CloseL);
  servo(35, CloseR);
  delay(100);
}

void ServoCloseSmall() {
  MotorStop();
  servo(34, CloseLSmall);
  servo(35, CloseRSmall);
  delay(200);
}

void ServoUp() {
  MotorStop();
  servo(36, Up);
}

void ServoUp45() {
  MotorStop();
  servo(36, Up45);
}

void ServoDown() {
  MotorStop();
  servo(36, Down);
  delay(150);
}

void Servo(int x, int y, int z) {
  MotorStop();
  servo(36, x);
  servo(34, y);
  servo(35, z);
  pos1 = x;
  pos2 = y;
  pos3 = z;
  delay(300);
}


void arm_ready()  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
  {
    servo(36, servo_down);
    servo(34, servoL_open - 30);
    servo(35, servoR_open + 30);
  }

void arm_down_open()
  {
    servo(36, servo_down);
    delay(300);
    servo(34, servoL_open);
    servo(35, servoR_open);
  }
void arm_up_open()
  {
    servo(36, servo_down + 90);
    servo(34, servoL_open);
    servo(35, servoR_open);
    servo(36, servo_down + 90);
  }
void arm_down_close()
  {
    servo(36, servo_down);
    delay(50);
    servo(34, servoL_open-110);
    servo(35, servoR_open+110);
  }

void arm_up_close()
  {
    servo(36, servo_down+90);
    servo(34, servoL_open-110);
    servo(35, servoR_open+110);
  }
void arm_big_box()
  {
    servo(36, servo_down);
    servo(34, servoL_open - 70);
    servo(35, servoR_open + 70);
  }

void fw_ch_line(int num)
  {
    for(int i=0; i< num; i++)
      {
        while(1)
          {
            delay(5);      
            if(read_sensorA(0) < md_sensorA(0)-50 && read_sensorA(7) > md_sensorA(7)-50)
              {
                Motor(-5 ,20);
              }
            else if(read_sensorA(0) > md_sensorA(0)-50 && read_sensorA(7) < md_sensorA(7)-50)
              {
                Motor(20 ,-5);
              }
            else if(read_sensorA(0) > md_sensorA(0)-50 && read_sensorA(7) > md_sensorA(7)-50)
              {          
                Motor(15 ,15);
              }
            else 
              {
                Motor(-1 ,-1);
                break;
              }      
          }
        if(num > 1)
          {
            Motor(-15 ,-15);
            delay(50);
            Motor(-1 ,-1);
          }
      }
    
  }

void bw_ch_line(int num)
  {
    for(int i=0; i< num; i++)
      {
        while(1)
          {
            delay(5);      
            if(read_sensorB(0) < md_sensorB(0)-50 && read_sensorB(7) > md_sensorB(7)-50)
              {
                Motor(-20 ,5);
              }
            else if(read_sensorB(0) > md_sensorB(0)-50 && read_sensorB(7) < md_sensorB(7)-50)
              {
                Motor(5 ,-20);
              }
            else if(read_sensorB(0) > md_sensorB(0)-50 && read_sensorB(7) > md_sensorB(7)-50)
              {          
                Motor(-15 ,-20);
              }
            else 
              {
                Motor(-1 ,-1);
                break;
              }      
          }
        if(num > 1)
          {
            Motor(10 ,10);
            delay(50);
            Motor(-1 ,-1);
          }
      }
    
  }
