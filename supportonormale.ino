void controllaPulsanti() {
  if (digitalRead(pinV) == HIGH)giocV.punti++;
  if (digitalRead(pinR) == HIGH)giocR.punti++;
  if (digitalRead(pinA) == HIGH)giocV.punti--;
  if (digitalRead(pinB) == HIGH)giocR.punti--;
//  if (digitalRead(pinV) == HIGH)
}
