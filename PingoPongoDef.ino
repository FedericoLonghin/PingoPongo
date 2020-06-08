    #include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include "./DNSServer.h"


const char* ssid = "Pingo Pongo";  // Enter SSID here
const char* password = "12345678";  //Enter Password here
IPAddress local_ip(10, 10, 10, 1);
IPAddress gateway(10, 10, 10, 1);
IPAddress subnet(255, 0, 0, 0);
ESP8266WebServer server(80);


int n_punti = 0, n_set_fine = 0, set_corr = 1;
bool is_partita = false;
bool autoref = false;
struct giocatore {
  String nome = " ";
  int punti = 0;
  int set_vinti = 0;
};
struct giocatore giocV, giocR;
struct dato_set {
  int  puntiV;
  int puntiR;
};
struct dato_set dati_set[9];
#define pinV 13
#define pinR 15
#define pinA 12
#define pinB 14
#define pinC 16



void setup() {

  pinMode(pinV, INPUT);
  pinMode(pinR, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(D4, OUTPUT);
  Serial.begin(115200);


  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);



  server.on("/", handle_index);
  server.on("/conf", handle_conf);
  server.on("/dati", handle_dati);
//  server.on("/info", handle_info);
    server.on("/cancella", handle_cancella);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  // put your main code here, to run repeatedly:

  if (is_partita) {
    controllaPulsanti();
    gestisciPunti();
  }

}
