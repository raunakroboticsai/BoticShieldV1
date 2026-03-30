# BoticShieldV1 — Arduino Motor Library

> **Hardware:** L293D Dual H-Bridge + 74HC595 Shift Register  
> **Author:** Raunak Choudhary  
> **Version:** 1.0.0  

---

## 📦 Installation

1. Download `BoticShieldV1.zip`
2. Arduino IDE → **Sketch → Include Library → Add .ZIP Library…**
3. Select the downloaded zip → Done ✅

---

## 🔌 Default Pin Mapping

| Function          | Arduino Pin |
|-------------------|-------------|
| DS (Data)         | D11         |
| SRCLK (Clock)     | D13         |
| STCP (Latch)      | D10         |
| EN1 (PWM speed)   | D3          |
| EN2 (PWM speed)   | D6          |

> Pins match the Botic Shield V1 PCB. If you use a custom wiring, pass pins to the constructor.

---

## ⚡ Quick Start

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  robot.begin(200);   // speed: 0–255
}

void loop() {
  robot.forward();
  delay(2000);
  robot.stop();
  delay(1000);
}
```

---

## 📚 API Reference

| Method | Description |
|---|---|
| `begin(speed)` | Init pins, set speed, motors stopped. Call in `setup()`. |
| `setSpeed(0–255)` | Change speed anytime |
| `getSpeed()` | Returns current speed |
| `forward()` | All 4 wheels forward |
| `backward()` | All 4 wheels backward |
| `left()` | Spin left in place |
| `right()` | Spin right in place |
| `stop()` | Cut all motor output |
| `moveFor(dir, ms)` | Move direction (`'F'/'B'/'L'/'R'`) for `ms` milliseconds, then auto-stop |
| `sendRaw(byte)` | Send raw 8-bit pattern to shift register (advanced) |

---

## 🔬 74HC595 Bit Map

```
Bit 7 (Q7) → IN4   Motor 2 B
Bit 6 (Q6) → IN3   Motor 2 A
Bit 5 (Q5) → IN2   Motor 1 B
Bit 4 (Q4) → IN1   Motor 1 A
Bit 3 (Q3) → IN8   Motor 4 B
Bit 2 (Q2) → IN7   Motor 4 A
Bit 1 (Q1) → IN6   Motor 3 B
Bit 0 (Q0) → IN5   Motor 3 A
```

Each motor pair: `10` = forward · `01` = backward · `00` = coast/stop

---

## 📁 Examples

| Sketch | Description |
|---|---|
| `BasicControl` | Simple move sequence |
| `BluetoothControl` | HC-05/HC-06 Serial commands |
| `SpeedTest` | PWM ramp 0 → 255 → 0 |

---

## 📜 License

MIT License — free to use, modify, and distribute.
