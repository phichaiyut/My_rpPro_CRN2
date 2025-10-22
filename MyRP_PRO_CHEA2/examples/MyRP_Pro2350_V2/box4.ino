void box4() {
  BB(20, 'r');
  FF(40, 'r');
  FF(20, 's');
  arm_down_close();
  delay(500);

  BB(20, 'r');
  FF(40, 'R');
  FF(20, 's');
  arm_down_open();
  FD(20, 20);
}