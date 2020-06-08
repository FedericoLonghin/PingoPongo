String pgVittoria() {
  String HTML = "<div class='d-none d-lg-block h-20'></div><div class=' p-2  bg-primary  rounded-pill '><h1 class='display-1'><strong>";
  HTML += "Ha vinto: <br>";
   if (giocV.set_vinti > giocR.set_vinti)HTML +=giocV.nome;
   else HTML+=giocR.nome;
  HTML += "</strong></h1><a href='/cancella' class='btn btn-primary'> Termina</a> </div> <h1 class='display-2'> <strong>";
  HTML += "</strong></h1>";
  return HTML;
}
