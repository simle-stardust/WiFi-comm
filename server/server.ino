#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char *ssid = "Hermes";
const char *password = "getmesomemilk";

ESP8266WebServer server(80);

/* Test Message, Please Ignore*/
void handleRoot() {
	server.send(200, "text/html", "<h1>Hermes reporting for duty</h1>");
  Serial.println("HTTP server started");
}

void setup() {
	Serial.begin(115200);
	Serial.println();
	Serial.print("Hermes reporting for duty");
  
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
	server.on("/", handleRoot);
	server.begin();
	Serial.println("HTTP server started");
}

void loop() {
	server.handleClient();
}
