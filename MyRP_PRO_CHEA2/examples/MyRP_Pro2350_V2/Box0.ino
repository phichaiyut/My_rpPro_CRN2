void box0() {
  FFtimer(40,600);
  FFR(40, 'r');
  FFL(40, 'l');
  FF(40, 'r');
  FFL(40, 'L');
  FFR(10, 's');
  arm_down_close();
  delay(500);
  BBL(40, 'R');
  FFR(40, 'r');
  FFL(40, 'l');
  FFR(40, 'r');
  FF(20, 'L');
  FFWhite(10,'s');
  Spin_right_gyro(30, 100 ,10);
  fw_gyro(20, 0.85, 'p');
  fw_gyro(20, 0.85, 'p');
  fw_gyro(20, 0.85, 's');
  arm_down_open();delay(500);
  bw_gyro(20, 0.85, 'p');
  bw_gyro(20, 0.85, 'p');
  bw_gyro(20, 0.85, 'R');
  arm_up_open();

}