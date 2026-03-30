/**
 * SpeedTest.ino
 * ─────────────────────────────────────────────────────────────────────
 * Example: Ramp speed 0→255→0 while moving forward
 * Library: BoticShieldV1 v1.0.0
 * Author : Raunak Choudhary
 * ─────────────────────────────────────────────────────────────────────
 * Useful for: finding minimum start speed, tuning PWM range
 * ─────────────────────────────────────────────────────────────────────
 */

#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  Serial.begin(9600);
  robot.begin(0);  // Start at speed 0
  Serial.println(F("Botic Shield V1 — Speed Ramp Test"));
}

void loop() {
  Serial.println(F("↑ Ramping UP"));
  robot.forward();
  for (int spd = 0; spd <= 255; spd += 5) {
    robot.setSpeed(spd);
    Serial.print(F("Speed: ")); Serial.println(spd);
    delay(50);
  }

  delay(1000);

  Serial.println(F("↓ Ramping DOWN"));
  for (int spd = 255; spd >= 0; spd -= 5) {
    robot.setSpeed(spd);
    Serial.print(F("Speed: ")); Serial.println(spd);
    delay(50);
  }

  robot.stop();
  Serial.println(F("■ Done. Waiting 3s...\n"));
  delay(3000);
}
