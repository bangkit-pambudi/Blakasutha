void restartPID() {
  setpointX = X;
  setpointY = Y;
  setpointC = C;
  lasterrorX = 0;
  lasterrorY = 0;
  lasterrorC = 0;
  errorX = 0;
  errorY = 0;
  errorC = 0;
  errorXi = 0;
  errorYi = 0;
  errorCi = 0;
  errorXd = 0;
  errorYd = 0;
  errorCd = 0;
}

void CalcXPID () {
  errorX = setpointX - X;
  errorXi += errorX * elapsedtime;
  errorXd = (errorX - lasterrorX) / elapsedtime;
  XPID = (Xp * errorX) + (Xi * errorXi) + (Xd * errorXd);
  lasterrorX = errorX;
  stickX = XPID;
}

void CalcYPID () {
  errorY = setpointY - Y;
  errorYi += errorY * elapsedtime;
  errorYd = (errorY - lasterrorY) / elapsedtime;
  YPID = (Yp * errorY) + (Yi * errorYi) + (Yd * errorYd);
  lasterrorY = errorY;
  stickY = YPID;
}

void CalcCPID () {
  errorC = setpointC - C;
  errorCi += errorC * elapsedtime;
  errorCd = (errorC - lasterrorC) / elapsedtime;
  CPID = (Cp * errorC) + (Ci * errorCi) + (Cd * errorCd);
  lasterrorC = errorC;
  stickW = CPID;
}

void CalcPID() {
  CalcXPID();
  CalcYPID();
  CalcCPID();
}
