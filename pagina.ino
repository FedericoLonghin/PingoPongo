void handle_index() {
  String html = "errore";
  if (is_partita) {
    if (set_corr > n_set) {
      html = pgVittoria();
      pulisci();
    }
    else
      html = pgPartita();

  }
  else {
    html = pgForm();
  }
  server.send(200, "text/html", html);
}
void handle_dati() {
  server.send(200, "text/html", pgDati());
}






void handle_conf() {
  Serial.println("crea");
  giocV.nome = server.arg("GV");
  giocR.nome = server.arg("GR");
  n_punti = server.arg("n-punti").toFloat();
  n_set = server.arg("n-set").toFloat();
  if (server.arg("autoref") == "on")autoref == true;
  EEPROM.write(0, n_punti);
  EEPROM.commit();
  Serial.print(giocV.nome);
  Serial.print(giocR.nome);
  Serial.print(n_punti);
  Serial.println(n_set);
  is_partita = true;
  server.send(200, "text/html", "<meta http-equiv='refresh' content='1; URL=/' >");
}



void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
