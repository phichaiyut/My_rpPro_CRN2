int readyL = 65, readyR = 70; // ฟังก์ชันองศาของ arm_ready()  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
int behindL = 40, behindR = 45; //ฟังก์ชันองศาของ arm_behind()  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
int up = 95; //ยกแขนขึ้น
int closeL = 91, closeR = 91; //หุบลูกเล็ก close
int closeBigL = 75, closeBigR = 85; //หุบลูกใหญ่ big_box



void arm_ready()  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
{
  servo(36, servo_down);
  servo(34, servoL_open - readyL);
  servo(35, servoR_open - readyR);
  pos1 = servo_down, pos2 = servoL_open - readyL, pos3 = servoR_open - readyR;
}

void arm_behind()  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
{
  servo(36, servo_down);
  servo(34, servoL_open + behindL);
  servo(35, servoR_open + behindR);
  pos1 = servo_down, pos2 = servoL_open + behindL, pos3 = servoR_open + behindR;
}
void arm_open_down() {
  servo(34, servoL_open);
  servo(35, servoR_open);
  delay(300);
  servo(36, servo_down);
  pos1 = servo_down, pos2 = servoL_open, pos3 = servoR_open;
}
void arm_down_open() {
  servo(36, servo_down);
  delay(300);
  servo(34, servoL_open);
  servo(35, servoR_open);
  pos1 = servo_down, pos2 = servoL_open, pos3 = servoR_open;
}
void arm_open_up() {
  servo(34, servoL_open);
  servo(35, servoR_open);
  delay(300);
  servo(36, servo_down + up);

  pos1 = servo_down + up, pos2 = servoL_open, pos3 = servoR_open;
}
void arm_up_open() {
  servo(36, servo_down + up);
  delay(300);
  servo(34, servoL_open);
  servo(35, servoR_open);

  pos1 = servo_down + up, pos2 = servoL_open, pos3 = servoR_open;
}
void arm_down_close() {
  servo(36, servo_down);
  delay(100);
  servo(34, servoL_open - closeL);
  servo(35, servoR_open - closeR);

  pos1 = servo_down, pos2 = servoL_open - closeL, pos3 = servoR_open - closeR;
}

void arm_up_close() {
  servo(36, servo_down + up);
  delay(100);
  servo(34, servoL_open - closeL);
  servo(35, servoR_open - closeR);
  pos1 = servo_down + up, pos2 = servoL_open - closeL, pos3 = servoR_open - closeR;
}
void arm_big_box() {
  servo(36, servo_down);
  servo(34, servoL_open - closeBigL);
  servo(35, servoR_open - closeBigR);
  pos1 = servo_down, pos2 = servoL_open - closeBigL, pos3 = servoR_open - closeBigR;
}

void arm_big_box_up() {
  servo(34, servoL_open - closeBigL);
  servo(35, servoR_open - closeBigR);
  delay(300);
  servo(36, servo_down + up);
  
  pos1 = servo_down + up, pos2 = servoL_open - closeBigL, pos3 = servoR_open - closeBigR;
}




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
  Servo(servo_down, servoL_open - closeBigL, servoR_open - closeBigR, spd);
}

void arm_big_box_up(int spd) {
  Servo(servo_down, servoL_open - closeBigL, servoR_open - closeBigR, spd);
  delay(100);
  Servo(servo_down + up, pos2 , pos3, spd);
}