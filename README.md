# arduino-multi-sensor-scanner
An Arduino Uno project that automatically scans multiple sensor types, detects their presence, and streams live diagnostic data over serial via a CP2102 USB-TTL adapter. Supports clap, obstacle, line tracking, touch, DHT11, HW-477, and HC-05 modules with modular testing code.

# Arduino Multi-Sensor Scanner

A modular Arduino Uno project that scans, detects, and reads multiple sensors one at a time, then streams diagnostic data through a CP2102 USB-TTL module. Designed for testing hardware setups in real time using PuTTY or any serial console.

---

## ✨ Features
- Auto-scans all connected sensors
- Serial output via CP2102 @ 9600 baud
- Supports:
  - CZN-15E 4-pin clap sensor  
  - MH-Flying-Fish 3-pin IR obstacle sensor  
  - DHT11 temperature/humidity  
  - Lafvin 5-pin 3-sensor line tracker  
  - HC-05 BLE module (AT response check)  
  - Touch sensor (3-pin type)  
  - HW-477 Breakout 3-pin IR sensor  
- Modular test functions for easy expansion
- Works with PuTTY, Arduino Serial Monitor, etc.

---

## 📦 Hardware Required
- Arduino Uno R3  
- CP2102 USB-to-TTL module  
- Any combination of supported sensors  
- Jumper wires  

---

## 📜 Required Libraries
- SoftwareSerial (built-in)
- DHT kxn 3.4.4 or later
- DHT sensor library 1.4.6 or later 
- (If needed, libraries provided in folder "Libraries" in this repo)

## 🔧 Wiring Overview
### CP2102 → Arduino
TXD → RX (D0)
|
RXD → TX (D1)
|
GND → GND
|
5V → 5V (if Arduino USB/External Power not used)

### Notes
- Disconnect pins **RXD** and **TXD** before uploading firmware.
- HC-05 uses SoftwareSerial: `D10 = TX`, `D11 = RX`.

---

## 📜 Installation
1. Open the project in Arduino IDE.  
2. Select **Board → Arduino Uno**.  
3. Upload with a normal USB cable (ensure pins RXD/TXD are disconnected).  
4. Reconnect CP2102 and open PuTTY/Any serial Monitor at:
   - **Specific COM Port**
   - **9600 baud**
   - 8N1, no flow control

---

## ▶️ Usage
After boot, the Arduino cycles through all sensor types, printing:

- Whether each sensor responds  
- Raw readings for analog/digital modules  
- AT response from HC-05 (if connected)

---

## 🧩 Expanding the Project
You can easily add:
- More sensors  
- Logging to SD card  
- BLE streaming  
- Interactive serial menu  

Contributions welcome.

---

## 📝 License
MIT License.

## 👨‍🚀 Author

Developed by AndreyWinz

Feel free to contribute, fork, or suggest new features!

## P.S.
I do these projects purely for fun, and I decided to upload them to GitHub to share with others. I am not asking or begging for a donation, but if you want to appreciate my work, feel free to donate whatever amount you want! You can also send your GitHub username in the "Note" section of the donation page, so I can give you a shout-out in the next repository. Stay tuned for more!

This is my Revolut Payment Link:
[Thank you so much!](https://revolut.me/andreygdl9)
