#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "./DNSServer.h"
#include<EEPROM.h>
/* Put your SSID & Password */
const char* ssid = "Pingo Pongo";  // Enter SSID here
const char* password = "12345678";  //Enter Password here
int punti_fine;
struct giocatore {
  int punti = 0;
  String nome;
};
struct giocatore giocV, giocR;
bool is_partita = false;
/* Put IP Address details */
IPAddress local_ip(10, 10, 10, 1);
IPAddress gateway(10, 10, 10, 1);
IPAddress subnet(255, 0, 0, 0);

ESP8266WebServer server(80);

const byte        DNS_PORT = 53;          // Capture DNS requests on port 53
DNSServer         dnsServer;              // Create the DNS object

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
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
  controllaPulsanti();
  Serial.print("punti verde: ");
  Serial.print(giocV.punti);
  Serial.print("punti rossi: ");
  Serial.println(giocR.punti);
}
