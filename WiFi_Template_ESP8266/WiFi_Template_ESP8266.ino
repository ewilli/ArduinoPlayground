#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);
 
const char* ssid = "SSID";
const char* password = "PW";
 
// == http://makesmartesp.local/ 
const char* dns_name = "esp8266";
 
void eigeneFunktion();
 
void setup()
{
  Serial.begin(115200);
  Serial.println("ESP Gestartet");
 
  WiFi.begin(ssid, password);
 
  Serial.print("Verbindung wird hergestellt ...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
 
  Serial.print("Verbunden! IP-Adresse: ");
  Serial.println(WiFi.localIP());
 
  // Bei Android-Geräten wird der mDNS oft nicht unterstützt, dann muss auf die IP-Adresse zurückgegriffen werden
  if (MDNS.begin(dns_name)) {
    Serial.println("DNS gestartet, erreichbar unter: ");
    Serial.println("http://" + String(dns_name) + ".local/");
  }
 
  server.onNotFound([](){
    server.send(404, "text/plain", "Link wurde nicht gefunden!");  
  });
 
  server.on("/", []() {
    server.send(200, "text/plain", "ESP-Startseite!");
  });
 
  server.on("/custom", []() {
    server.send(200, "text/plain", "Nur eine Beispiel-Route");
    eigeneFunktion();
  });
 
  server.begin();
  Serial.println("Webserver gestartet.");
}
 
void loop() {
  server.handleClient();  
  MDNS.update();
}
 
void eigeneFunktion(){
  Serial.println("unsere eigene Funktion wird ausgeführt ...");
}

