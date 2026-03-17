The  Landslide Detection System is a decentralized IoT network designed for real-time monitoring of ground displacement. It utilizes a mesh network of ESP32 microcontrollers and MPU6050 accelerometers housed in spherical enclosures to detect movement. To ensure reliability, the system employs a three-sensor consensus algorithm that requires at least three unique nodes to confirm a threat before triggering an alarm. Once a landslide is confirmed, the receiver hub activates local countermeasures, such as high-decibel speakers and servo-controlled mechanisms, while logging sensor data to a Firebase Realtime Database for remote authority monitoring.


![Landslide-Detection-System---V1 Diagram](https://raw.githubusercontent.com/neuditya/Landslide-Detection-System---V1/refs/heads/main/LDS.png)




