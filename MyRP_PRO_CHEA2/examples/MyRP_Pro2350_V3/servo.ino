



void arm_ready()  //--------->> แขนลง กางฝ่ามือออกเตรียมเข้าไปคีบ
{
  servo(36, servo_down);
  servo(34, servoL_open - 80);
  servo(35, servoR_open - 70);
  pos1 = servo_down, pos2 = servoL_open - 80, pos3 = servoR_open - 70;
}

void arm_behind()  //--------->> แขนลง เอาฝ่ามือมาข้างหลัง
{
  servo(36, servo_down);
  servo(34, servoL_open + 40);
  servo(35, servoR_open + 45);
  pos1 = servo_down, pos2 = servoL_open + 40, pos3 = servoR_open + 45;
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
  servo(36, servo_down + 95);

  pos1 = servo_down + 95, pos2 = servoL_open, pos3 = servoR_open;
}
void arm_up_open() {
  servo(36, servo_down + 95);
  delay(300);
  servo(34, servoL_open);
  servo(35, servoR_open);

  pos1 = servo_down + 95, pos2 = servoL_open, pos3 = servoR_open;
}
void arm_down_close() {
  servo(36, servo_down);
  delay(100);
  servo(34, servoL_open - 100);
  servo(35, servoR_open - 100);

  pos1 = servo_down, pos2 = servoL_open - 100, pos3 = servoR_open - 100;
}

void arm_up_close() {
  servo(36, servo_down + 95);
  delay(100);
  servo(34, servoL_open - 100);
  servo(35, servoR_open - 100);
  pos1 = servo_down + 95, pos2 = servoL_open - 100, pos3 = servoR_open - 100;
}
void arm_big_box() {
  servo(36, servo_down);
  servo(34, servoL_open - 85);
  servo(35, servoR_open - 85);
  pos1 = servo_down, pos2 = servoL_open - 85, pos3 = servoR_open - 85;
}
