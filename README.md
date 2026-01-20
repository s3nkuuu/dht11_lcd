# DHT11 LCD Temperature & Humidity Monitor

## 📌 Description
This project uses a **DHT11 sensor** to measure temperature and humidity and displays the values on a **16x2 I2C LCD** using Arduino.

## 🧰 Components Used
- Arduino Uno / Nano
- DHT11 Temperature & Humidity Sensor
- 16x2 I2C LCD (0x27)
- Jumper wires
- Breadboard

## 🔌 Connections
| Component | Arduino Pin |
|---------|------------|
| DHT11 Data | D8 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| VCC | 5V |
| GND | GND |

## 📟 Output
- Displays **Temperature (°C)** on LCD
- Displays **Humidity (%)** on LCD
- Serial Monitor shows sensor details

## 📚 Required Libraries
- Adafruit Unified Sensor
- DHT Sensor Library
- LiquidCrystal_I2C
- Wire

## 🚀 How to Use
1. Install required libraries in Arduino IDE
2. Connect the components
3. Upload `dht11_lcd.ino`
4. Open Serial Monitor (9600 baud)
