// Heater Control System using DHT22 and ESP32
// Simulates heater ON/OFF based on temperature thresholds

#include <DHT.h>

#define DHTPIN 4           // GPIO pin where the DHT22 is connected
#define DHTTYPE DHT22      // Define the sensor type as DHT22

#define HEATER_PIN 5       // GPIO pin to simulate heater (e.g., LED or Relay)
#define BUZZER_PIN 2       // Optional: Buzzer or LED for visual feedback

// Thresholds (you can adjust these based on requirements)
#define TEMP_LOW 25.0
#define TEMP_HIGH 30.0
#define TEMP_OVERHEAT 40.0

DHT dht(DHTPIN, DHTTYPE);

// Define states
enum State {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

State currentState = IDLE;

void setup() {
  Serial.begin(115200);            // Start Serial Monitor
  dht.begin();                     // Initialize DHT sensor
  pinMode(HEATER_PIN, OUTPUT);    // Heater control pin
  pinMode(BUZZER_PIN, OUTPUT);    // Optional: Visual/buzzer feedback
  digitalWrite(HEATER_PIN, LOW);  // Start with heater OFF
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  float temp = dht.readTemperature();  // Read temperature in Celsius

  if (isnan(temp)) {
    Serial.println("[ERROR] Failed to read from DHT22!");
    delay(2000);
    return;
  }

  Serial.print("[INFO] Temp: ");
  Serial.println(temp);

  // State logic based on temperature
  if (temp < TEMP_LOW) {
    currentState = HEATING;
    digitalWrite(HEATER_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);  // Heater ON, feedback ON
  } else if (temp >= TEMP_LOW && temp < TEMP_HIGH) {
    currentState = STABILIZING;
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);   // Heater OFF, stabilizing
  } else if (temp >= TEMP_HIGH && temp < TEMP_OVERHEAT) {
    currentState = TARGET_REACHED;
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);   // Reached target, no heating
  } else if (temp >= TEMP_OVERHEAT) {
    currentState = OVERHEAT;
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(BUZZER_PIN, HIGH);  // Overheat warning
  } else {
    currentState = IDLE;
    digitalWrite(HEATER_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Print current state
  switch (currentState) {
    case IDLE:
      Serial.println("[STATE] IDLE");
      break;
    case HEATING:
      Serial.println("[STATE] HEATING");
      break;
    case STABILIZING:
      Serial.println("[STATE] STABILIZING");
      break;
    case TARGET_REACHED:
      Serial.println("[STATE] TARGET REACHED");
      break;
    case OVERHEAT:
      Serial.println("[STATE] OVERHEAT");
      break;
  }

  delay(2000);  // Wait 2 seconds before next read (DHT22 limitation)
}
