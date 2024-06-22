/*
  Setup WebServer by connecting to a WiFi Network.
  This example returns JSON to the client.
*/

#include <WiFi.h>
#include <WebServer.h>
#include <Arduino_JSON.h>

// WiFi Network credentials
const char *ssid = ".............";
const char *password = ".........";

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

  // Setup API endpoints
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

  JSONVar responseObject;

  responseObject["msg"] = "Hello World";

  String responseString = JSON.stringify(responseObject);

  server.send(200, "application/json", responseString);
}

void handleAnother(){
  JSONVar responseObject;

  responseObject["msg"] = "Another World";

  String responseString = JSON.stringify(responseObject);

  server.send(200, "application/json", responseString);
}

void handleNotFound(){
  JSONVar responseObject;

  responseObject["msg"] = "Page not found.";

  String responseString = JSON.stringify(responseObject);
  server.send(404, "application/json", responseString);
}