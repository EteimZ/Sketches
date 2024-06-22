/*
  Blink program for esp32 dev boards which have their builtin LED on pin 2
*/

#define LED_BUILTIN 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
