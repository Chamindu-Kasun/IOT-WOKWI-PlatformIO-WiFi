#include <Arduino.h>
#include <WiFi.h>

#define ssid "Wokwi-GUEST"
#define password ""

#define LEDPIN 2

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");

  // Blink the LED while connecting
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected");
  Serial.println(WiFi.status());
  Serial.println(WiFi.localIP());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());

  // Turn off the LED after successful connection
  digitalWrite(LEDPIN, HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(LEDPIN, OUTPUT);
  initWiFi();
}

void loop() {
  // put your main code here, to run repeatedly:
}