int MaxSpeed = 100;
int MinSpeed = 0;
int ModePidStatus = 0;
int LastError_F, LastError_B;
int Error_F = 0, Error_B = 0;
int dottedline = 0;
int modesoftstart = 1;
int set_position = 3500;
void ModeSpdPID(int moD, int maX, int miN){
  ModePidStatus = moD;
  MaxSpeed = maX;
  MinSpeed = miN;
}

void Dottedline(int Dot){
  dottedline = Dot;
}

void mode_soft_start(int mod){
  modesoftstart = mod;
}

void set_position_line(int _pos){
 if (_pos < 0) {
    set_position = 0;
  } 
  else if (_pos > 7000) {
    set_position = 7000;
  } 
  else {
    set_position = _pos;
  }
}



int readPositionF(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrateF();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = F[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
     if (dottedline) {
      return last_value;
    }
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}



int readPositionB(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;
  ReadCalibrateB();
  for (i = 0; i < NUM_SENSORS; i++) {
    int values = B[i];
    if (values > Track) {
      online = 1;
    }
    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }
  if (!online) {
     if (dottedline) {
      return last_value;
    }
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }
  last_value = avg / sum;
  return last_value;
}

void SerialPositionF() {
  int pos = readPositionF(250, 50); // เรียกฟังก์ชันอ่านค่า
  Serial.print("Position: ");
  Serial.println(pos);           // ส่งค่าออกทาง Serial
}

void SerialPositionB() {
  int pos = readPositionB(250, 50); // เรียกฟังก์ชันอ่านค่า
  Serial.print("Position: ");
  Serial.println(pos);           // ส่งค่าออกทาง Serial
}


int constrainPID(int val, int minVal, int maxVal) {
  if (val > maxVal) return maxVal;
  if (val < minVal) return minVal;
  return val;
}

void PIDF(int SpeedL, int SpeedR, float Kp, float Kd) {
  int Pos = readPositionF(250, 50);
  int Error = Pos - set_position;
  // if(abs(Error) < 1000) Error = 0;
  int PID_Value = ((Kp / 1000.0) * Error) + ((Kd / 1000.0) * (Error - LastError_F));
  LastError_F = Error;

  int LeftPower  = SpeedL  + PID_Value;
  int RightPower = SpeedR - PID_Value;

  

switch (ModePidStatus) {
    case 0:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = MinSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = MinSpeed;
      break;
    case 1:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < MinSpeed) LeftPower = MinSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < MinSpeed) RightPower = MinSpeed;
      break;
    case 2:
      if (LeftPower > SpeedL) LeftPower = SpeedL;
      if (LeftPower < -SpeedL) LeftPower = -SpeedL;
      if (RightPower > SpeedR) RightPower = SpeedR;
      if (RightPower < -SpeedR) RightPower = -SpeedR;
      break;
    case 3:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = -BaseSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = -BaseSpeed;
      break;
    default:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = 0;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = 0;
  }
  Motor(LeftPower, RightPower);
}


void PIDB(int SpeedL, int SpeedR, float Kp, float Kd) {
  int Pos = readPositionB(250, 50);
  int Error = Pos - set_position;
  int PID_Value = ((Kp / 1000.0) * Error) + ((Kd / 1000.0) * (Error - LastError_B));
  LastError_B = Error;

  int LeftPower  = SpeedL  + PID_Value;
  int RightPower = SpeedR - PID_Value;


switch (ModePidStatus) {
    case 0:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = MinSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = MinSpeed;
      break;
    case 1:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < MinSpeed) LeftPower = MinSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < MinSpeed) RightPower = MinSpeed;
      break;
    case 2:
      if (LeftPower > SpeedL) LeftPower = SpeedL;
      if (LeftPower < -SpeedL) LeftPower = -SpeedL;
      if (RightPower > SpeedR) RightPower = SpeedR;
      if (RightPower < -SpeedR) RightPower = -SpeedR;
      break;
    case 3:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = -BaseSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = -BaseSpeed;
      break;
    default:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = 0;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = 0;
  }

  Motor(-LeftPower, -RightPower); // วิ่งย้อน (กลับทิศกับ PIDF)
}



void softstartf(int target_speed) {
  if(modesoftstart == 1){
  const int ramp_step = 3;
  int current_speed = 0; // PWM
  int actual_target_speed = min(LeftBaseSpeed, RightBaseSpeed);  // ← เปลี่ยนชื่อ
  float _kp = PID_KP, _kd = PID_KP; 
  while (current_speed < actual_target_speed) {
    current_speed += ramp_step;
    if (current_speed > actual_target_speed) {
      current_speed = actual_target_speed;
    }
    delay(ramp_delay);
    BaseSpeed = current_speed;   // ← เดิมเขียนผิดเป็น target_speed
    InitialSpeed();
    PIDF(LeftBaseSpeed, RightBaseSpeed, _kp, _kd);
  }
  }
}

void softstartf(int target_speed,float kp,float kd) {
  if(modesoftstart == 1){
  const int ramp_step = 3;
  int current_speed = 0; // PWM
  int actual_target_speed = min(LeftBaseSpeed, RightBaseSpeed);  // ← เปลี่ยนชื่อ
  //float _kp = PID_KP, _kd = PID_KP; 
  while (current_speed < actual_target_speed) {
    current_speed += ramp_step;
    if (current_speed > actual_target_speed) {
      current_speed = actual_target_speed;
    }
    delay(ramp_delay);
    BaseSpeed = current_speed;   // ← เดิมเขียนผิดเป็น target_speed
    InitialSpeed();
    PIDF(LeftBaseSpeed, RightBaseSpeed, kp, kd);
  }
  }
}




void softstartb(int target_speed){
  if(modesoftstart == 1){
  const int ramp_step = 3;
  int current_speed = 0; // PWM
  int actual_target_speed = min(BackLeftBaseSpeed, BackRightBaseSpeed);  // ← เปลี่ยนชื่อ
  float _kp = PID_KP_Back, _kd = PID_KP_Back; 
  while (current_speed < actual_target_speed) {
    current_speed += ramp_step;
    if (current_speed > actual_target_speed) {
      current_speed = actual_target_speed;
    }
    delay(ramp_delay);
    BaseSpeed = current_speed;   // ← เดิมเขียนผิดเป็น target_speed
    InitialSpeed();
    PIDB(BackLeftBaseSpeed, BackRightBaseSpeed, _kp, _kd);
  }
  }
}

void softstartb(int target_speed ,float kp,float kd){
  if(modesoftstart == 1){
  const int ramp_step = 3;
  int current_speed = 0; // PWM
  int actual_target_speed = min(BackLeftBaseSpeed, BackRightBaseSpeed);  // ← เปลี่ยนชื่อ
 // float _kp = PID_KP_Back, _kd = PID_KP_Back; 
  while (current_speed < actual_target_speed) {
    current_speed += ramp_step;
    if (current_speed > actual_target_speed) {
      current_speed = actual_target_speed;
    }
    delay(ramp_delay);
    BaseSpeed = current_speed;   // ← เดิมเขียนผิดเป็น target_speed
    InitialSpeed();
    PIDB(BackLeftBaseSpeed, BackRightBaseSpeed, kp, kd);
  }
  }
}



void FFtimer(int baseSpeed, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
  }
  RGB();
}

void BBtimer(int baseSpeed, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
  }
  RGB();
}

void FFT(int baseSpeed, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
  }
  RGB();
}

void BBT(int baseSpeed, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
  }
  RGB();
}

///////////////////////////////////////////////////////////////////////////////////////
void TrackSelectF(int spd, char x) {
  if (x == 's') {
    MotorStop();
  } else if (x == 'S') {
    MotorShot();
  } 
  else if (x == 'p') {
    BZon();
    Motor(LeftBaseSpeed, RightBaseSpeed);
    delay(20);
    ReadCalibrateF();
    while (1) {
      Motor(LeftBaseSpeed, RightBaseSpeed);
      ReadCalibrateF();
      if (F[1] < Ref && F[6] < Ref) {
        delay(1500/spd);
        BZoff();
        break;
      }
    }
  } else if (x == 'l') {
    ToCenter();
    SpinL();
  } else if (x == 'L') {
    ToCenterC();
    SpinL();
  } else if (x == 'r') {
    ToCenter();
    SpinR();
  } else if (x == 'R') {
    ToCenterC();
    SpinR();
  } else if (x == 'q') {
    BZon();
    while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[0] < Ref) {
        BZoff();
        break;
      }
    }
    TurnLeft();
  } else if (x == 'e') {
    BZon();
    while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[7] < Ref) {
        BZoff();
        break;
      }
    }
    TurnRight();
  } else if (x == 'c') {
    ToCenter();
  } else if (x == 'C') {
    ToCenterC();
  } else if (x == 'b') {
    ToCenterCB();
  } else if (x == 'P') {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(2000/spd);
  } 

  else if (x == 'B') {
    BZon();
    Motor(LeftBaseSpeed, RightBaseSpeed);
    delay(20);
    while (1) {
      Motor(LeftBaseSpeed,RightBaseSpeed);
      ReadCalibrateB();
      if ((B[1] > Ref && B[6] > Ref)) {
        Motor(LeftBaseSpeed, RightBaseSpeed);
        delay(5);
        BZoff();
        break;
      }
    }
  }
  RGB();
}

void TrackSelectFR(int spd, char x) {
  if (x == 's') {
    MotorStop();
  } else if (x == 'S') {
    MotorShot();
  } else if (x == 'p') {
    BZon();
    Motor(LeftBaseSpeed, RightBaseSpeed);
    delay(30);
    ReadCalibrateF();
    while (1) {
      PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
      ReadCalibrateF();
      if (F[1] < Ref && F[6] < Ref) {
        delay(1500/spd);
        BZoff();
        break;
      }
    }
  } else if (x == 'l') {
    ToCenterR();
    SpinL();
  } else if (x == 'L') {
    ToCenterCR();
    SpinL();
  } else if (x == 'r') {
    ToCenterR();
    SpinR();
  } else if (x == 'R') {
    ToCenterCR();
    SpinR();
  } else if (x == 'q') {
    BZon();
     while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[0] < Ref ) {
        BZoff();
        break;
      }
    }
    TurnLeft();
  } else if (x == 'e') {
    BZon();
    while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[7] < Ref) {
        BZoff();
        break;
      }
    }
    TurnRight();
  } else if (x == 'c') {
    ToCenterR();
  } else if (x == 'C') {
    ToCenterCR();
  }
  else if (x == 'P') {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(2000/spd);
  } 

   else if (x == 'B') {
    BZon();
    Motor(LeftBaseSpeed, RightBaseSpeed);
    delay(20);
    while (1) {
      Motor(LeftBaseSpeed,RightBaseSpeed);
      ReadCalibrateB();
      if ((B[1] > Ref && B[6] > Ref)) {
        Motor(LeftBaseSpeed, RightBaseSpeed);
        delay(5);
        BZoff();
        break;
      }
    }
  }
  RGB();
}

void TrackSelectFL(int spd, char x) {
  if (x == 's') {
    MotorStop();
  } else if (x == 'S') {
    MotorShot();
  }  else if (x == 'p') {
    BZon();
    Motor(LeftBaseSpeed, RightBaseSpeed);
    delay(30);
    ReadCalibrateF();
    while (1) {
      PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
      ReadCalibrateF();
      if (F[1] < Ref && F[6] < Ref) {
        delay(1500/spd);
        BZoff();
        break;
      }
    }
  } else if (x == 'l') {
    ToCenterL();
    SpinL();
  } else if (x == 'L') {
    ToCenterCL();
    SpinL();
  } else if (x == 'r') {
    ToCenterL();
    SpinR();
  } else if (x == 'R') {
    ToCenterCL();
    SpinR();
  } else if (x == 'q') {
    BZon();
     while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if (F[0] < Ref ) {
        BZoff();
        break;
      }
    }
    TurnLeft();
  } else if (x == 'e') {
    BZon();
     while (1) {
      Motor(spd/2,spd/2);
      ReadCalibrateF();
      if ( F[7] < Ref) { 
        BZoff();
        break;
      }
    }
    TurnRight();
  } else if (x == 'c') {
    ToCenterL();
  } else if (x == 'C') {
    ToCenterCL();
  }
  else if (x == 'P') {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(2000/spd);
  } 
   else if (x == 'B') {
    BZon();
    Motor(LeftBaseSpeed, RightBaseSpeed);
    delay(20);
    while (1) {
      Motor(BackLeftBaseSpeed,RightBaseSpeed);
      ReadCalibrateB();
      if ((B[1] > Ref && B[6] > Ref)) {
        Motor(LeftBaseSpeed, RightBaseSpeed);
        delay(5);
        BZoff();
        break;
      }
    }
  }
  RGB();
}


void TrackSelectB(int spd, char x) {
  if (x == 's') {
    MotorStop();
  } else if (x == 'S') {
    MotorShot();
  } else if (x == 'p') {
    BZon();
    Motor(-BackLeftBaseSpeed, -BackRightBaseSpeed);
    delay(20);
    while (1) {
      Motor(-BackLeftBaseSpeed, -BackRightBaseSpeed);
      ReadCalibrateB();
      if ((B[1] < Ref && B[6] < Ref)) {
        Motor(-BackLeftBaseSpeed, -BackRightBaseSpeed);
        delay(1500/spd);
        BZoff();
        break;
      }
    }
  } else if (x == 'l') {
    BackCenter();
    SpinL();
  } else if (x == 'L') {
    BackCenterC();
    SpinL();
  } else if (x == 'r') {
    BackCenter();
    SpinR();
  } else if (x == 'R') {
    BackCenterC();
    SpinR();
  } else if (x == 'c') {
    BackCenter();
  } else if (x == 'C') {
    BackCenterC();
  } else if (x == 'q') {
    BZon();
     while (1) {
      Motor(-(spd/2),-(spd/2));
      ReadCalibrateB();
      if (B[7] < Ref ) {
        BZoff();
        break;
      }
    }
    BTurnLeft();
  } else if (x == 'e') {
    BZon();
     while (1) {
      Motor(-(spd/2),-(spd/2));
      ReadCalibrateB();
      if ( B[0] < Ref) { 
        BZoff();
        break;
      }
    }
    BTurnRight();
  }
  else if (x == 'P') {
    Motor(-BackLeftBaseSpeed, -BackRightBaseSpeed);
    Beep(2000/spd);
  }
  RGB();
}

void FF(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref) || (F[0] > Ref && F[2] > Ref) || (F[5] > Ref && F[7] > Ref)  || (F[2] > Ref && F[5] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFC(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref)||(F[1] > Ref && F[6] > Ref)||(F[2] > Ref && F[3] > Ref&& F[4] > Ref&& F[5] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFC2(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if (F[0] > Ref && F[7] > Ref) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFL(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if ((F[0] > Ref && F[2] > Ref)) {
      break;
    }
  }
  TrackSelectFL(Speed, select);
}

void FFL2(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if (F[0] > Ref && F[1] > Ref && F[2] > Ref && F[3] > Ref ) {
      break;
    }
  }
  TrackSelectFL(Speed, select);
}

void FFR(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if ((F[5] > Ref && F[7] > Ref)) {
      break;
    }
  }
  TrackSelectFR(Speed, select);
}


void FFR2(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
   PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if (F[4] > Ref && F[5] > Ref && F[6] > Ref && F[7] > Ref) {
      break;
    }
  }
  TrackSelectFR(Speed, select);
}

void FFWhite(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if (F[0] < Ref && F[1] < Ref&& F[2] < Ref&& F[3] < Ref&& F[4] < Ref&& F[5] < Ref&& F[6] < Ref && F[7] < Ref) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFBlack(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  Move(LeftBaseSpeed,RightBaseSpeed,50);
  while (1) {
    Motor(LeftBaseSpeed,RightBaseSpeed);
    ReadCalibrateF();
    if (F[0] > Ref || F[1] > Ref || F[2] > Ref || F[3] > Ref || F[4] > Ref || F[5] > Ref || F[6] > Ref || F[7] > Ref) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFBlack(int SpeedL,int SpeedR, char select) {
	
  Move(SpeedL,SpeedR,50);
  while (1) {
    Motor(SpeedL,SpeedR);
    ReadCalibrateF();
    if (F[0] > Ref || F[1] > Ref || F[2] > Ref || F[3] > Ref || F[4] > Ref || F[5] > Ref || F[6] > Ref || F[7] > Ref) {
      break;
    }
  }
  TrackSelectF(SpeedL, select);
}

void FFNUM(int Speed, char select, int numm) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    ReadCalibrateF();
    if ((F[numm] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FF_DISTANCE(int Speed, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,PID_KP,PID_KD);
    if (DistanceValue() <=  DisT) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}


void BB(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] > 200 && B[7] > 200) || (B[0] > 200 && B[2] > 200) || (B[5] > 200 && B[7] > 200) || (B[2] > Ref && B[5] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBC(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)||(B[1] > Ref && B[6] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBC2(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if (B[0] > Ref && B[7] > Ref) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBL(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] > Ref && B[2] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBR(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[5] > Ref && B[7] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBNUM(int Speed, char select, int numm) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[numm] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBWhite(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] < Ref && B[1] < Ref&& B[2] < Ref&& B[3] < Ref&& B[4] < Ref&& B[5] < Ref&& B[6] < Ref && B[7] < Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBBlack(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  Move(-BackLeftBaseSpeed,-BackRightBaseSpeed,50);
  while (1) {
    Motor(-BackLeftBaseSpeed,-BackRightBaseSpeed);
    ReadCalibrateB();
    if (B[0] > Ref || B[1] > Ref || B[2] > Ref || B[3] > Ref || B[4] > Ref || B[5] > Ref || B[6] > Ref || B[7] > Ref) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBBlack(int SpeedL,int SpeedR, char select) {
	
  Move(-SpeedL,-SpeedR,50);
  while (1) {
    Motor(-SpeedL,-SpeedR);
    ReadCalibrateB();
    if (B[0] > Ref || B[1] > Ref || B[2] > Ref || B[3] > Ref || B[4] > Ref || B[5] > Ref || B[6] > Ref || B[7] > Ref) {
      break;
    }
  }
  TrackSelectB(SpeedL, select);
}

void BB_DISTANCE(int Speed, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP,PID_KD);
    if (DistanceValue() >=  DisT) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}



//____________แบบกำหนดค่า Kp Kd เอง _________________________

void FFtimer(int baseSpeed,float Kp,float Kd, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
  }
  RGB();
  
}

void BBtimer(int baseSpeed,float Kp,float Kd, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
  }
  RGB();
}

void FFT(int baseSpeed,float Kp,float Kd, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
  }
  RGB();
}

void BBT(int baseSpeed,float Kp,float Kd, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
  }
  RGB();
}

void FF(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref) || (F[0] > Ref && F[2] > Ref) || (F[5] > Ref && F[7] > Ref)  || (F[2] > Ref && F[5] > Ref)){
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFC(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if ((F[0] > Ref && F[7] > Ref)||(F[1] > Ref && F[6] > Ref)||(F[2] > Ref && F[3] > Ref&& F[4] > Ref&& F[5] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FFC2(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if (F[0] > Ref && F[7] > Ref) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}


void FFL(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if ((F[0] > Ref && F[2] > Ref)) {
      break;
    }
  }
  TrackSelectFL(Speed, select);
}

void FFL2(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if (F[0] > Ref && F[1] > Ref && F[2] > Ref && F[3] > Ref ) {
      break;
    }
  }
  TrackSelectFL(Speed, select);
}

void FFR(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if ((F[5] > Ref && F[7] > Ref)) {
      break;
    }
  }
  TrackSelectFR(Speed, select);
}


void FFR2(int Speed, float Kp,float Kd,char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
   PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if (F[4] > Ref && F[5] > Ref && F[6] > Ref && F[7] > Ref) {
      break;
    }
  }
  TrackSelectFR(Speed, select);
}

void FFWhite(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if ((F[0] < Ref && F[1] < Ref&& F[2] < Ref&& F[3] < Ref&& F[4] < Ref&& F[5] < Ref&& F[6] < Ref && F[7] < Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}


void FFNUM(int Speed,float Kp,float Kd, char select, int numm) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    ReadCalibrateF();
    if ((F[numm] > Ref)) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void FF_DISTANCE(int Speed,float Kp,float Kd, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartf(Speed,Kp,Kd);
  while (1) {
    PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
    if (DistanceValue() <=  DisT) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}


void BB(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref) || (B[0] > Ref && B[2] > Ref) || (B[5] > Ref && B[7] > Ref) || (B[2] > Ref && B[5] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBC(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)||(B[1] > Ref && B[6] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBC2(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBL(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[0] > Ref && B[2] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBR(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[5] > Ref && B[7] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BBNUM(int Speed,float Kp,float Kd, char select, int numm) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[numm] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBWhite(int Speed,float Kp,float Kd, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[0] < Ref && B[1] < Ref&& B[2] < Ref&& B[3] < Ref&& B[4] < Ref&& B[5] < Ref&& B[6] < Ref && B[7] < Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void BB_DISTANCE(int Speed,float Kp,float Kd, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    if (DistanceValue() >=  DisT) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void FD_Dist(int Speed, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  while (1) {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    if (DistanceValue()  <=  DisT) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void BK_Dist(int Speed, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  while (1) {
    Motor(-BackLeftBaseSpeed, -BackRightBaseSpeed);
    if (DistanceValue() >=  DisT) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void SL_Dist(int Speed, int DisT) {
  MotorStop(0);
  Motor(-Speed, Speed);
  while(1)
  {
    if (DistanceValue() >=  DisT) {
      break;
    }
  }
  MotorStop(0);
}

void SR_Dist(int Speed, int DisT) {
  MotorStop(0);
  Motor(Speed, -Speed);
  while(1){
    if (DistanceValue() >=  DisT) {
      break;
    }
  }
  MotorStop(0);
}





//6 เซ็นเซอร์

int readPositionB1(int Track, int noise) {
  unsigned char i, online = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  static int last_value = 0;

  ReadCalibrateB();

  for (i = 0; i < NUM_SENSORS; i++) {

    // ข้ามเซนเซอร์ตัวที่ 6 (index 5)
    if (i == 6) continue;

    int values = B[i];

    if (values > Track) {
      online = 1;
    }

    if (values > noise) {
      avg += (long)(values) * (i * 1000);
      sum += values;
    }
  }

  if (!online) {
    if (dottedline) {
      return last_value;
    }
    if (last_value < (NUM_SENSORS - 1) * 1000 / 2) {
      return 0;
    } else {
      return (NUM_SENSORS - 1) * 1000;
    }
  }

  last_value = avg / sum;
  return last_value;
}

void PIDB1(int SpeedL, int SpeedR, float Kp, float Kd) {
  int Pos = readPositionB1(250, 50);
  int Error = Pos - set_position;
  int PID_Value = ((Kp / 1000.0) * Error) + ((Kd / 1000.0) * (Error - LastError_B));
  LastError_B = Error;

  int LeftPower  = SpeedL  + PID_Value;
  int RightPower = SpeedR - PID_Value;


switch (ModePidStatus) {
    case 0:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = MinSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = MinSpeed;
      break;
    case 1:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < MinSpeed) LeftPower = MinSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < MinSpeed) RightPower = MinSpeed;
      break;
    case 2:
      if (LeftPower > SpeedL) LeftPower = SpeedL;
      if (LeftPower < -SpeedL) LeftPower = -SpeedL;
      if (RightPower > SpeedR) RightPower = SpeedR;
      if (RightPower < -SpeedR) RightPower = -SpeedR;
      break;
    case 3:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = -BaseSpeed;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = -BaseSpeed;
      break;
    default:
      if (LeftPower > MaxSpeed) LeftPower = MaxSpeed;
      if (LeftPower < 0) LeftPower = 0;
      if (RightPower > MaxSpeed) RightPower = MaxSpeed;
      if (RightPower < 0) RightPower = 0;
  }

  Motor(-LeftPower, -RightPower); // วิ่งย้อน (กลับทิศกับ PIDF)
}

void _BBtimer(int baseSpeed, int totalTime) {
	BaseSpeed = baseSpeed;
	InitialSpeed();
  unsigned long startTime = millis();
  unsigned long endTime = startTime + totalTime;
  while (millis() <= endTime) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
  }
  RGB();
}




void _BB(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] > 200 && B[7] > 200) || (B[0] > 200 && B[2] > 200) || (B[5] > 200 && B[7] > 200) || (B[2] > Ref && B[5] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void _BBC(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref)||(B[1] > Ref && B[7] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void _BBC2(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if (B[0] > Ref && B[7] > Ref) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void _BBL(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] > Ref && B[2] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void _BBR(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[5] > Ref && B[7] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void _BBNUM(int Speed, char select, int numm) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[numm] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void _BBWhite(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP_Back,PID_KD_Back);
    ReadCalibrateB();
    if ((B[0] < Ref && B[1] < Ref&& B[2] < Ref&& B[3] < Ref&& B[4] < Ref&& B[5] < Ref&& B[6] < Ref && B[7] < Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void _BBBlack(int Speed, char select) {
	BaseSpeed = Speed;
	InitialSpeed();
  Move(-BackLeftBaseSpeed,-BackRightBaseSpeed,50);
  while (1) {
    Motor(-BackLeftBaseSpeed,-BackRightBaseSpeed);
    ReadCalibrateB();
    if (B[0] > Ref || B[1] > Ref || B[2] > Ref || B[3] > Ref || B[4] > Ref || B[5] > Ref || B[7] > Ref) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}

void _BBBlack(int SpeedL,int SpeedR, char select) {
	
  Move(-SpeedL,-SpeedR,50);
  while (1) {
    Motor(-SpeedL,-SpeedR);
    ReadCalibrateB();
    if (B[0] > Ref || B[1] > Ref || B[2] > Ref || B[3] > Ref || B[4] > Ref || B[5] > Ref ||  B[7] > Ref) {
      break;
    }
  }
  TrackSelectB(SpeedL, select);
}

void _BB_DISTANCE(int Speed, char select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  softstartb(Speed);
  while (1) {
    PIDB1(BackLeftBaseSpeed,BackRightBaseSpeed,PID_KP,PID_KD);
    if (DistanceValue() >=  DisT) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}
