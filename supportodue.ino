
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
    HTML += "<input type = 'text' id = 'f1' name = 'G1'><br><br>";

    HTML += "<label for = 'f2'>Giocatore2: </label > <br>";
    HTML += "<input type = 'text' id = 'f1' name = 'G2'><br><br>";

    HTML += "<label for='punti'>Punti:</label><br>";
    HTML += "<input type='text' id='punti' name='P' value=";
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
  return HTML;
}

void handle_index() {
  Serial.println("index");
  server.send(200, "text/html", dammiCodice("index"));
}

void handle_crea() {
  server.send(200, "text/html", dammiCodice("crea"));
  Serial.println("crea");
  giocV.nome = server.arg("G1");
  giocR.nome = server.arg("G2");
  EEPROM.write(0, server.arg("P").toFloat());
  Serial.println(giocV.nome);
  Serial.println(giocR.nome);
  Serial.println(punti_fine);
}
void handle_NotFound() {

  server.send(404, "text/plain", "Not found");
}
