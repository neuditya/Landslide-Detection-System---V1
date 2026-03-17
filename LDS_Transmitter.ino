#include <esp_now.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include "Wire.h"
#include "MPU6050.h"

// --- CONFIGURATION ---
#define WIFI_SSID "TEST WIFI"
#define WIFI_PASSWORD "SECURE@LANDSLIDE"
#define API_KEY "AIzaSyB2YCc69pcEUrqcUUJqkWqqnzrZiJ-g####"//replace with your API key
#define DATABASE_URL "https://lds--0-de####-rtdb.firebaseio.com"//replace with your database

// REPLACE WITH YOUR RECEIVER MAC ADDRESS
uint8_t broadcastAddress[] = {0x24, 0x6F, 0x28, 0xAE, 0xD5, 0x84}; 

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
MPU6050 mpu;

typedef struct struct_message {
  byte sendX;
  byte sendY;
  byte sendZ;
  byte sendMoisture;
} struct_message;

struct_message myData;
esp_now_peer_info_t peerInfo;
unsigned long lastFirebaseUpdate = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }

  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(&config, &auth);

  if (esp_now_init() != ESP_OK) return;
  
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  esp_now_add_peer(&peerInfo);
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6
