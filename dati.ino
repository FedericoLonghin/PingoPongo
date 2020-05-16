String pgDati() {
  String HTML = "<div class='d-none d-lg-block h-20'></div><div class=' p-2  bg-primary  rounded-pill '><h1 class='display-1'><strong>";
  HTML += giocV.nome;
  HTML += " - ";
  HTML += giocR.nome;
  HTML += "<br>";
  HTML += giocV.punti;
  HTML += " - ";
  HTML += giocR.punti;
  HTML += "</strong></h1> </div> <h1 class='display-2'> <strong>";
  HTML += giocV.set_vinti;
  HTML += " - ";
  HTML += giocR.set_vinti;
  HTML += "</strong></h1><a href='/cancella' class='btn btn-primary'> Termina</a>";

  return HTML;
}
