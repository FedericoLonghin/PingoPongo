void controllaPulsanti() {
  if (digitalRead(pinV) == HIGH) {
    giocV.punti++;
    while (digitalRead(pinV) == HIGH) {}
  }
  if (digitalRead(pinR) == HIGH) {
    giocR.punti++;
    while (digitalRead(pinR) == HIGH) {}
  }
  if (digitalRead(pinA) == HIGH) {
    giocV.punti--;
    while (digitalRead(pinA) == HIGH) {}
  }
  if (digitalRead(pinB) == HIGH) {
    giocR.punti--;
    while (digitalRead(pinB) == HIGH) {}
  }
}

void gestisciPunti() {
  if (giocV.punti >= n_punti) {
    dati_set[set_corr-1].puntiV=giocV.punti;
    dati_set[set_corr-1].puntiR=giocR.punti;
    set_corr++;
    giocV.set_vinti++;
    giocV.punti = 0;
    giocR.punti = 0;
  }
  if (giocR.punti >= n_punti) {
    set_corr++;
    giocR.set_vinti++;
    giocV.punti = 0;
    giocR.punti = 0;
  }



}
bool vincitore() {
  if (giocV.set_vinti > giocR.set_vinti)return 0;
  else return 1;
}

void pulisci() {
  n_punti = 0;
  n_set = 0;
  set_corr = 1;
  giocV.nome = " ";
  giocV.punti = 0;
  giocV.set_vinti = 0;
  giocR.nome = " ";
  giocR.punti = 0;
  giocR.set_vinti = 0;
  is_partita = false;
  autoref=false;
}
