void MoveRobot(){
  if(ps2x.Button(PSB_PAD_UP)){
    Serial.println("Robot Maju");
    kiri_atas_acw(integral);
    kiri_bawah_acw(integral);
    kanan_bawah_cw(integral);
    kanan_atas_cw(integral);
  }else
  if(ps2x.Button(PSB_PAD_DOWN)){
    Serial.println("Robot Mundur");
    kiri_atas_cw(integral);
    kiri_bawah_cw(integral + 7);
    kanan_bawah_acw(integral);
    kanan_atas_acw(integral);    
  }else
  if(ps2x.Button(PSB_PAD_LEFT)){
    Serial.println("Robot Geser Kiri");
    kiri_atas_cw(integral);
    kiri_bawah_acw(integral + 7);
    kanan_bawah_acw(integral + 5);
    kanan_atas_cw(integral); 
  }else
  if(ps2x.Button(PSB_PAD_RIGHT)){
    Serial.println("Robot Geser Kanan");
    kiri_atas_acw(integral);
    kiri_bawah_cw(integral);
    kanan_bawah_cw(integral);
    kanan_atas_acw(integral); 
    }else
   if(ps2x.Button(PSB_R1)){
      if(ps2x.Button(PSB_PAD_RIGHT)){
        Serial.println("Robot Putar Kanan");
        kiri_atas_acw(integral);
        kiri_bawah_acw(integral);
        kanan_bawah_acw(integral);
        kanan_atas_acw(integral); 
      }else if(ps2x.Button(PSB_PAD_LEFT)){
        Serial.println("Robot Putar Kiri");
        kiri_atas_cw(integral);
        kiri_bawah_cw(integral);
        kanan_bawah_cw(integral);
        kanan_atas_cw(integral);
      }
    }else{
    reset_kiri_atas();
    reset_kiri_bawah();
    reset_kanan_bawah();
    reset_kanan_atas();
    integral = 0;
  }
}
