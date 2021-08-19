//Kiri Atas
void reset_kiri_atas(){
  analogWrite(pwm_kiri_atas1, 0);
  analogWrite(pwm_kiri_atas2, 0);
}

void kiri_atas_cw(int pwm){
  reset_kiri_atas();
  analogWrite(pwm_kiri_atas1, 0);
  analogWrite(pwm_kiri_atas2, pwm);
}

void kiri_atas_acw(int pwm){
  reset_kiri_atas();
  analogWrite(pwm_kiri_atas1, pwm);
  analogWrite(pwm_kiri_atas2, 0);
}
//-----------------------------------------------

//Kiri Bawah
void reset_kiri_bawah(){
  analogWrite(pwm_kiri_bawah1, 0);
  analogWrite(pwm_kiri_bawah2, 0);
}

void kiri_bawah_cw(int pwm){
  reset_kiri_bawah();
  analogWrite(pwm_kiri_bawah1, 0);
  analogWrite(pwm_kiri_bawah2, pwm);
}

void kiri_bawah_acw(int pwm){
  reset_kiri_bawah();
  analogWrite(pwm_kiri_bawah1, pwm);
  analogWrite(pwm_kiri_bawah2, 0);
}
//-----------------------------------------------

//Kanan Bawah
void reset_kanan_bawah(){
  analogWrite(pwm_kanan_bawah1, 0);
  analogWrite(pwm_kanan_bawah2, 0);
}

void kanan_bawah_cw(int pwm){
  reset_kanan_bawah();
  analogWrite(pwm_kanan_bawah1, 0);
  analogWrite(pwm_kanan_bawah2, pwm);
}

void kanan_bawah_acw(int pwm){
  reset_kanan_bawah();
  analogWrite(pwm_kanan_bawah1, pwm);
  analogWrite(pwm_kanan_bawah2, 0);
}
//-----------------------------------------------

//Kanan Atas
void reset_kanan_atas(){
  analogWrite(pwm_kanan_atas1, 0);
  analogWrite(pwm_kanan_atas2, 0);
}

void kanan_atas_cw(int pwm){
  reset_kanan_atas();
  analogWrite(pwm_kanan_atas1, 0);
  analogWrite(pwm_kanan_atas2, pwm);
}

void kanan_atas_acw(int pwm){
  reset_kanan_atas();
  analogWrite(pwm_kanan_atas1, pwm);
  analogWrite(pwm_kanan_atas2, 0);
}

void check_integral( int data){
  if(data != tmp_data){
    tmp_data = data;
    integral = 0;
  }
}
