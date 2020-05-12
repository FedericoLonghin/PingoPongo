#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "./DNSServer.h"
#include<EEPROM.h>

const char* ssid = "Pingo Pongo";  // Enter SSID here
const char* password = "12345678";  //Enter Password here
IPAddress local_ip(10, 10, 10, 1);
IPAddress gateway(10, 10, 10, 1);
IPAddress subnet(255, 0, 0, 0);
ESP8266WebServer server(80);
const byte        DNS_PORT = 53;          // Capture DNS requests on port 53
DNSServer         dnsServer;              // Create the DNS object

int n_punti=0, n_set = 3, set_corr = 1;
bool is_partita = false;
struct giocatore {
  int punti = 0;
  String nome=" ";
  int set_vinti=0;
};
struct giocatore giocV, giocR;

int mod = 0;
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
  Serial.begin(115200);
  EEPROM.begin(512);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  dnsServer.setTTL(300);
  dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);

  dnsServer.start(DNS_PORT, "ping.pong", local_ip);
  dnsServer.start(DNS_PORT, "*", local_ip);



  server.on("/", handle_index);
  server.on("/crea", handle_crea);
  server.on("/partita", handle_partita);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
  switch (mod) {
    case 1:
      controllaPulsanti();
      vittoria();
      Serial.print("\nset: ");
      Serial.print(giocV.set_vinti);
      Serial.print(" - ");
      Serial.print(giocR.set_vinti);
      Serial.print("      punti: ");
      Serial.print(giocV.punti);
      Serial.print(" - ");
      Serial.print(giocR.punti);
      break;
    case 2:
      Serial.println("FINE");
      break;
    default:
      while (n_punti == 0) {
        dnsServer.processNextRequest();
        server.handleClient();
        Serial.println("premi 'C' per continuare");

      }
      mod = 1;
      break;
  }
}
