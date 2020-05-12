void controllaPulsanti() {
  if (digitalRead(pinV) == HIGH) {
    giocV.punti++;
    while (digitalRead(pinV) == HIGH){}
    }
  if (digitalRead(pinR) == HIGH) {
    giocR.punti++;
    while (digitalRead(pinR) == HIGH){}
    }
  if (digitalRead(pinA) == HIGH) {
    giocV.punti--;
    while (digitalRead(pinA) == HIGH){}
    }
  if (digitalRead(pinB) == HIGH) {
    giocR.punti--;
    while (digitalRead(pinB) == HIGH){}
    }
}
void vittoria(){
  if (giocV.punti == n_punti) {
      set_corr++;
      giocV.punti = 0;
      giocR.punti = 0;
      giocV.set_vinti++;
      if (set_corr > n_set) {
        //mod=2;
    }
    else {
      //il verde ha vinto
      
    }
  }
   if (giocR.punti == n_punti) {
      set_corr++;
      giocV.punti = 0;
      giocR.punti = 0;
      giocR.set_vinti++;
      if (set_corr > n_set) {
       // mod=2;
       // if(giocV.set_vinti>=giocR.set_vinti)
       // else
    }
   
  }
}
