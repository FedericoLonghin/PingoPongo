void controllaPulsanti() {
  if (digitalRead(pinV) == HIGH) {
    giocV.punti++;
    digitalWrite(D4, 1);
    delay(100);
    while (digitalRead(pinV) == HIGH) {}
    digitalWrite(D4, 0);
  }
  if (digitalRead(pinR) == HIGH) {
    giocR.punti++;
    digitalWrite(D4, 1);
    delay(100);
    while (digitalRead(pinR) == HIGH) {}
    digitalWrite(D4, 0);
  }
  if (digitalRead(pinA) == HIGH && giocV.punti > 0) {
    giocV.punti--;
    digitalWrite(D4, 1);
    delay(100);
    while (digitalRead(pinA) == HIGH) {}
    digitalWrite(D4, 0);
  }
  if (digitalRead(pinB) == HIGH && giocR.punti > 0) {
    giocR.punti--;
    digitalWrite(D4, 1);
    delay(100);
    while (digitalRead(pinB) == HIGH) {}
    digitalWrite(D4, 0);
  }
}


void gestisciPunti() {
  if (giocV.punti >= n_punti) {
    dati_set[set_corr - 1].puntiV = giocV.punti;
    dati_set[set_corr - 1].puntiR = giocR.punti;
    set_corr++;
    giocV.set_vinti++;
    giocV.punti = 0;
    giocR.punti = 0;
  }
  if (giocR.punti >= n_punti) {
    dati_set[set_corr - 1].puntiV = giocV.punti;
    dati_set[set_corr - 1].puntiR = giocR.punti;
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
  autoref = false;
}
