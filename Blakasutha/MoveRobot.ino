void MoveRobot(){
  if(integral < pwm_speed){
    integral+= 10;
  }
//  if (slowMove) {        //Motor move slow if R1 is pressed
//    integral /= 2;
//  }
  Serial.println(integral);  
  if(ps2x.Button(PSB_PAD_UP)){
    Serial.println("Robot Maju");
    kiri_atas_acw(integral+ kfrl[0]);
    kiri_bawah_acw(integral+ kbcl[0]);
    kanan_bawah_cw(integral+ kbcr[0]);
    kanan_atas_cw(integral+ kfrr[0]);
  }else
  if(ps2x.Button(PSB_PAD_DOWN)){
    Serial.println("Robot Mundur");
    kiri_atas_cw(integral+ kfrl[1]);
    kiri_bawah_cw(integral + kbcl[1]);
    kanan_bawah_acw(integral + kbcr[1]);
    kanan_atas_acw(integral+ kfrr[1]);    
  }else
   if(ps2x.Button(PSB_R2)){
      if(ps2x.Button(PSB_PAD_RIGHT)){
        Serial.println("Robot Putar Kanan");
        kiri_atas_acw(50);
        kiri_bawah_acw(50);
        kanan_bawah_acw(50);
        kanan_atas_acw(50); 
      }else if(ps2x.Button(PSB_PAD_LEFT)){
        Serial.println("Robot Putar Kiri");
        kiri_atas_cw(50);
        kiri_bawah_cw(50);
        kanan_bawah_cw(50);
        kanan_atas_cw(50);
      }
    }else
  if(ps2x.Button(PSB_PAD_LEFT)){
    Serial.println("Robot Geser Kiri");
    kiri_atas_cw(integral + kfrl[2]);
    kiri_bawah_acw(integral + kbcl[2]);
    kanan_bawah_acw(integral + kbcr[2]);
    kanan_atas_cw(integral + kfrr[2]); 
  }else
  if(ps2x.Button(PSB_PAD_RIGHT)){
    Serial.println("Robot Geser Kanan");
    kiri_atas_acw(integral+ kfrl[3]);
    kiri_bawah_cw(integral+ kbcl[3]);
    kanan_bawah_cw(integral+ kbcr[3]);
    kanan_atas_acw(integral+ kfrr[3]); 
   }else{
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    integral = 0;
  }
}

void maju()
{
    kiri_atas_acw(80);
    kiri_bawah_acw(80);
    kanan_bawah_cw(80);
    kanan_atas_cw(80);
}
