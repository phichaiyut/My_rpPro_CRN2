void box2() {
  BB(40, 'l');
  FF(50, 'L');
  FF(20, 's');
  arm_down_close();
  delay(500);
  BB(40, 'l');
  FF(50, 'L');
  FF(20, 's');
  arm_down_open();
  FD(20, 50);
}