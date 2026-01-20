#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define DHTPIN 8   // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11 sensor type

DHT_Unified dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set LCD address to 0x27 for a 16x2 display

uint32_t delayMS;

void setup() {
    Serial.begin(9600);
    Serial.println(F("DHT11 Sensor Test"));
    dht.begin();
    lcd.init();  // Initialize the LCD
    lcd.backlight(); // Turn on the backlight
    
    // Retrieve sensor details
    sensor_t sensor;
    dht.temperature().getSensor(&sensor);
    Serial.println(F("------------------------------------"));
    Serial.println(F("Temperature Sensor"));
    Serial.print(F("Sensor Type: ")); Serial.println(sensor.name);
    Serial.print(F("Driver Ver:  ")); Serial.println(sensor.version);
    Serial.print(F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
    Serial.print(F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
    Serial.print(F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
    Serial.println(F("------------------------------------"));
    
    dht.humidity().getSensor(&sensor);
    Serial.println(F("Humidity Sensor"));
    Serial.print(F("Sensor Type: ")); Serial.println(sensor.name);
    Serial.print(F("Driver Ver:  ")); Serial.println(sensor.version);
    Serial.print(F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
    Serial.print(F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
    Serial.print(F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
    Serial.println(F("------------------------------------"));
    
    delayMS = sensor.min_delay / 1000;
}

void loop() {
    delay(delayMS);
    
    // Get temperature event
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    float temp = event.temperature;
    
    dht.humidity().getEvent(&event);
    float humidity = event.relative_humidity;
    
    if (isnan(temp) || isnan(humidity)) {
        Serial.println(F("Error reading from DHT sensor!"));
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sensor Error!!!!!");
    } else {
        Serial.print(F("Temperature: "));
        Serial.print(temp);
        Serial.println(F("°C"));
        
        Serial.print(F("Humidity: "));
        Serial.print(humidity);
        Serial.println(F("%"));
        
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temp);
        lcd.print(" C");
        
        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print("%");
    }
    delay(2000); // Update every 2 seconds
}