#include <esp_now.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <set>

Servo myServo; 
const int servoPin = 25;
const int speakerPin = 27;

// REQUIRES 3 UNIQUE SENSORS TO TRIGGER
const int TRIGGER_THRESHOLD = 3; 
std::set<String> triggeredSensors;

typedef struct struct_message {
  byte sendX;
  byte sendY;
  byte sendZ;
  byte sendMoisture;
} struct_message;

struct_message incomingData;

void OnDataRecv(const esp_now_recv_info *info, const uint8_t *data, int len) {
  memcpy(&incomingData, data, sizeof(incomingData));

  char macStr[18];
  snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X", 
           info->src_addr[0], info->src_addr[1], info->src_addr[2], 
           info->src_addr[3], info->src_addr[4], info->src_addr[5]);
  String sensorID = String(macStr);

  if (incomingData.sendX > 100 || incomingData.sendY > 100) {
    triggeredSensors.insert(sensorID);
  } else {
    triggeredSensors.erase(sensorID);
  }

  if (triggeredSensors.size() >= TRIGGER_THRESHOLD) {
    myServo.write(90);
    digitalWrite(speakerPin, HIGH);
    tone(speakerPin, 1500); 
  } else {
    myServo.write(0);
    digitalWrite(speakerPin, LOW);
    noTone(speakerPin);
  }
}

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
  pinMode(speakerPin, OUTPUT);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() == ESP_OK) {
    esp_now_register_recv_cb(OnDataRecv);
  }
}

void loop() {}