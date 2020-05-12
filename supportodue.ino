
String dammiCodice(char* variante) {
  String HTML;
 
  if (variante == "index") {
    HTML = "<html><head><title>index</title><style>";
    HTML += "body { background-color: #ffffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }";
    HTML += "  </style></head><body >";
    HTML += "<h1>benvenuto nella pagina di gestione pingopongo! </h1> ";
    HTML += "inserisci i dati e inizia la partita";
    HTML += "<form action = ' /crea'>";

    HTML += "<label for = 'f1'>Giocatore1: </label > <br>";
    HTML += "<input type = 'text' id = 'GV' name = 'GV'><br><br>";

    HTML += "<label for = 'f2'>Giocatore2: </label > <br>";
    HTML += "<input type = 'text' id = 'GR' name = 'GR'><br><br>";

    HTML += "<label for='punti'>Punti:</label><br>";
    HTML += "<input type='text' id ='P' name='P' value=";
    HTML +=EEPROM.read(0);
    HTML+="><br><br>";
    
    HTML += " <input type='submit' value='INIZIA'>";
    HTML += "</form></body ></html >";

  }

  if (variante == "crea") {
    HTML="<html><head><title>Pagina di Redirect </title>";
     HTML+="<meta http-equiv='refresh' content='1; URL=/partita' >";
     HTML+="</head><body></body></html>";

  }
  if (variante == "partita") {
    HTML="<!DOCTYPE html><html><head><meta http-equiv='refresh' content='10'><title>Partita - Pingo Pongo</title><style></style></head><body><div>punti: ";
    HTML+= giocV.punti;
    HTML+=" - ";
    HTML+=giocR.punti;
    HTML+="<br> set: ";
    HTML+= giocV.set_vinti;
    HTML+=" - ";
    HTML+=giocR.set_vinti;
        HTML+="<br> giocatori: ";
    HTML+= giocV.nome;
    HTML+=" - ";
    HTML+=giocR.nome;
    
    HTML+="<br> punti: ";
    HTML+= n_punti;
    HTML+="</div></body></html>";
  }
  return HTML;
}

void handle_index() {
  Serial.println("index");
  server.send(200, "text/html", dammiCodice("index"));
}

void handle_crea() {
  server.send(200, "text/html", dammiCodice("crea"));
  Serial.println("crea");
  giocV.nome = server.arg("GV");
  giocR.nome = server.arg("GR");
  n_punti=server.arg("P").toFloat();
  EEPROM.write(0, n_punti);
  EEPROM.commit();
  Serial.println(giocV.nome);
  Serial.println(giocR.nome);
  Serial.println(n_punti);
}

void handle_partita(){
  server.send(200, "text/html", dammiCodice("partita"));
  
}

void handle_NotFound() {

  server.send(404, "text/plain", "Not found");
}
