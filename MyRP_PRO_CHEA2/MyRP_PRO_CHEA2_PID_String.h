

///_____________________String___________________________________
///////////////////////////////////////////////////////////////////////////////////////
void TrackSelectF(int spd, String x) {
  if (x == "s") {
    MotorStop();
  } else if (x == "S") {
    MotorShot();
  } 
  else if (x == "p") {
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
  } else if (x == "l") {
    ToCenter();
    SpinL();
  } else if (x == "L") {
    ToCenterC();
    SpinL();
  } else if (x == "r") {
    ToCenter();
    SpinR();
  } else if (x == "R") {
    ToCenterC();
    SpinR();
  } else if (x == "q") {
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
  } else if (x == "e") {
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
  } else if (x == "c") {
    ToCenter();
  } else if (x == "C") {
    ToCenterC();
  } else if (x == "b") {
    ToCenterCB();
  } else if (x == "P") {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(2000/spd);
  } 

  else if (x == "B") {
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
   else if (x == "Bl" || x == "bl" ) {
    // ToCenterCB();
    BSpinL();
  } else if (x == "BL" || x == "bL") {
    ToCenterC();
    BSpinL();
  } else if (x == "Br" || x == "br") {
    // ToCenterCB();
    BSpinR();
  } else if (x == "BR" || x == "bR") {
   ToCenterC();
    BSpinR();
  }

  else if (x == "Bq" || x == "bq") {
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
  } else if (x == "Be" || x == "be") {
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
  RGB();
}

void TrackSelectFR(int spd, String x) {
  if (x == "s") {
    MotorStop();
  } else if (x == "S") {
    MotorShot();
  } else if (x == "p") {
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
  } else if (x == "l") {
    ToCenterR();
    SpinL();
  } else if (x == "L") {
    ToCenterCR();
    SpinL();
  } else if (x == "r") {
    ToCenterR();
    SpinR();
  } else if (x == "R") {
    ToCenterCR();
    SpinR();
  } else if (x == "q") {
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
  } else if (x == "e") {
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
  } else if (x == "c") {
    ToCenterR();
  } else if (x == "C") {
    ToCenterCR();
  }
  else if (x == "P") {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(2000/spd);
  } 

   else if (x == "B") {
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
  else if (x == "Bl" || x == "bl" ) {
    // ToCenterCB();
    BSpinL();
  } else if (x == "BL" || x == "bL") {
    ToCenterCR();
    BSpinL();
  } else if (x == "Br" || x == "br") {
    // ToCenterCB();
    BSpinR();
  } else if (x == "BR" || x == "bR") {
    ToCenterCR();
    BSpinR();
  }

  else if (x == "Bq" || x == "bq") {
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
  } else if (x == "Be" || x == "be") {
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
  RGB();
}

void TrackSelectFL(int spd, String x) {
  if (x == "s") {
    MotorStop();
  } else if (x == "S") {
    MotorShot();
  }  else if (x == "p") {
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
  } else if (x == "l") {
    ToCenterL();
    SpinL();
  } else if (x == "L") {
    ToCenterCL();
    SpinL();
  } else if (x == "r") {
    ToCenterL();
    SpinR();
  } else if (x == "R") {
    ToCenterCL();
    SpinR();
  } else if (x == "q") {
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
  } else if (x == "e") {
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
  } else if (x == "c") {
    ToCenterL();
  } else if (x == "C") {
    ToCenterCL();
  }
  else if (x == "P") {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    Beep(2000/spd);
  } 
  else if (x == "B") {
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
  else if (x == "Bl" || x == "bl" ) {
    // ToCenterCB();
    BSpinL();
  } else if (x == "BL" || x == "bL") {
    ToCenterCL();
    BSpinL();
  } else if (x == "Br" || x == "br") {
    // ToCenterCB();
    BSpinR();
  } else if (x == "BR" || x == "bR") {
    ToCenterCL();
    BSpinR();
  }

  else if (x == "Bq" || x == "bq") {
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
  } else if (x == "Be" || x == "be") {
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
  RGB();
}


void TrackSelectB(int spd, String x) {
  if (x == "s") {
    MotorStop();
  } else if (x == "S") {
    MotorShot();
  } else if (x == "p") {
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
  } else if (x == "l") {
    BackCenter();
    SpinL();
  } else if (x == "L") {
    BackCenterC();
    SpinL();
  } else if (x == "r") {
    BackCenter();
    SpinR();
  } else if (x == "R") {
    BackCenterC();
    SpinR();
  } else if (x == "c") {
    BackCenter();
  } else if (x == "C") {
    BackCenterC();
  } else if (x == "q") {
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
  } else if (x == "e") {
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
  else if (x == "P") {
    Motor(-BackLeftBaseSpeed, -BackRightBaseSpeed);
    Beep(2000/spd);
  }
  else if (x == "Bl" || x == "bl" ) {
    BackCenter();
    BSpinL();
  } else if (x == "BL" || x == "bL") {
    BackCenterC();
    BSpinL();
  } else if (x == "Br" || x == "br") {
    BackCenter();
    BSpinR();
  } else if (x == "BR" || x == "bR") {
    BackCenterC();
    BSpinR();
  }

  else if (x == "Bq" || x == "bq") {
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
  } else if (x == "Be" || x == "be") {
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
  RGB();
}


//__________________String________


void FF(int Speed, String select) {
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

void FFC(int Speed, String select) {
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

void FFC2(int Speed, String select) {
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

void FFL(int Speed, String select) {
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

void FFL2(int Speed, String select) {
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

void FFR(int Speed, String select) {
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


void FFR2(int Speed, String select) {
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

void FFWhite(int Speed, String select) {
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

void FFBlack(int Speed, String select) {
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

void FFBlack(int SpeedL,int SpeedR, String select) {
	
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

void FFNUM(int Speed, String select, int numm) {
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

void FF_DISTANCE(int Speed, String select, int DisT) {
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


void BB(int Speed, String select) {
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


void BBC(int Speed, String select) {
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

void BBC2(int Speed, String select) {
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

void BBL(int Speed, String select) {
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

void BBR(int Speed, String select) {
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

void BBNUM(int Speed, String select, int numm) {
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


void BBWhite(int Speed, String select) {
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

void BBBlack(int Speed, String select) {
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

void BBBlack(int SpeedL,int SpeedR, String select) {
	
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

void BB_DISTANCE(int Speed, String select, int DisT) {
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

// void FFtimer(int baseSpeed,float Kp,float Kd, int totalTime) {
// 	BaseSpeed = baseSpeed;
// 	InitialSpeed();
//   unsigned long startTime = millis();
//   unsigned long endTime = startTime + totalTime;
//   while (millis() <= endTime) {
//     PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
//   }
//   RGB();
  
// }

// void BBtimer(int baseSpeed,float Kp,float Kd, int totalTime) {
// 	BaseSpeed = baseSpeed;
// 	InitialSpeed();
//   unsigned long startTime = millis();
//   unsigned long endTime = startTime + totalTime;
//   while (millis() <= endTime) {
//     PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
//   }
//   RGB();
// }

// void FFT(int baseSpeed,float Kp,float Kd, int totalTime) {
// 	BaseSpeed = baseSpeed;
// 	InitialSpeed();
//   unsigned long startTime = millis();
//   unsigned long endTime = startTime + totalTime;
//   while (millis() <= endTime) {
//     PIDF(LeftBaseSpeed,RightBaseSpeed,Kp,Kd);
//   }
//   RGB();
// }

// void BBT(int baseSpeed,float Kp,float Kd, int totalTime) {
// 	BaseSpeed = baseSpeed;
// 	InitialSpeed();
//   unsigned long startTime = millis();
//   unsigned long endTime = startTime + totalTime;
//   while (millis() <= endTime) {
//     PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
//   }
//   RGB();
// }

void FF(int Speed,float Kp,float Kd, String select) {
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

void FFC(int Speed,float Kp,float Kd, String select) {
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

void FFC2(int Speed,float Kp,float Kd, String select) {
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


void FFL(int Speed,float Kp,float Kd, String select) {
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

void FFL2(int Speed,float Kp,float Kd, String select) {
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

void FFR(int Speed,float Kp,float Kd, String select) {
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


void FFR2(int Speed, float Kp,float Kd,String select) {
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

void FFWhite(int Speed,float Kp,float Kd, String select) {
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


void FFNUM(int Speed,float Kp,float Kd, String select, int numm) {
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

void FF_DISTANCE(int Speed,float Kp,float Kd, String select, int DisT) {
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


void BB(int Speed,float Kp,float Kd, String select) {
	BaseSpeed = Speed;
	InitialSpeed();
    softstartf(Speed,Kp,Kd);
  while (1) {
    PIDB(BackLeftBaseSpeed,BackRightBaseSpeed,Kp,Kd);
    ReadCalibrateB();
    if ((B[0] > Ref && B[7] > Ref) || (B[0] > Ref && B[2] > Ref) || (B[5] > Ref && B[7] > Ref) || (B[2] > Ref && B[5] > Ref)) {
      break;
    }
  }
  TrackSelectB(Speed, select);
}


void BBC(int Speed,float Kp,float Kd, String select) {
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


void BBC2(int Speed,float Kp,float Kd, String select) {
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


void BBL(int Speed,float Kp,float Kd, String select) {
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

void BBR(int Speed,float Kp,float Kd, String select) {
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

void BBNUM(int Speed,float Kp,float Kd, String select, int numm) {
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


void BBWhite(int Speed,float Kp,float Kd, String select) {
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

void BB_DISTANCE(int Speed,float Kp,float Kd, String select, int DisT) {
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


void FD_Dist(int Speed, String select, int DisT) {
	BaseSpeed = Speed;
	InitialSpeed();
  while (1) {
    Motor(LeftBaseSpeed, RightBaseSpeed);
    if (analogRead(DIST) <=  DisT) {
      break;
    }
  }
  TrackSelectF(Speed, select);
}

void BK_Dist(int Speed, String select, int DisT) {
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
