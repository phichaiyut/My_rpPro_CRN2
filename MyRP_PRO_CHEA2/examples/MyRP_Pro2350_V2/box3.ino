void box3() {
  BB(20, 'r');
  SR(30, 115);
  SpinR();
  FF(20, 's');
  arm_down_close();
  delay(500);

  BB(20, 'l');
  SL(30, 115);
  SpinL();
  FF(20, 's');
  arm_down_open();
  FD(20, 40);

}