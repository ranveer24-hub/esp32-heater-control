# esp32-heater-control
ESP32-based heater control system using DHT22 sensor. Automatically manages heating and safety states with visual feedback and temperature monitoring. Built for Wokwi simulation.
# Heater Control System using ESP32 and DHT22

A simulated heater control system using ESP32 and DHT22 sensor that adjusts a heater (LED/Relay) based on temperature readings. Visual feedback is provided using a buzzer or indicator LED.

## 🔧 Features

- Turns heater ON below 25°C
- Stabilizing state between 25°C – 30°C
- Heater OFF once target temperature is reached
- Overheat warning above 40°C
- Serial monitor feedback for debugging

## 📐 Circuit Overview

- **DHT22 Sensor** → GPIO 4 (with 10kΩ pull-up resistor)
- **Heater (LED/Relay)** → GPIO 5
- **Buzzer/Indicator** → GPIO 2
- **Power Supply** → 3.3V and GND

## 🚀 How to Simulate in Wokwi

1. Open the project: [Wokwi Simulation Link](#)
2. Click on the DHT22 component.
3. Change the temperature value.
4. View output on Serial Monitor and LED/Buzzer behavior.

## 📂 File Contents

| File                  | Description                          |
|-----------------------|--------------------------------------|
| `HeaterControl.ino`   | Arduino sketch for ESP32             |
| `schematic.png`       | Circuit diagram                      |
| `README.md`           | This file                            |
| `Design_Document.pdf` | Project explanation and thresholds   |
| `wokwi-diagram.json`  | (Optional) Wokwi project file        |

## 💡 Bonus (Planned)

- BLE Advertising of heating state
- FreeRTOS-based task handling
- Web dashboard for remote monitoring

---

## 🛠 Tools Used

- [ESP32 Dev Module](https://www.espressif.com/en/products/socs/esp32)
- [Wokwi Simulator](https://wokwi.com/projects/438153436114816001)


## 📬 Contact

Ranveer Singh Shekhawat  
[shekhawatranveersingh828@gmail.com]

