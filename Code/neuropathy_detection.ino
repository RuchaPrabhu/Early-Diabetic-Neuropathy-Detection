#include <Arduino.h>

// -------- Pin Configuration --------
const int SENSOR1_PIN = 26;   // Velostat sensor 1
const int SENSOR2_PIN = 27;   // Velostat sensor 2
const int ERM_PIN      = 2;  // ERM motor PWM pin

// -------- ADC & PWM Configuration --------
const int ADC_MAX = 4095;
const int PWM_CHANNEL = 0;
const int PWM_FREQ = 2000;     // Hz
const int PWM_RES = 8;         // 8-bit (0–255)

// -------- Variables --------
float adc1 = 0, adc2 = 0, ratio = 0;
int duty = 0;
bool motorOn = true;
bool testDone = false;

// -------- Helper Function: Read Sensor Average --------
float readAveragedADC(int pin, int samples = 10) {
  long total = 0;
  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delayMicroseconds(200);
  }
  return (float)total / samples;
}

// -------- Calculate Risk Factor --------
String riskLevel(float ratio, int duty) {
  float risk = (0.5 * ratio) + (0.5 * (duty / 255.0));

  if (risk < 0.85) return "LOW";
  else if (0.85<risk < 1.1) return "MEDIUM";
  else return "HIGH";
}

// -------- Setup --------
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\n========== Neuropathy Detection System ==========");
  Serial.println("Press ANY key in Serial Monitor when vibration is felt.");
  Serial.println("--------------------------------------------------");
  Serial.println("S1_ADC\tS2_ADC\tRatio\tERM_Duty\tRisk");

  // Pull-ups ensure open ADC pins read ~4095 when nothing connected
  pinMode(SENSOR1_PIN, INPUT_PULLUP);
  pinMode(SENSOR2_PIN, INPUT_PULLUP);

  analogReadResolution(12);
  analogSetPinAttenuation(SENSOR1_PIN, ADC_11db);
  analogSetPinAttenuation(SENSOR2_PIN, ADC_11db);

  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(ERM_PIN, PWM_CHANNEL);
}

// -------- Main Loop --------
void loop() {
  if (testDone) return;  // Stop after result shown

  // --- Read sensor ADCs ---
  adc1 = readAveragedADC(SENSOR1_PIN);
  adc2 = readAveragedADC(SENSOR2_PIN);
  if (adc2 > 1) ratio = adc1 / adc2;
  else ratio = 0;

  // --- Gradual PWM increase (+5 every ~700ms) ---
  if (motorOn) {
    ledcWrite(PWM_CHANNEL, duty);
    duty += 5;
    if (duty > 255) duty = 255;
  }

  // --- Check for keyboard press (virtual button) ---
  if (Serial.available() > 0) {
    Serial.read();  // clear buffer
    motorOn = false;
    testDone = true;
    ledcWrite(PWM_CHANNEL, 0);

    String level = riskLevel(ratio, duty);

    Serial.println("\n--- Patient Response Detected (Keyboard Input) ---");
    Serial.printf("Final Sensor1 ADC: %.0f\n", adc1);
    Serial.printf("Final Sensor2 ADC: %.0f\n", adc2);
    Serial.printf("Sensor Ratio (S1/S2): %.3f\n", ratio);
    Serial.printf("ERM Duty (PWM when felt): %d\n", duty);
    Serial.printf("=> RISK LEVEL: %s\n", level.c_str());
    Serial.println("---------------------------------\n");
  }

  // --- Live display (before button press) ---
  if (!testDone) {
    Serial.printf("%4.0f\t%4.0f\t%.3f\t%3d\n", adc1, adc2, ratio, duty);
  }

  delay(700);  // slower increase for smoother ramp
}
