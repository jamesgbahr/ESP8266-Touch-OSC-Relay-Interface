#include <ESP8266WiFi.h>  // Include ESP8266-specific WiFi library
#include <WiFiUdp.h>
#include <OSCMessage.h>

// WiFi credentials
const char* ssid = "*******";
const char* password = "*******";

// OSC
WiFiUDP Udp;
const unsigned int localPort = 8000;  // Local port to listen for OSC packets
const char* faderAddress1 = "/1/fader1";
const char* faderAddress2 = "/1/fader2";
const char* faderAddress3 = "/1/fader3";
const char* faderAddress4 = "/1/fader4";

// Relay pins (update to valid GPIO pins for ESP8266)
#define RELAY_PIN_1 2  // GPIO5 (D1 on ESP8266 NodeMCU)
#define RELAY_PIN_2 4  // GPIO4 (D2 on ESP8266 NodeMCU)
#define RELAY_PIN_3 0  // GPIO0 (D3 on ESP8266 NodeMCU)
#define RELAY_PIN_4 5  // GPIO2 (D4 on ESP8266 NodeMCU)
#define LED_PIN     16 // GPIO16 (D0 on ESP8266 NodeMCU)

float faderValue1 = 0.0;
float faderValue2 = 0.0;
float faderValue3 = 0.0;
float faderValue4 = 0.0;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
  
  // Print the IP address
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start UDP
  Udp.begin(localPort);
  Serial.print("Listening on UDP port ");
  Serial.println(localPort);
  
  // Set relay pins and LED pin as output
  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(RELAY_PIN_4, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN_1, LOW);  // Ensure the relays are off initially
  digitalWrite(RELAY_PIN_2, LOW);
  digitalWrite(RELAY_PIN_3, LOW);
  digitalWrite(RELAY_PIN_4, LOW);
  digitalWrite(LED_PIN, LOW);      // Ensure the LED is off initially
}

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize > 0) {
    Serial.print("Received packet size: ");
    Serial.println(packetSize);

    OSCMessage msg;
    while (packetSize--) {
      msg.fill(Udp.read());
    }

    if (!msg.hasError()) {
      Serial.println("OSC message received:");
      msg.route(faderAddress1, updateFaderValue1);
      msg.route(faderAddress2, updateFaderValue2);
      msg.route(faderAddress3, updateFaderValue3);
      msg.route(faderAddress4, updateFaderValue4);
    } else {
      Serial.print("OSC message error: ");
      Serial.println(msg.getError());
    }
  }

  // Adjust relays based on fader values
  controlRelay(RELAY_PIN_1, faderValue1);
  controlRelay(RELAY_PIN_2, faderValue2);
  controlRelay(RELAY_PIN_3, faderValue3);
  controlRelay(RELAY_PIN_4, faderValue4);
}

void controlRelay(int relayPin, float faderValue) {
  if (faderValue >= 0.3 && faderValue < 0.4) {
    int duration = 300;
    Serial.print("Relay ON duration: ");
    Serial.println(duration);
    digitalWrite(relayPin, HIGH);
    delay(duration);
    digitalWrite(relayPin, LOW);
    delay(duration);
  } else if (faderValue >= 0.4 && faderValue < 0.5) {
    int duration = 200;
    Serial.print("Relay ON duration: ");
    Serial.println(duration);
    digitalWrite(relayPin, HIGH);
    delay(duration);
    digitalWrite(relayPin, LOW);
    delay(duration);
  } else if (faderValue >= 0.5 && faderValue < 0.6) {
    int duration = 100;
    Serial.print("Relay ON duration: ");
    Serial.println(duration);
    digitalWrite(relayPin, HIGH);
    delay(duration);
    digitalWrite(relayPin, LOW);
    delay(duration);
  } else if (faderValue >= 0.6 && faderValue < 0.7) {
    int duration = 50;
    Serial.print("Relay ON duration: ");
    Serial.println(duration);
    digitalWrite(relayPin, HIGH);
    delay(duration);
    digitalWrite(relayPin, LOW);
    delay(duration);
  } else if (faderValue >= 0.7 && faderValue < 0.8) {
    int duration = 40;
    Serial.print("Relay ON duration: ");
    Serial.println(duration);
    digitalWrite(relayPin, HIGH);
    delay(duration);
    digitalWrite(relayPin, LOW);
    delay(duration);
  } else if (faderValue >= 0.8) {
    int duration = 10;
    Serial.print("Relay ON duration: ");
    Serial.println(duration);
    digitalWrite(relayPin, HIGH);
    delay(duration);
    digitalWrite(relayPin, LOW);
    delay(duration);
  } else {
    digitalWrite(relayPin, LOW);  // Ensure the relay is off if the fader is below 0.3
    Serial.println("Fader below 0.3, relay OFF");
  }
}

void updateFaderValue1(OSCMessage &msg, int addrOffset) {
  faderValue1 = msg.getFloat(0);  // Get float value from OSC message
  Serial.print("Updated fader value 1: ");
  Serial.println(faderValue1);
}

void updateFaderValue2(OSCMessage &msg, int addrOffset) {
  faderValue2 = msg.getFloat(0);  // Get float value from OSC message
  Serial.print("Updated fader value 2: ");
  Serial.println(faderValue2);
}

void updateFaderValue3(OSCMessage &msg, int addrOffset) {
  faderValue3 = msg.getFloat(0);  // Get float value from OSC message
  Serial.print("Updated fader value 3: ");
  Serial.println(faderValue3);
}

void updateFaderValue4(OSCMessage &msg, int addrOffset) {
  faderValue4 = msg.getFloat(0);  // Get float value from OSC message
  Serial.print("Updated fader value 4: ");
  Serial.println(faderValue4);
}
