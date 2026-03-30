<div align="center">

<h1> BoticShieldV1</h1>

<img width="2000" height="2000" alt="boticssheildfrontpng" src="https://github.com/user-attachments/assets/d2b2c251-fde5-41b1-b1aa-b70df21e2a60" />

<img width="2000" height="2000" alt="Boticsdsheildoublepng" src="https://github.com/user-attachments/assets/4b11ddf3-84a7-47ef-9954-c6b2d3eb4633" />

<h3>Official Arduino Library for the Botic Shield V1</h3>

<p><em>A powerful yet beginner-friendly library to control 4-wheel differential-drive robots<br>
using a custom-designed Arduino shield built with the L293D motor driver and 74HC595 shift register.</em></p>

<br>

[![Version](https://img.shields.io/badge/Version-1.0.0-blue?style=for-the-badge&logo=github)](https://github.com/raunakchoudhary/BoticShieldV1/releases)
[![Arduino](https://img.shields.io/badge/Arduino-Compatible-00979D?style=for-the-badge&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge)](LICENSE)
[![Platform](https://img.shields.io/badge/Platform-UNO%20%7C%20Nano%20%7C%20Mega-orange?style=for-the-badge)]()
[![Stars](https://img.shields.io/github/stars/raunakchoudhary/BoticShieldV1?style=for-the-badge&color=yellow)]()

<br>

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() { robot.begin(); }
void loop()  { robot.forward(); }
```

**That's all it takes. Your robot is moving.** 🚀

<br>

[📦 Install Now](#-installation) &nbsp;·&nbsp;
[⚡ Quick Start](#-quick-start) &nbsp;·&nbsp;
[📚 Full API](#-complete-api-reference) &nbsp;·&nbsp;
[🔧 Hardware Docs](#-hardware-deep-dive) &nbsp;·&nbsp;
[💡 Examples](#-examples-in-detail) &nbsp;·&nbsp;
[🛠️ Troubleshoot](#%EF%B8%8F-troubleshooting-guide)

</div>


## 🔷 What is Botic Shield V1?

**Botic Shield V1** is a custom-designed Arduino shield created specifically for building 4-wheel differential-drive robots. It is a plug-on board that sits directly on top of an Arduino UNO or Nano and gives you complete control over 4 DC motors using a minimal number of Arduino I/O pins.

This library (**BoticShieldV1**) is the official software companion for the shield. It abstracts away all the low-level hardware communication and gives you clean, readable function calls like `robot.forward()`, `robot.left()`, and `robot.setSpeed(200)`.

---

## 🔷 Features

- 🔹 **4 DC Motor Control** using dual L293DNE motor driver ICs — independent control of all four drive wheels simultaneously

- 🔹 **Efficient Pin Usage** with 74HC595 shift register — control 4 motors using only 3 Arduino I/O pins, leaving the rest free for sensors

- 🔹 **Complete Robot Movement** — full directional support with simple, readable function calls:
  - `robot.forward()`
  - `robot.backward()`
  - `robot.left()`
  - `robot.right()`
  - `robot.stop()`

- 🔹 **Built-in PWM Speed Control** — smooth and adjustable motion using hardware PWM, set any speed from 0 to 255 with `robot.setSpeed()`

- 🔹 **3 Ultrasonic Sensor Ports** — dedicated headers for HC-SR04 or compatible sensors, ideal for obstacle detection and distance measurement

- 🔹 **3 Servo Motor Ports** — plug in standard servo motors for scanning turrets, pan-tilt mounts, or gripper mechanisms

- 🔹 **2 IR Sensor Inputs** — onboard headers for infrared line-following sensors and proximity/object detection

- 🔹 **I2C Interface** (SDA – A4, SCL – A5) — for LCD displays, OLED modules, and any other I2C peripherals

- 🔹 **Clean Header-based Layout** — all connectors clearly labeled, no soldering required, snap modules directly into the header pins

- 🔹 **External Motor Power Supply Support** — dedicated motor supply input keeps drive current separate from Arduino logic, no brownouts during motor stall

- 🔹 **Power Protection & Decoupling** — onboard diode for reverse-polarity protection and bypass capacitors for clean, stable operation

- 🔹 **Fully Compatible with the BoticShieldV1 Arduino Library** — designed to work seamlessly with this library out of the box

- 🔹 **Beginner-friendly yet Powerful** — simple enough for first-time builders, capable enough for advanced competition robots and autonomous systems

---

## 🔷 Board Compatibility

| Board | Supported |
|-------|-----------|
| Arduino UNO R3 | ✅ |
| Arduino UNO R4 | ✅ |

---

## 🔷 Installation

1. Download this repository as a `.zip` file
2. Open Arduino IDE
3. Go to **Sketch → Include Library → Add .ZIP Library**
4. Select the downloaded `.zip` file
5. Done! The library is ready to use.

---

## 🔷 Quick Start

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  robot.begin();
  robot.setSpeed(200);   // Speed range: 0 to 255
}

void loop() {
  robot.forward();       // Move forward
  delay(1000);

  robot.left();          // Turn left
  delay(500);

  robot.backward();      // Move backward
  delay(1000);

  robot.right();         // Turn right
  delay(500);

  robot.stop();          // Stop the robot
  delay(500);
}
```

---

## 🔷 Pin Map

| Function | Arduino Pin | Component |
|----------|-------------|-----------|
| Motor data | D4 | 74HC595 DS |
| Shift clock | D7 | 74HC595 SHCP |
| Latch clock | D8 | 74HC595 STCP |
| Motor A speed | D5 (PWM) | L293DNE EN1 |
| Motor B speed | D6 (PWM) | L293DNE EN2 |
| I2C SDA | A4 | I2C bus |
| I2C SCL | A5 | I2C bus |

---

## 🔷 API Reference

| Function | Description |
|----------|-------------|
| `robot.begin()` | Initialize the shield |
| `robot.setSpeed(speed)` | Set motor speed (0–255) |
| `robot.forward()` | Move robot forward |
| `robot.backward()` | Move robot backward |
| `robot.left()` | Turn robot left |
| `robot.right()` | Turn robot right |
| `robot.stop()` | Stop all motors |

---

---

## 💡 Why This Shield Exists

### The Problem with Standard L293D Wiring

If you try to control 4 DC motors with standard L293D H-bridge ICs, you need:

- **8 direction control pins** (2 per motor × 4 motors = 8 pins)
- **2 PWM speed pins** (one per L293D enable)
- **Total: 10 Arduino pins** just for motors

On an Arduino UNO, this leaves almost no pins for anything else — no ultrasonic sensor, no Bluetooth module, no IR remote receiver, nothing.

### The Botic Shield V1 Solution

By inserting a **74HC595 shift register** between the Arduino and the L293D ICs, all 8 direction signals are compressed into just **3 serial communication pins**. This brings the total pin count way down:

```
❌  Standard wiring:   8 direction + 2 PWM  =  10 pins consumed
✅  Botic Shield V1:   3 serial   + 2 PWM  =   5 pins consumed
                                               ───────────────
                                               5 FREE pins for sensors, modules, etc.
```

**This is the core innovation of the Botic Shield V1 design.**

---

##  Hardware Deep Dive

### Components Used

| Component | Quantity | Role |
|---|:---:|---|
| **L293D** Quadruple Half-H Driver | 2 | Controls 2 motors each (4 total), provides H-bridge for bidirectional drive |
| **74HC595** 8-Bit Shift Register | 1 | Converts 3-wire serial input to 8 parallel output pins (IN1–IN8 of L293Ds) |
| DC Motor (generic, 3V–12V) | 4 | The actual wheels of the robot |
| Arduino UNO / Nano | 1 | Brain — runs your sketch and this library |
| Motor Power Supply | 1 | Separate power for motors (6V–12V recommended) |

---

### L293D — The Motor Driver

The **L293D** is a quadruple half-H bridge driver IC. Each L293D can drive **2 bidirectional DC motors**. With 2 L293D ICs on the shield, we get **4 motor channels**.

**How it drives a motor:**
Each motor needs two control pins (IN_A and IN_B). By setting these HIGH and LOW in different combinations, the motor spins forward, backward, or stops:

```
IN_A = LOW,  IN_B = HIGH  →  Motor spins FORWARD
IN_A = HIGH, IN_B = LOW   →  Motor spins BACKWARD
IN_A = LOW,  IN_B = LOW   →  Motor COASTS (free spin, no brake)
IN_A = HIGH, IN_B = HIGH  →  Motor BRAKES (not used in this library)
```

**Enable pins (EN1, EN2):**
Each L293D has an enable pin. This is where **PWM speed control** happens. By sending an `analogWrite()` value (0–255) to the enable pin, you control how much power goes to the motors — effectively controlling speed.

- `analogWrite(EN1, 255)` → Full speed on Motor 1 & 2
- `analogWrite(EN1, 128)` → Half speed on Motor 1 & 2
- `analogWrite(EN1, 0)`   → Motors 1 & 2 off

**L293D Key Specs:**
- Supply voltage range: 4.5V – 36V
- Output current per channel: 600mA continuous
- Peak output current: 1.2A per channel
- Built-in ESD protection and flyback diodes
- Can drive inductive loads (motors, solenoids, relays)

---

### 74HC595 — The Pin Saver

The **74HC595** is an 8-bit serial-in, parallel-out shift register. It receives data serially (one bit at a time) from the Arduino over 3 wires, and then presents all 8 bits simultaneously on its output pins (Q0–Q7).

**The 3 control signals:**

| Pin Name | Arduino Pin | Function |
|---|:---:|---|
| **DS** (Data)  | D11 | The actual data — bits sent one at a time |
| **SHCP** (Clock) | D13 | Each rising edge shifts in one data bit |
| **STCP** (Latch) | D10 | Rising edge copies shift register to output pins |

**How shiftOut() works step by step:**
1. Arduino pulls **STCP (Latch) LOW** — output pins are locked
2. Arduino sends 8 bits one-by-one on **DS (Data)**, toggling **SHCP (Clock)** for each bit
3. Arduino pulls **STCP (Latch) HIGH** — all 8 bits appear on Q0–Q7 simultaneously
4. Q0–Q7 now hold the motor direction pattern — and stay there until next update

This entire process happens in microseconds and uses the Arduino's built-in `shiftOut()` function.

**74HC595 Key Specs:**
- Supply voltage: 2V – 6V (5V Arduino compatible)
- Output current per pin: 35mA source, 70mA sink
- High-speed CMOS logic
- Cascadable — multiple 595s can be chained for more outputs

---

### Pin Mapping Table

| Signal | Arduino Pin | IC | IC Pin | Description |
|---|:---:|---|:---:|---|
| DS — Data | **D11** | 74HC595 | Pin 14 | Serial data sent bit-by-bit |
| SHCP — Clock | **D13** | 74HC595 | Pin 11 | Clocks each data bit into shift register |
| STCP — Latch | **D10** | 74HC595 | Pin 12 | Transfers shifted data to output pins |
| EN1 — Enable 1 | **D3** *(PWM)* | L293D #1 | Pin 1, 9 | Speed control for Motor 1 & Motor 2 |
| EN2 — Enable 2 | **D6** *(PWM)* | L293D #2 | Pin 1, 9 | Speed control for Motor 3 & Motor 4 |

> ✅ **All connections are pre-soldered on the Botic Shield V1 PCB.** No jumper wires needed when using the actual shield.

> ⚠️ **D3 and D6 must be PWM-capable pins.** On Arduino UNO/Nano, PWM pins are: D3, D5, D6, D9, D10, D11. If you're building your own custom wiring (not using the shield PCB), make sure EN1 and EN2 connect to PWM pins.

---

### Full Circuit Architecture

```
  ARDUINO UNO / NANO
  ┌─────────────────────────────────────────────────────────┐
  │                                                         │
  │  D11 ──────────────────► DS   (Pin 14)  ┌───────────┐  │
  │  D13 ──────────────────► SHCP (Pin 11)  │           │  │
  │  D10 ──────────────────► STCP (Pin 12)  │  74HC595  │  │
  │                          OE   (Pin 13) ─┤  8-bit    │  │
  │                          GND  (Pin  8) ─┤  Shift    │  │
  │                          VCC  (Pin 16) ─┤  Register │  │
  │                          MR   (Pin 10) ─┤           │  │
  │                                         └───┬───────┘  │
  │   D3 (PWM) ────────────► EN1,EN2 (L293D #1)│           │
  │   D6 (PWM) ────────────► EN1,EN2 (L293D #2)│           │
  │                                             │           │
  └─────────────────────────────────────────────────────────┘
                                                │
              ┌─────────────────────────────────┘
              │  74HC595 Outputs (Q0–Q7)
              │
              ├── Q4 → IN1 ─┐
              ├── Q5 → IN2 ─┤ L293D #1 ──► Motor 1 (Front Left)
              ├── Q6 → IN3 ─┤
              ├── Q7 → IN4 ─┘ L293D #1 ──► Motor 2 (Front Right)
              │
              ├── Q0 → IN5 ─┐
              ├── Q1 → IN6 ─┤ L293D #2 ──► Motor 3 (Rear Left)
              ├── Q2 → IN7 ─┤
              └── Q3 → IN8 ─┘ L293D #2 ──► Motor 4 (Rear Right)
```

---

### Robot Wheel Layout

```
                        FRONT OF ROBOT
                    ┌───────────────────┐
                    │                   │
        ┌───────────┤  M1          M2   ├───────────┐
        │  WHEEL 1  │  ●            ●   │  WHEEL 2  │
        │ Front Left│                   │Front Right│
        └───────────┤                   ├───────────┘
                    │                   │
        ┌───────────┤  M3          M4   ├───────────┐
        │  WHEEL 3  │  ●            ●   │  WHEEL 4  │
        │ Rear Left │                   │ Rear Right│
        └───────────┤                   ├───────────┘
                    │                   │
                    └───────────────────┘
                        REAR OF ROBOT

    M1 = Motor 1 = Front Left     M2 = Motor 2 = Front Right
    M3 = Motor 3 = Rear  Left     M4 = Motor 4 = Rear  Right
```

---

## 📦 Installation

### ✅ Method 1 — Add ZIP Library (Easiest for Beginners)

**Step 1:** Go to the [Releases page](https://github.com/raunakchoudhary/BoticShieldV1/releases) and download `BoticShieldV1.zip`

**Step 2:** Open Arduino IDE

**Step 3:** Go to the menu:
```
Sketch → Include Library → Add .ZIP Library...
```

**Step 4:** Navigate to where you downloaded the ZIP file, select it, and click **Open**

**Step 5:** Restart Arduino IDE

**Step 6:** Verify it worked:
```
File → Examples → BoticShieldV1 → BasicControl
```
If you can see the examples, installation was successful ✅

---

### ✅ Method 2 — Manual Folder Install

**Find your Arduino libraries folder:**

| OS | Path |
|---|---|
| Windows | `C:\Users\YourName\Documents\Arduino\libraries\` |
| macOS | `~/Documents/Arduino/libraries/` |
| Linux | `~/Arduino/libraries/` |

**Steps:**
1. Download and extract `BoticShieldV1.zip`
2. Move the extracted `BoticShieldV1` folder into your `libraries` folder
3. The final path should look like: `.../libraries/BoticShieldV1/src/BoticShieldV1.h`
4. Restart Arduino IDE

---

### ✅ Method 3 — Git Clone

```bash
# Navigate to your Arduino libraries folder first, then:
git clone https://github.com/raunakchoudhary/BoticShieldV1.git

# Restart Arduino IDE after cloning
```

---

## ⚡ Quick Start

### The Absolute Minimum

```cpp
#include <BoticShieldV1.h>      // Step 1: Include the library

BoticShieldV1 robot;             // Step 2: Create robot object (default pins)

void setup() {
  robot.begin();                 // Step 3: Initialize (ALWAYS call this in setup!)
}

void loop() {
  robot.forward();               // Step 4: GO!
}
```

That's the absolute minimum. Three lines in `setup()` and one movement command. Done.

---

### Your First Test Sequence

This sketch makes the robot do a complete movement test — good for verifying all 4 motors work correctly when you first get the shield:

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  Serial.begin(9600);
  robot.begin(180);   // Initialize at speed 180 (moderate)

  Serial.println("Botic Shield V1 - Motor Test Starting!");
  delay(2000);        // 2 second pause before starting
}

void loop() {

  // --- Test Forward ---
  Serial.println("Testing: FORWARD");
  robot.forward();
  delay(2000);
  robot.stop();
  delay(800);

  // --- Test Backward ---
  Serial.println("Testing: BACKWARD");
  robot.backward();
  delay(2000);
  robot.stop();
  delay(800);

  // --- Test Left Turn ---
  Serial.println("Testing: LEFT");
  robot.left();
  delay(1000);
  robot.stop();
  delay(800);

  // --- Test Right Turn ---
  Serial.println("Testing: RIGHT");
  robot.right();
  delay(1000);
  robot.stop();
  delay(800);

  // --- Test Speed Change ---
  Serial.println("Testing: SPEED RAMP");
  robot.setSpeed(80);
  robot.forward();
  delay(1500);
  robot.setSpeed(200);
  delay(1500);
  robot.stop();

  Serial.println("Test cycle complete! Waiting 3 seconds...\n");
  delay(3000);
}
```

---

### Using moveFor() for Cleaner Code

Instead of writing `robot.forward(); delay(2000); robot.stop();` every time, use `moveFor()`:

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  robot.begin(200);

  // These are equivalent:

  // Method 1 — Manual
  robot.forward();
  delay(2000);
  robot.stop();

  // Method 2 — moveFor() (cleaner!)
  robot.moveFor('F', 2000);

  // A full maneuver sequence:
  robot.moveFor('F', 3000);   // Forward  3 seconds
  delay(300);
  robot.moveFor('L', 600);    // Turn left 600ms
  robot.moveFor('F', 2000);   // Forward  2 seconds
  delay(300);
  robot.moveFor('R', 600);    // Turn right 600ms
  robot.moveFor('B', 1000);   // Backward  1 second
}

void loop() {}
```

---

## 📚 Complete API Reference

### Constructor

```cpp
BoticShieldV1 robot;
// or with custom pins:
BoticShieldV1 robot(dataPin, clockPin, latchPin, en1Pin, en2Pin);
```

Creates a BoticShieldV1 object. When using the Botic Shield V1 PCB, call with no arguments — all default pin values match the PCB wiring.

**Parameters (all optional):**

| Parameter | Default | Description |
|---|:---:|---|
| `dataPin` | `11` | DS pin of 74HC595 — serial data |
| `clockPin` | `13` | SHCP pin of 74HC595 — shift clock |
| `latchPin` | `10` | STCP pin of 74HC595 — output latch |
| `en1Pin` | `3` | EN1 of L293D #1 — speed for Motor 1 & 2 (must be PWM) |
| `en2Pin` | `6` | EN2 of L293D #2 — speed for Motor 3 & 4 (must be PWM) |

**Examples:**

```cpp
BoticShieldV1 robot;               // Default Botic Shield V1 pins

BoticShieldV1 robot(7, 8, 9, 5, 6); // Custom wiring
```

---

### `begin(speed)`

```cpp
void begin(uint8_t speed = 200);
```

**This must be the first thing you call in `setup()`.** It does the following in order:
1. Sets all 5 pins as OUTPUT
2. Sends a STOP signal to the 74HC595 (safety — ensures motors are off at boot)
3. Applies PWM speed value to EN1 and EN2

**Parameter:**

| Parameter | Type | Range | Default | Description |
|---|---|:---:|:---:|---|
| `speed` | `uint8_t` | 0–255 | 200 | Initial motor speed |

**Examples:**

```cpp
robot.begin();        // Speed = 200 (recommended starting point)
robot.begin(255);     // Full speed from the start
robot.begin(150);     // Slower, more controlled start
robot.begin(0);       // Motors initialized but not moving — set speed later
```

> ⚠️ **If you forget to call `begin()`, the motors will not work.** The pins won't be configured as outputs, and the 74HC595 may output undefined values.

---

### `setSpeed()` / `getSpeed()`

```cpp
void    setSpeed(uint8_t speed);
uint8_t getSpeed() const;
```

`setSpeed()` changes the PWM duty cycle on both EN1 and EN2 pins simultaneously. This directly controls motor power output. You can call it at any time — even while the robot is moving.

`getSpeed()` returns the currently stored speed value (does not read hardware, returns internal variable).

**Speed reference guide:**

| Speed Value | Effect |
|:---:|---|
| `0` | Motors receive no power — robot coasts to stop |
| `50–100` | Very slow crawl — useful for precision movements |
| `120–150` | Slow-moderate speed — good for turning accuracy |
| `180–200` | Medium speed — recommended for most use cases |
| `220–240` | Fast — may cause drift on smooth surfaces |
| `255` | Full power — maximum speed |

> 💡 **Tip:** Most DC hobby motors have a **minimum startup speed** — they won't turn if the PWM value is too low. Typically this is around 60–90 for common TT motors. Use the `SpeedTest` example to find your motor's minimum.

**Examples:**

```cpp
robot.begin(200);                    // Start at 200

robot.forward();                     // Moving at 200
delay(1000);

robot.setSpeed(100);                 // Slow down while still moving
delay(1000);

robot.setSpeed(230);                 // Speed back up

Serial.println(robot.getSpeed());    // Prints: 230

robot.setSpeed(0);                   // Kill power to motors
```

---

### `forward()`

```cpp
void forward();
```

Drives all 4 motors in the forward direction. The robot moves straight ahead.

**What happens internally:**
- Sends byte `0b01100110` to the 74HC595
- All 4 motor direction pins are set: each motor receives IN_A=LOW, IN_B=HIGH
- Robot continues moving forward until you call another command

```cpp
robot.forward();         // Start moving forward
delay(3000);             // Move for 3 seconds
robot.stop();            // Stop
```

---

### `backward()`

```cpp
void backward();
```

Drives all 4 motors in the reverse direction. The robot moves straight backward.

**What happens internally:**
- Sends byte `0b10011001` to the 74HC595
- All 4 motor direction pins are reversed from forward

```cpp
robot.backward();        // Start reversing
delay(2000);             // Reverse for 2 seconds
robot.stop();            // Stop
```

---

### `left()`

```cpp
void left();
```

Pivots the robot to the left in place. The right-side motors (M2, M4) drive forward while the left-side motors (M1, M3) coast (off). This causes the robot to rotate counterclockwise.

> 💡 **Turning behavior depends on your motor and wheel setup.** If the robot turns in the wrong direction, swap the motor wire connections on one side.

```cpp
robot.left();            // Start turning left
delay(700);              // Adjust this time to tune turn angle
robot.stop();
```

---

### `right()`

```cpp
void right();
```

Pivots the robot to the right in place. The left-side motors (M1, M3) drive forward while the right-side motors (M2, M4) coast (off). This causes the robot to rotate clockwise.

```cpp
robot.right();           // Start turning right
delay(700);              // Adjust this time to tune turn angle
robot.stop();
```

---

### `stop()`

```cpp
void stop();
```

Immediately stops all motors by sending `0x00` to the 74HC595. All direction pins go LOW, causing the motors to coast freely to a stop. This does **not** disable the PWM enable pins — speed is retained so the next movement command works immediately.

```cpp
robot.stop();            // Stop all motors
```

> **Note:** This is a **coast stop**, not a brake. The motors stop receiving power and slowly spin down due to friction. For harder braking, you would need to implement a brief brake pattern using `sendRaw()`.

---

### `moveFor(direction, ms)`

```cpp
void moveFor(char direction, unsigned long ms);
```

Moves the robot in the specified direction for a set number of milliseconds, then **automatically calls `stop()`**. This is a convenience function that combines movement + delay + stop into one clean call.

**Parameters:**

| Parameter | Type | Valid Values | Description |
|---|---|---|---|
| `direction` | `char` | `'F'`, `'B'`, `'L'`, `'R'` | Direction to move |
| `ms` | `unsigned long` | 0 – 4,294,967,295 | Duration in milliseconds |

> **Case insensitive:** Both `'F'` and `'f'` work. Both `'L'` and `'l'` work.

**Examples:**

```cpp
robot.moveFor('F', 2000);    // Forward exactly 2 seconds, then stop
robot.moveFor('B', 1500);    // Backward 1.5 seconds, then stop
robot.moveFor('L', 500);     // Turn left 500ms, then stop
robot.moveFor('R', 500);     // Turn right 500ms, then stop
robot.moveFor('f', 3000);    // Lowercase also works
```

**A complete route:**

```cpp
void setup() {
  robot.begin(200);

  robot.moveFor('F', 2000);  // Forward
  delay(200);
  robot.moveFor('L', 550);   // Turn ~90 degrees left
  delay(200);
  robot.moveFor('F', 2000);  // Forward again
  delay(200);
  robot.moveFor('L', 550);   // Turn ~90 degrees left
  delay(200);
  robot.moveFor('F', 2000);  // Back to start (roughly)
}
```

> ⚠️ **`moveFor()` is blocking** — the program pauses for `ms` milliseconds during execution. If you need your code to do other things while the robot is moving (e.g., read sensors), see the [Non-Blocking Movement](#-non-blocking-movement-with-millis) section.

---

### `sendRaw(data)` — Advanced

```cpp
void sendRaw(uint8_t data);
```

Sends a raw 8-bit byte directly to the 74HC595 shift register, bypassing all library logic. This gives you direct control over every single motor direction pin.

**When to use this:**
- Testing individual motors during hardware debugging
- Creating custom movement patterns not covered by the standard functions
- Using the predefined constants directly

**Predefined constants you can use:**

```cpp
robot.sendRaw(BOTIC_FORWARD);    // Same as robot.forward()
robot.sendRaw(BOTIC_BACKWARD);   // Same as robot.backward()
robot.sendRaw(BOTIC_LEFT);       // Same as robot.left()
robot.sendRaw(BOTIC_RIGHT);      // Same as robot.right()
robot.sendRaw(BOTIC_STOP);       // Same as robot.stop()
```

**Custom patterns:**

```cpp
// Motor 2 only, forward (for testing a single motor)
robot.sendRaw(0b00100000);

// Motor 1 forward, Motor 2 backward (for spinning in tight circle)
robot.sendRaw(0b01100000);

// All motors stopped
robot.sendRaw(0x00);
```

---

## 🔁 Motor Direction Logic

### H-Bridge Truth Table (Single Motor)

Each motor is controlled by two bits. Here is the logic for one motor channel:

| IN_A | IN_B | Result | Description |
|:---:|:---:|:---:|---|
| `0` | `1` | ✅ Forward | Current flows through motor: A→ motor →B |
| `1` | `0` | 🔄 Backward | Current flows reversed: B→ motor →A |
| `0` | `0` | 🌊 Coast | No current — motor freewheels |
| `1` | `1` | 🛑 Brake | Both terminals connected to ground — hard stop |

> The library uses only Forward, Backward, and Coast states. Brake is not implemented.

---

### All Motion Commands Explained

| Function | M1 (Front Left) | M2 (Front Right) | M3 (Rear Left) | M4 (Rear Right) | Hex | Binary |
|---|:---:|:---:|:---:|:---:|:---:|:---:|
| `forward()` | ✅ FWD | ✅ FWD | ✅ FWD | ✅ FWD | `0x66` | `01100110` |
| `backward()` | 🔄 BWD | 🔄 BWD | 🔄 BWD | 🔄 BWD | `0x99` | `10011001` |
| `left()` | 🌊 Coast | ✅ FWD | 🌊 Coast | ✅ FWD | `0x44` | `01000100` |
| `right()` | ✅ FWD | 🌊 Coast | ✅ FWD | 🌊 Coast | `0x22` | `00100010` |
| `stop()` | 🌊 Off | 🌊 Off | 🌊 Off | 🌊 Off | `0x00` | `00000000` |

---

### Visual Movement Diagram

```
  forward()              backward()
  ────────────────────   ────────────────────
  M1↑  ──────  M2↑       M1↓  ──────  M2↓
       [ROBOT]                [ROBOT]
  M3↑  ──────  M4↑       M3↓  ──────  M4↓
       ▲  FRONT                ▼  FRONT


  left()                 right()
  ────────────────────   ────────────────────
  M1○  ──────  M2↑       M1↑  ──────  M2○
       [ROBOT]                [ROBOT]
  M3○  ──────  M4↑       M3↑  ──────  M4○
       ↺ rotates                ↻ rotates

  ↑ = Forward   ↓ = Backward   ○ = Coast/Off
```

---

## 🔬 74HC595 Bit Map Reference

Understanding the bit mapping helps when using `sendRaw()` or debugging hardware.

### Bit Position to Motor Signal Map

```
  MSB                                               LSB
  Bit:   7       6       5       4       3       2       1       0
         │       │       │       │       │       │       │       │
 74HC595: Q7      Q6      Q5      Q4      Q3      Q2      Q1      Q0
         │       │       │       │       │       │       │       │
  L293D: IN4     IN3     IN2     IN1     IN8     IN7     IN6     IN5
         │       │       │       │       │       │       │       │
  Motor: M2-B   M2-A    M1-B    M1-A    M4-B    M4-A    M3-B    M3-A
```

### Reading a Bit Pattern

To decode any byte, split it into 4 pairs. Each pair controls one motor:

```
Byte: 0b 01 10 01 10
          │  │  │  │
          │  │  │  └── Bits [1:0] → Motor 4: 10 = Forward
          │  │  └───── Bits [3:2] → Motor 3: 01 = Backward  ← Wait, that's odd...
          │  └──────── Bits [5:4] → Motor 2: 10 = Forward
          └─────────── Bits [7:6] → Motor 1: 01 = Backward  ← And this too?
```

> 💡 The left-side motors (M1, M3) use a mirrored wiring on the PCB, so "backward" in the bit pattern = "forward" physical direction. This is already accounted for in the library — all directions are hardware-verified.

### Verified Pattern Values

```
Command       Binary         Hex    Decimal
──────────────────────────────────────────
forward()     0b01100110    0x66    102
backward()    0b10011001    0x99    153
left()        0b01000100    0x44     68
right()       0b00100010    0x22     34
stop()        0b00000000    0x00      0
```

---

## 💡 Examples in Detail

The library comes with three examples, accessible via:
`File → Examples → BoticShieldV1 → [Example Name]`

---

### 📂 Example 1: BasicControl

**File:** `examples/BasicControl/BasicControl.ino`

**Purpose:** The simplest possible test — a timed movement loop that cycles through all directions. Use this as your **first test** when you get the shield to verify all 4 motors are working.

**What it does:**
```
→ Forward 2s  →  Stop 0.5s  →  Backward 2s  →  Stop 0.5s
→  Left 1s   →  Right 1s  →   Stop 2s  →  REPEAT
```

**Full code:**

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  Serial.begin(9600);
  robot.begin(200);
  Serial.println("Botic Shield V1 — BasicControl ready!");
}

void loop() {
  Serial.println("→ Forward 2 s");
  robot.forward();
  delay(2000);

  Serial.println("■ Stop 0.5 s");
  robot.stop();
  delay(500);

  Serial.println("← Backward 2 s");
  robot.backward();
  delay(2000);

  Serial.println("■ Stop 0.5 s");
  robot.stop();
  delay(500);

  Serial.println("↺ Left 1 s");
  robot.left();
  delay(1000);

  Serial.println("↻ Right 1 s");
  robot.right();
  delay(1000);

  Serial.println("■ Stop 2 s\n");
  robot.stop();
  delay(2000);
}
```

**Open Serial Monitor at 9600 baud** to see movement logs printed in real time.

---

### 📂 Example 2: BluetoothControl

**File:** `examples/BluetoothControl/BluetoothControl.ino`

**Purpose:** Control the robot wirelessly via an **HC-05 or HC-06 Bluetooth module**, or directly via USB Serial Monitor.

**Hardware needed:** HC-05 or HC-06 Bluetooth module connected to Arduino TX/RX (D0/D1) or via SoftwareSerial.

**Command table:**

| Send this | Robot does |
|:---:|---|
| `F` or `f` | Move forward |
| `B` or `b` | Move backward |
| `L` or `l` | Turn left |
| `R` or `r` | Turn right |
| `S` or `s` | Stop |
| `+` | Increase speed by 20 (max 255) |
| `-` | Decrease speed by 20 (min 0) |

**Compatible Bluetooth apps:**
- Android: **Bluetooth RC Controller**, **Serial Bluetooth Terminal**, **Arduino Bluetooth Controller**
- iOS: **LightBlue**, **BlueSee** (use HC-06 BLE variant)
- Any app that sends ASCII characters over Bluetooth serial

**Full code:**

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;
uint8_t currentSpeed = 200;

void setup() {
  Serial.begin(9600);
  robot.begin(currentSpeed);
  Serial.println("Botic Shield V1 — Bluetooth Control ready!");
  Serial.println("Commands: F B L R S + -");
}

void loop() {
  if (Serial.available()) {
    char cmd = (char)Serial.read();

    switch (cmd) {
      case 'F': case 'f':
        robot.forward();
        Serial.println("→ Forward");
        break;

      case 'B': case 'b':
        robot.backward();
        Serial.println("← Backward");
        break;

      case 'L': case 'l':
        robot.left();
        Serial.println("↺ Left");
        break;

      case 'R': case 'r':
        robot.right();
        Serial.println("↻ Right");
        break;

      case 'S': case 's':
        robot.stop();
        Serial.println("■ Stop");
        break;

      case '+':
        currentSpeed = min(255, currentSpeed + 20);
        robot.setSpeed(currentSpeed);
        Serial.print("Speed ↑ → "); Serial.println(currentSpeed);
        break;

      case '-':
        currentSpeed = max(0, currentSpeed - 20);
        robot.setSpeed(currentSpeed);
        Serial.print("Speed ↓ → "); Serial.println(currentSpeed);
        break;
    }
  }
}
```

---

### 📂 Example 3: SpeedTest

**File:** `examples/SpeedTest/SpeedTest.ino`

**Purpose:** Ramps the motor PWM value from 0 → 255 → 0 while the robot moves forward. Watch the Serial Monitor to find the **minimum startup speed** of your specific motors (the point where they actually start moving from standstill).

**Why this is useful:** Every motor is slightly different. Some TT motors start moving at PWM 60, others need 90+. The SpeedTest helps you find this value so you can set `begin()` appropriately and avoid calling `setSpeed()` with values too low to actually move.

**Full code:**

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

void setup() {
  Serial.begin(9600);
  robot.begin(0);
  Serial.println("Botic Shield V1 — Speed Ramp Test");
}

void loop() {
  Serial.println("↑ Ramping UP");
  robot.forward();
  for (int spd = 0; spd <= 255; spd += 5) {
    robot.setSpeed(spd);
    Serial.print("Speed: "); Serial.println(spd);
    delay(50);
  }

  delay(1000);

  Serial.println("↓ Ramping DOWN");
  for (int spd = 255; spd >= 0; spd -= 5) {
    robot.setSpeed(spd);
    Serial.print("Speed: "); Serial.println(spd);
    delay(50);
  }

  robot.stop();
  Serial.println("■ Done. Waiting 3s...\n");
  delay(3000);
}
```

---

## ⏱️ Non-Blocking Movement with millis()

The standard motion commands (`forward()`, `backward()`, etc.) are non-blocking — they start the motors and return immediately. The only blocking function is `moveFor()` which uses `delay()` internally.

If you need to **read sensors while moving**, use `millis()` for timing instead:

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

unsigned long moveStartTime = 0;
bool isMoving = false;
int state = 0;

void setup() {
  Serial.begin(9600);
  robot.begin(200);
}

void loop() {

  // Check sensor at any time — not blocked!
  // int distance = ultrasonic.read();
  // if (distance < 20) { robot.stop(); }

  // State machine for timed movement
  switch (state) {

    case 0:  // Start moving forward
      robot.forward();
      moveStartTime = millis();
      isMoving = true;
      state = 1;
      break;

    case 1:  // Wait 2 seconds
      if (millis() - moveStartTime >= 2000) {
        robot.stop();
        moveStartTime = millis();
        state = 2;
      }
      break;

    case 2:  // Wait 500ms stopped
      if (millis() - moveStartTime >= 500) {
        state = 3;
      }
      break;

    case 3:  // Turn left
      robot.left();
      moveStartTime = millis();
      state = 4;
      break;

    case 4:  // Wait 600ms turning
      if (millis() - moveStartTime >= 600) {
        robot.stop();
        state = 0;  // Loop back to start
      }
      break;
  }
}
```

---

## 📡 Complete Bluetooth Robot Project

Here is a full project combining the Botic Shield V1 with an HC-05 Bluetooth module for a complete wireless robot:

### Hardware Needed
- Arduino UNO
- Botic Shield V1
- 4× DC motors + wheels + chassis
- HC-05 or HC-06 Bluetooth module
- 7.4V LiPo or 6× AA battery pack (motor power)
- 9V battery (Arduino power) or USB power bank

### HC-05 Wiring (to Arduino)

| HC-05 Pin | Arduino Pin |
|:---:|:---:|
| VCC | 5V |
| GND | GND |
| TX | D0 (RX) |
| RX | D1 (TX) via 1kΩ voltage divider |

> ⚠️ The HC-05 RX pin is 3.3V tolerant — use a voltage divider (1kΩ + 2kΩ) to step down from Arduino's 5V TX.

### Full Bluetooth Robot Sketch

```cpp
#include <BoticShieldV1.h>

BoticShieldV1 robot;

char command = 'S';
uint8_t speed = 200;

void setup() {
  Serial.begin(9600);          // HC-05 default baud rate
  robot.begin(speed);
}

void loop() {
  // Read incoming Bluetooth command
  if (Serial.available() > 0) {
    command = toupper((char)Serial.read());
    executeCommand(command);
  }
}

void executeCommand(char cmd) {
  switch (cmd) {
    case 'F': robot.forward();  break;
    case 'B': robot.backward(); break;
    case 'L': robot.left();     break;
    case 'R': robot.right();    break;
    case 'S': robot.stop();     break;
    case '0': robot.setSpeed(0);   robot.stop(); break;
    case '1': robot.setSpeed(50);  break;
    case '2': robot.setSpeed(100); break;
    case '3': robot.setSpeed(150); break;
    case '4': robot.setSpeed(200); break;
    case '5': robot.setSpeed(255); break;
    default: break;
  }
}
```

**App to use:** Download **"Bluetooth RC Controller"** on Android → Connect to HC-05 → Set button characters to F/B/L/R/S → Drive!

## Sensor & Peripheral Testing Guide

This section provides independent test programs for all onboard peripherals of the Botic Shield V1.
Use these codes to verify hardware functionality before integrating into your main robot project.

**1. Ultrasonic Sensor Test (3 Sensors)**
Connections
Sensor 1 → TRIG = A0, ECHO = A1
Sensor 2 → TRIG = A2, ECHO = A3
Sensor 3 → TRIG = A4, ECHO = A5

Note: If using I2C LCD, avoid using A4/A5 (reserved for SDA/SCL)

Code
#define TRIG1 A0
#define ECHO1 A1

#define TRIG2 A2
#define ECHO2 A3

#define TRIG3 A4
#define ECHO3 A5

long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  Serial.begin(9600);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);
}

void loop() {
  long d1 = readDistance(TRIG1, ECHO1);
  long d2 = readDistance(TRIG2, ECHO2);
  long d3 = readDistance(TRIG3, ECHO3);

  Serial.print("Sensor1: ");
  Serial.print(d1);
  Serial.print(" cm | ");

  Serial.print("Sensor2: ");
  Serial.print(d2);
  Serial.print(" cm | ");

  Serial.print("Sensor3: ");
  Serial.print(d3);
  Serial.println(" cm");

  delay(500);
}




**2. Servo Motor Test (3 Servos)**
Pins
Servo 1 → D2
Servo 2 → D4
Servo 3 → D7
Code
#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;

void setup() {
  Serial.begin(9600);

  s1.attach(2);
  s2.attach(4);
  s3.attach(7);
}

void loop() {
  for (int angle = 0; angle <= 180; angle += 30) {
    s1.write(angle);
    s2.write(angle);
    s3.write(angle);

    Serial.print("Angle: ");
    Serial.println(angle);

    delay(1000);
  }

  for (int angle = 180; angle >= 0; angle -= 30) {
    s1.write(angle);
    s2.write(angle);
    s3.write(angle);

    Serial.print("Angle: ");
    Serial.println(angle);

    delay(1000);
  }
}


**3. IR Sensor Test**
Pins
IR1 → D12
IR2 → D8
Code
#define IR1 12
#define IR2 8

void setup() {
  Serial.begin(9600);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
}

void loop() {
  int val1 = digitalRead(IR1);
  int val2 = digitalRead(IR2);

  Serial.print("IR1: ");
  Serial.print(val1);
  Serial.print(" | IR2: ");
  Serial.println(val2);

  delay(200);
}
Output
0 → Object detected
1 → No object


**4. I2C LCD Test**
Pins
SDA → A4
SCL → A5

Important: Ensure no other device (like ultrasonic sensors) is connected to A4/A5

Required Library
LiquidCrystal_I2C
Code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Change address if needed (0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("LCD Test Start");

  Serial.println("LCD Working...");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("Hello Raunak  ");

## 🔭 Board Compatibility

| Board | Status | Notes |
|---|:---:|---|
| Arduino UNO R3 | ✅ Fully Tested | Primary target |
| Arduino Nano | ✅ Fully Tested | Identical pinout to UNO |
| Arduino Mega 2560 | ✅ Compatible | PWM pins differ — check D3/D6 availability |
| Arduino UNO R4 Minima | ⚠️ Should work | Not officially tested yet |
| Arduino UNO R4 WiFi | ⚠️ Should work | Not officially tested yet |
| Arduino Leonardo | ⚠️ Should work | Check PWM pin map |
| ESP8266 (NodeMCU) | ⚠️ Use caution | 3.3V logic — add level shifter before 74HC595 |
| ESP32 | ⚠️ Use caution | 3.3V logic — add level shifter before 74HC595 |
| Raspberry Pi Pico | ❌ Not tested | Different architecture |

> The library uses only standard Arduino functions: `pinMode()`, `digitalWrite()`, `analogWrite()`, and `shiftOut()`. It will compile on any Arduino-compatible board. Physical shield PCB may need adaptation for non-UNO form factors.



## 🔍 How It Works Internally

This section is for those curious about what happens inside the library when you call `robot.forward()`.

### Step-by-step: What `robot.forward()` does

```
robot.forward()
    │
    └── calls _shiftSend(BOTIC_FORWARD)
            │
            └── BOTIC_FORWARD = 0b01100110
                    │
                    ├── digitalWrite(_latch, LOW)       // Lock outputs — prevent glitches
                    │
                    ├── shiftOut(_data, _clock, MSBFIRST, 0b01100110)
                    │       │
                    │       │  Sends 8 bits one at a time:
                    │       │  Bit 7: 0 → Q7 (IN4, M2-B) = LOW
                    │       │  Bit 6: 1 → Q6 (IN3, M2-A) = HIGH  ← M2 Forward
                    │       │  Bit 5: 1 → Q5 (IN2, M1-B) = HIGH  ← M1 Forward
                    │       │  Bit 4: 0 → Q4 (IN1, M1-A) = LOW
                    │       │  Bit 3: 0 → Q3 (IN8, M4-B) = LOW
                    │       │  Bit 2: 1 → Q2 (IN7, M4-A) = HIGH  ← M4 Forward
                    │       │  Bit 1: 1 → Q1 (IN6, M3-B) = HIGH  ← M3 Forward
                    │       │  Bit 0: 0 → Q0 (IN5, M3-A) = LOW
                    │
                    └── digitalWrite(_latch, HIGH)      // Release outputs — all 8 appear simultaneously
                                                         // All 4 motors now receiving forward signal
                                                         // Speed determined by EN1/EN2 PWM values
```

The entire `shiftOut()` operation takes only about **50–100 microseconds** at 16MHz — virtually instantaneous from a human perspective.



## 🤝 Contributing

Contributions are welcome! Bug fixes, new examples, documentation improvements, and board support patches are all appreciated.

### How to Contribute

1. **Fork** this repository on GitHub
2. Create a new branch: `git checkout -b feature/add-nonblocking-movement`
3. Make your changes and test them on real hardware
4. Commit with a clear message: `git commit -m "feat: add non-blocking millis-based moveFor"`
5. Push: `git push origin feature/add-nonblocking-movement`
6. Open a **Pull Request** with a description of what you changed and why

### Good First Contributions

- 📖 Fix typos or improve explanations in README
- 🧪 Add new example sketches (IR remote, ultrasonic obstacle avoidance, etc.)
- 🔧 Add support for per-motor speed control
- 📱 Test and document compatibility with specific Bluetooth apps
- 🌐 Test and document ESP32/ESP8266 compatibility

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for full guidelines.

---

## 📋 Changelog

### v1.0.0 — Initial Release *(2025)*

**Added:**
- `BoticShieldV1` class with full constructor and default pin values
- `begin(speed)` — safe initialization with auto-stop on power-up
- `setSpeed(0–255)` — real-time PWM speed control
- `getSpeed()` — read current speed value
- `forward()`, `backward()`, `left()`, `right()`, `stop()` — motion commands
- `moveFor(direction, ms)` — timed movement with automatic stop
- `sendRaw(byte)` — direct shift register access for advanced users
- Named constants: `BOTIC_FORWARD`, `BOTIC_BACKWARD`, `BOTIC_LEFT`, `BOTIC_RIGHT`, `BOTIC_STOP`
- Example: `BasicControl` — timed movement sequence
- Example: `BluetoothControl` — HC-05/HC-06 serial command interface
- Example: `SpeedTest` — PWM ramp test for motor calibration
- Full Doxygen-style comments throughout header file
- Comprehensive README with hardware docs, API reference, and troubleshooting

See [CHANGELOG.md](CHANGELOG.md) for full history.

---

## 📜 License

```
MIT License

Copyright (c) 2025 Raunak Choudhary

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

<div align="center">

### 🤖 Built with  Raunak Choudhary

*From a custom PCB design to a published open-source library.*

<br>

**⭐ If this library helped you build your robot, please star this repository! ⭐**

<br>

[![GitHub](https://img.shields.io/badge/GitHub-raunakchoudhary-black?style=for-the-badge&logo=github)](https://github.com/raunakchoudhary)

</div>
