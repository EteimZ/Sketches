/*
  Setup WebServer by connecting to a WiFi Network.
*/

#include <WiFi.h>
#include <WebServer.h>

// WiFi Network credentials
const char *ssid = "...........";
const char *password = ".......";

WebServer server(80);

void setup() {
  // Start Serial monitor
  Serial.begin(9600);
  Serial.println("Connecting to Wifi:");
  
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup server pages
  server.on("/", handleRoot);

  server.on("/another", handleAnother);

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");

}

void loop() {
  // Use this loop to handle clients
  server.handleClient();
}

// Handlers

void handleRoot(){
  server.send(200, "text/html", "<h1>Hello World</h1>");
}

void handleAnother(){
  server.send(200, "text/html", "<h1>Another World</h1>");
}

void handleNotFound(){
  server.send(404, "text/html", "<h1>Page Not Found</h1>");
}