/**
 * BluetoothControl.ino
 * ─────────────────────────────────────────────────────────────────────
 * Example: Control robot via Serial / Bluetooth (HC-05 / HC-06)
 * Library: BoticShieldV1 v1.0.0
 * Author : Raunak Choudhary
 * ─────────────────────────────────────────────────────────────────────
 * Commands (send via Serial Monitor or BT app):
 *   F  → Forward
 *   B  → Backward
 *   L  → Left
 *   R  → Right
 *   S  → Stop
 *   +  → Speed up   (+20)
 *   -  → Speed down (-20)
 * ─────────────────────────────────────────────────────────────────────
 */

#include <BoticShieldV1.h>

BoticShieldV1 robot;

uint8_t currentSpeed = 200;

void setup() {
  Serial.begin(9600);
  robot.begin(currentSpeed);
  Serial.println(F("Botic Shield V1 — Bluetooth Control ready!"));
  Serial.println(F("Commands: F B L R S + -"));
}

void loop() {
  if (Serial.available()) {
    char cmd = (char)Serial.read();

    switch (cmd) {
      case 'F': case 'f':
        robot.forward();
        Serial.println(F("→ Forward"));
        break;

      case 'B': case 'b':
        robot.backward();
        Serial.println(F("← Backward"));
        break;

      case 'L': case 'l':
        robot.left();
        Serial.println(F("↺ Left"));
        break;

      case 'R': case 'r':
        robot.right();
        Serial.println(F("↻ Right"));
        break;

      case 'S': case 's':
        robot.stop();
        Serial.println(F("■ Stop"));
        break;

      case '+':
        currentSpeed = min(255, currentSpeed + 20);
        robot.setSpeed(currentSpeed);
        Serial.print(F("Speed ↑ → "));
        Serial.println(currentSpeed);
        break;

      case '-':
        currentSpeed = max(0, currentSpeed - 20);
        robot.setSpeed(currentSpeed);
        Serial.print(F("Speed ↓ → "));
        Serial.println(currentSpeed);
        break;

      default:
        // Ignore unknown characters (newlines, spaces, etc.)
        break;
    }
  }
}
