void MotorPWMKIA (int pwm)
{
  if (pwm >= 0) //cw 
  {
    analogWrite(pwmkia1, 0);
    analogWrite(pwmkia2, pwm);
  }else //acw
  {
    analogWrite(pwmkia1, pwm);
    analogWrite(pwmkia2, 0);
  }
}

void MotorPWMKIB (int pwm)
{
  if (pwm >= 0) //cw 
  {
    analogWrite(pwmkib1, 0);
    analogWrite(pwmkib2, pwm);
  }else //acw
  {
    analogWrite(pwmkib1, pwm);
    analogWrite(pwmkib2, 0);
  }
}

void MotorPWMKAA (int pwm)
{
  if (pwm >= 0) //cw 
  {
    analogWrite(pwmkaa1, 0);
    analogWrite(pwmkaa2, pwm);
  }else //acw
  {
    analogWrite(pwmkaa1, pwm);
    analogWrite(pwmkaa2, 0);
  }
}

void MotorPWMKAB (int pwm)
{
  if (pwm >= 0) //cw 
  {
    analogWrite(pwmkab1, 0);
    analogWrite(pwmkab2, pwm);
  }else //acw
  {
    analogWrite(pwmkab1, pwm);
    analogWrite(pwmkab2, 0);
  }
}
