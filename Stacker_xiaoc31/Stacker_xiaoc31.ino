// XIAO ESP32-C3
// 8-channel relay module
// 5 solenoid valve outputs

// Relay pin assignments
const int MAIN_VALVE = D6;
const int FARM1_VALVE = D5;
const int FARM2_VALVE = D10;
const int FARM3_VALVE = D8;
const int FARM4_VALVE = D7;

// Most relay modules are active-LOW.
// Change to false if your relay module is active-HIGH.
const bool RELAY_ACTIVE_LOW = true;

const int relayPins[] = {
  MAIN_VALVE,
  FARM1_VALVE,
  FARM2_VALVE,
  FARM3_VALVE,
  FARM4_VALVE
};

const int RELAY_COUNT = 5;

void setRelay(int pin, bool on) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(pin, on ? LOW : HIGH);
  } else {
    digitalWrite(pin, on ? HIGH : LOW);
  }
}

void allRelaysOff() {
  for (int i = 0; i < RELAY_COUNT; i++) {
    setRelay(relayPins[i], false);
  }
}

void setup() {
  Serial.begin(115200);

  // Set all outputs OFF.
  for (int i = 0; i < RELAY_COUNT; i++) {
    digitalWrite(
      relayPins[i],
      RELAY_ACTIVE_LOW ? HIGH : LOW
    );
    pinMode(relayPins[i], OUTPUT);
  }

  allRelaysOff();

  Serial.println("Solenoid relay test started.");
  Serial.println("All valves should be OFF initially.");
}

void loop() {
  // Test main valve
  Serial.println("Main valve relay ON");
  setRelay(MAIN_VALVE, true);
  delay(2000);
  setRelay(MAIN_VALVE, false);
  delay(1000);

  // Test Farm 1
  Serial.println("Farm 1 relay ON");
  setRelay(MAIN_VALVE, true);
  delay(500);
  setRelay(FARM1_VALVE, true);
  delay(2000);
  setRelay(FARM1_VALVE, false);
  setRelay(MAIN_VALVE, false);
  delay(1000);

  // Test Farm 2
  Serial.println("Farm 2 relay ON");
  setRelay(MAIN_VALVE, true);
  delay(500);
  setRelay(FARM2_VALVE, true);
  delay(2000);
  setRelay(FARM2_VALVE, false);
  setRelay(MAIN_VALVE, false);
  delay(1000);

  // Test Farm 3
  Serial.println("Farm 3 relay ON");
  setRelay(MAIN_VALVE, true);
  delay(500);
  setRelay(FARM3_VALVE, true);
  delay(2000);
  setRelay(FARM3_VALVE, false);
  setRelay(MAIN_VALVE, false);
  delay(1000);

  // Test Farm 4
  Serial.println("Farm 4 relay ON");
  setRelay(MAIN_VALVE, true);
  delay(500);
  setRelay(FARM4_VALVE, true);
  delay(2000);
  setRelay(FARM4_VALVE, false);
  setRelay(MAIN_VALVE, false);
  delay(2000);
}