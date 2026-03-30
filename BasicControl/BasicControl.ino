/**
 * BasicControl.ino
 * ─────────────────────────────────────────────────────────────────────
 * Example: Simple move sequence for Botic Shield V1
 * Library: BoticShieldV1 v1.0.0
 * Author : Raunak Choudhary
 * ─────────────────────────────────────────────────────────────────────
 * Wiring  (default – no changes needed if using Botic Shield V1):
 *   DS    → D11    SRCLK → D13    STCP  → D10
 *   EN1   → D3     EN2   → D6
 * ─────────────────────────────────────────────────────────────────────
 */

#include <BoticShieldV1.h>

// Create robot object with default pins
BoticShieldV1 robot;

void setup() {
  Serial.begin(9600);
  robot.begin(200);   // Speed: 0 – 255
  Serial.println(F("Botic Shield V1 — BasicControl ready!"));
}

void loop() {

  Serial.println(F("→ Forward 2 s"));
  robot.forward();
  delay(2000);

  Serial.println(F("■ Stop 0.5 s"));
  robot.stop();
  delay(500);

  Serial.println(F("← Backward 2 s"));
  robot.backward();
  delay(2000);

  Serial.println(F("■ Stop 0.5 s"));
  robot.stop();
  delay(500);

  Serial.println(F("↺ Left 1 s"));
  robot.left();
  delay(1000);

  Serial.println(F("↻ Right 1 s"));
  robot.right();
  delay(1000);

  Serial.println(F("■ Stop 2 s\n"));
  robot.stop();
  delay(2000);
}
