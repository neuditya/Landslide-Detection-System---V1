The  Landslide Detection System is a decentralized IoT network designed for real-time monitoring of ground displacement. It utilizes a mesh network of ESP32 microcontrollers and MPU6050 accelerometers housed in spherical enclosures to detect movement. To ensure reliability, the system employs a three-sensor consensus algorithm that requires at least three unique nodes to confirm a threat before triggering an alarm. Once a landslide is confirmed, the receiver hub activates local countermeasures, such as high-decibel speakers and servo-controlled mechanisms, while logging sensor data to a Firebase Realtime Database for remote authority monitoring.

<table>
    <thead>
        <tr style="background-color: #f2f2f2;">
            <th style="padding: 12px; border: 1px solid #ddd; text-align: left;">Category</th>
            <th style="padding: 12px; border: 1px solid #ddd; text-align: left;">Component / Service</th>
            <th style="padding: 12px; border: 1px solid #ddd; text-align: left;">Role in System</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Microcontroller</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">ESP32</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Central Receiver (Sink) Node handling ESP-NOW communication and logic.</td>
        </tr>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Motion Sensor</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">MPU-6050 (MPU)</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Detects X, Y, and Z axis movement to identify tilt or vibrations.</td>
        </tr>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Environmental Sensor</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">Soil Moisture Sensor</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Measures moisture levels to assess landslide or environmental risk.</td>
        </tr>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Connectivity</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">ESP-NOW Protocol</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Wireless mesh-like communication for high-speed data transfer between nodes.</td>
        </tr>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Cloud Hosting</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">Firebase</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Real-time database used for hosting data and remote monitoring.</td>
        </tr>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Physical Actuator</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">Servo Motor (Pin 25)</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Mechanical response trigger (moves to 90 degrees on consensus).</td>
        </tr>
        <tr>
            <td style="padding: 12px; border: 1px solid #ddd;"><strong>Alarm System</strong></td>
            <td style="padding: 12px; border: 1px solid #ddd;">Piezo Speaker (Pin 27)</td>
            <td style="padding: 12px; border: 1px solid #ddd;">Audible alert system (1500Hz tone) when danger thresholds are met.</td>
        </tr>
    </tbody>
</table>

<br>

<div align="center">
    
</div>


![Landslide-Detection-System---V1 Diagram](https://raw.githubusercontent.com/neuditya/Landslide-Detection-System---V1/refs/heads/main/LDS.png)




