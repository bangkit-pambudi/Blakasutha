void restartPID() {
  setpointC = C;
  lasterrorC = 0;
  errorC = 0;
  errorCi = 0;
  errorCd = 0;
}



void CalcCPID () {
  errorC = setpointC - C;
  errorCi += errorC * elapsedtime;
  errorCd = (errorC - lasterrorC) / elapsedtime;
  CPID = (Cp * errorC) + (Ci * errorCi) + (Cd * errorCd);
  lasterrorC = errorC;
  stickW = CPID;
}
