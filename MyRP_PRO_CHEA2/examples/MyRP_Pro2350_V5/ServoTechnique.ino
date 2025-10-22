void Big_Box_left() {
  Servo(45, 120, 45);  // เปิดซ้าย
  MotorStop(300);
  Servo(45, 120, 1, 10);  // ตบซ้าย
}
void Big_Box_right() {
  Servo(45, 45, 120);  // เปิด
  MotorStop(300);
  Servo(45, 1, 120, 10);  // ขวา
}
void Small_Box_left() {
  place_left_in(30, 45, 30);
  Servo(45, 125, 45);  // เปิดซ้าย
  place_left_out(30, 45, 30);
}
void Small_Box_right() {
  place_right_in(10, 45, 30);
  Servo(45, 45, 125);  // เปิดซ้าย
  place_right_out(10, 45, 30);
}
void Big_speed_left() {
  Servo(45, 120, 45);  // เปิดซ้าย
  MotorStop(300);
  Servo(45, 120, 1);  // ตบซ้าย
}
void Big_speed_right() {
  Servo(45, 45, 120);  // เปิด
  MotorStop(300);
  Servo(45, 1, 120 );  // ขวา
}