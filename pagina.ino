void handle_index() {
  String html = "errore";
  if (is_partita) {
    html = pgPartita();
  }
  else {
    html = pgForm();
  }
  server.send(200, "text/html", html);
}





/**

*/
void handle_dati() {
  String html = pgDati();
  int codice = 0;
  Serial.print("giocR.set_vinti: ");
  Serial.print(giocR.set_vinti);
  Serial.print(" n_set_fine: ");
  Serial.println(n_set_fine );
  if (giocR.set_vinti > n_set_fine||giocV.set_vinti > n_set_fine) {
    Serial.println("fine");
    html = pgVittoria();
    codice = 1;
    pulisci();
  }
  String R = "{ \"html\":\"";
  R += html;
  R += "\",";
  R += "\"code\":";
  R += codice;
  R += "}";
  Serial.println(R);
  server.send(200, "text/html", R);
}





//
//void handle_info() {
//  String html = "<!DOCTYPE html><html><head> <title>Pingo Pongo</title> <style> /*! CSS Used from: https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css */*,::after,::before{box-sizing:border-box;}body{margin:0;font-family:-apple-system,BlinkMacSystemFont,'Segoe UI',Roboto,'Helvetica Neue',Arial,sans-serif,'Apple Color Emoji','Segoe UI Emoji','Segoe UI Symbol';font-size:1rem;font-weight:400;line-height:1.5;color:#212529;text-align:left;background-color:#fff;}h3,h4{margin-top:0;margin-bottom:.5rem;}p{margin-top:0;margin-bottom:1rem;}ul{margin-top:0;margin-bottom:1rem;}a{color:#007bff;text-decoration:none;background-color:transparent;-webkit-text-decoration-skip:objects;}a:hover{color:#0056b3;text-decoration:underline;}h3,h4{margin-bottom:.5rem;font-family:inherit;font-weight:500;line-height:1.2;color:inherit;}h3{font-size:1.75rem;}h4{font-size:1.5rem;}.container{width:100%;padding-right:15px;padding-left:15px;margin-right:auto;margin-left:auto;}@media (min-width:576px){.container{max-width:540px;}}@media (min-width:768px){.container{max-width:720px;}}@media (min-width:992px){.container{max-width:960px;}}@media (min-width:1200px){.container{max-width:1140px;}}.btn{display:inline-block;font-weight:400;text-align:center;white-space:nowrap;vertical-align:middle;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none;border:1px solid transparent;padding:.375rem .75rem;font-size:1rem;line-height:1.5;border-radius:.25rem;transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out;}.btn:focus,.btn:hover{text-decoration:none;}.btn:focus{outline:0;box-shadow:0 0 0 .2rem rgba(0,123,255,.25);}.btn:disabled{opacity:.65;}.btn-primary{color:#fff;background-color:#007bff;border-color:#007bff;}.btn-primary:hover{color:#fff;background-color:#0069d9;border-color:#0062cc;}.btn-primary:focus{box-shadow:0 0 0 .2rem rgba(0,123,255,.5);}.btn-primary:disabled{color:#fff;background-color:#007bff;border-color:#007bff;}.text-muted{color:#6c757d!important;}@media print{*,::after,::before{text-shadow:none!important;box-shadow:none!important;}a:not(.btn){text-decoration:underline;}h3,p{orphans:3;widows:3;}h3{page-break-after:avoid;}body{min-width:992px!important;}.container{min-width:992px!important;}} </style></head><body> <div class='container'> <div class='text'> <h3>Tutto quello che devi sapere</h3> <br> <h4 class='text-muted'>Informazioni</h4> <p>Segnapunti per il ping pong fatto da Samuele e Federico Longhin.</p> <p>Versione: 1.0 - Maggio 2020</p> <h4 class='text-muted'>Cosa c'è di Nuovo?</h4> <p>Essendo la prima versione rilasciata possiamo lasciare questo campo libero.</p> <br> <h4 class='text-muted'>procedura per gli aggiornamenti</h4> É la prima volta? <ul> <li>Scaricare l' <a href='https://www.arduino.cc/en/Main/Software'>IDE di Arduino</a> per il proprio sistema. </li> <li>Eseguire la procedura di installazione guidata per installare 'Arduino IDE'. </li> <li>Dentro l'IDE, premere su 'strumenti' --> 'scheda' --> 'gestore schede'.</li> <li>Cercare 'esp8266' e installare la libreria 'esp8266'.</li> <li>proseguire con i punti del prossimo elenco</li> </ul> l'hai già fatto? <ul> <li>Scaricare il codice dalla <a href='https://github.com/fededelong03/PingoPongo'>pagina GitHub</a>, premendo su 'clone or download' --> 'download zip'.</lik> </li> <li>Estrarre la cartella scaricata e aprire il file 'PingoPongoDef.ino'.</li> <li>Collegare il contapunti al computer.</li><li>Nel menù 'strumenti' --> 'scheda' selezionare 'NodeMCU 1.0 (ESP-E12 module)'.</li><li>Sempre nel menù 'strumenti' selezionare 'porta' e selezionare la porta visibile che compare (COM...).</li><li>Aprire il contapunti e mettere lo switch in posizione 'DEV'.</li><li>Premere su 'carica' (secondo cerchio da sinistra).</li><li>Se compaiono errori durante il caricameto provare a selezionare una porta diversa(se presente) vedi punto 9.<br> Se non si risolve mandare una foto della schermata a Federico.</li><li>Alla fine del caricamento (quando compare in basso 'caricamento completato') portare lo switch in posizione 'USER' e scollegare la scheda.</li><li>FINE.</li> </ul> <br> </div> <a class='btn btn-primary' href='http://10.10.10.1' role='button'>torna alla Home </a> </div></body> </html>";
//  server.send(200, "text/html", html);
//}




void handle_cancella() {
  server.send(200, "text/html", "<meta http-equiv='refresh' content='1; URL=/' >");
  pulisci();
  Serial.println("FATTO");
}




void handle_conf() {
  Serial.println("crea");
  giocV.nome = server.arg("GV");
  giocR.nome = server.arg("GR");
  n_punti = server.arg("n-punti").toFloat();
  n_set_fine = (server.arg("n-set").toFloat()/2);
  autoref = (server.arg("autoref") == "on") ? true : false;

  Serial.print(giocV.nome);
  Serial.print(giocR.nome);
  Serial.print(n_punti);
  Serial.println(n_set_fine);
  is_partita = true;
  server.send(200, "text/html", "<meta http-equiv='refresh' content='1; URL=/' >");
}



void handle_NotFound() {
  server.send(404, "text/plain", "OPS: questa pagina non esiste");
}
