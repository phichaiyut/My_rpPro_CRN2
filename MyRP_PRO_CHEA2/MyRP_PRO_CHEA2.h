#include <MyRP_PRO_CHEA2_Sensor.h> 
#include <MyRP_PRO_CHEA2_Motor.h> 
#include <MyRP_PRO_CHEA2_Initial.h> 
#include <MyRP_PRO_CHEA2_ForwardBackwardAndTurn.h> 
#include <MyRP_PRO_CHEA2_Turn.h> 
#include <MyRP_PRO_CHEA2_PID.h> 
#include <MyRP_PRO_CHEA2_PID_String.h> 
#include <MyRP_PRO_CHEA2_GYRO.h> 

int OpenL,OpenR;
int CloseL ,CloseR;
int CloseLSmall ,CloseRSmall;
int Up,Up45,Down;
int OpenL2,OpenR2;
int OpenRMax,OpenLMax;
int LeftOpen1;   // เซอร์โวซ้ายตัวที่ 1
int LeftOpen2;   // เซอร์โวซ้ายตัวที่ 2
int RightOpen1;   // เซอร์โวซ้ายตัวที่ 1
int RightOpen2;   // เซอร์โวซ้ายตัวที่ 2

// int pos1 = 90, pos2 = 90, pos3 = 90;



void setOpen(int degree1,int degree2){
  OpenL = degree1;
  OpenR = degree2;
}

void setOpen2(int degree1,int degree2){
  OpenL2 = degree1;
  OpenR2 = degree2;
}

void setOpenMax(int degree1,int degree2){
  OpenLMax = degree1;
  OpenRMax = degree2;
}

void setClose(int degree1,int degree2){
  CloseL = degree1;
  CloseR = degree2;
}

void setCloseSmall(int degree1,int degree2){
  CloseLSmall = degree1;
  CloseRSmall = degree2;
}

void setUpDown(int degree1,int degree2){
  Up = degree1; 
  Down = degree2;
}

void setOpenLeft(int degree1,int degree2){
  LeftOpen1 = degree1;
  LeftOpen2 = degree2;
}

void setOpenRight(int degree1,int degree2){
  RightOpen1 = degree1;
  RightOpen2 = degree2;
}

void OK(){

  sw();
}


void OK_STOP(){
MotorStop(0);
  sw();
}

void moveServo(int servoID, int targetAngle) {
  if (targetAngle < 0 || targetAngle > 180) {
    Serial.println("Error: มุมต้องอยู่ระหว่าง 0 - 180");
    return;
  }

  switch (servoID) {
    case 1: servo(36,targetAngle); Serial.print("Servo1 = "); break;
    case 2: servo(34,targetAngle); Serial.print("Servo2 = "); break;
    case 3: servo(35,targetAngle); Serial.print("Servo3 = "); break;
    default: Serial.println("Error: ไม่มี Servo หมายเลขนี้ (ใช้ 1, 2, 3)"); return;
  }
  Serial.println(targetAngle);
}

// ฟังก์ชันอ่านคำสั่งจาก Serial
void readSerialCommand() {
  while (1) {
    if (Serial.available() > 0) {
      String input = Serial.readStringUntil('\n');
      input.trim();

      // ถ้าอยากออกจาก loop
      if (input.equalsIgnoreCase("EXIT")) {
        Serial.println("ออกจากโหมดควบคุม Serial แล้ว");
        break; // ออกจาก while loop
      }

      if (input.startsWith("S1")) {
        int angle = input.substring(2).toInt();
        moveServo(1, angle);
      }
      else if (input.startsWith("S2")) {
        int angle = input.substring(2).toInt();
        moveServo(2, angle);
      }
      else if (input.startsWith("S3")) {
        int angle = input.substring(2).toInt();
        moveServo(3, angle);
      }
      else {
        Serial.println("❌ รูปแบบไม่ถูกต้อง! ใช้ S1/S2/S3 ตามด้วยมุม เช่น S1 90");
      }
    }
  }
}
