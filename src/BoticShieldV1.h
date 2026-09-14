/**
 * @file BoticShieldV1.h
 * @brief Motor control library for Botic Shield V1
 *
 * Hardware: L293D Motor Driver + 74HC595 Shift Register
 * Author:   Raunak Choudhary
 * Version:  1.1.0
 *
 * Default Pin Mapping (Arduino UNO/Nano):
 *   Data  (DS)    → Pin 11
 *   Clock (SHCP)  → Pin 13
 *   Latch (STCP)  → Pin 10
 *   EN1   (PWM)   → Pin 3
 *   EN2   (PWM)   → Pin 6
 *
 * 74HC595 → L293D Bit Mapping (Botic Shield V1 PCB):
 *   Bits [7:6] → Motor 1  (IN1/IN2)
 *   Bits [5:4] → Motor 2  (IN3/IN4)
 *   Bits [3:2] → Motor 3  (IN5/IN6)
 *   Bits [1:0] → Motor 4  (IN7/IN8)
 *
 *   Per-motor encoding:
 *     01 → Forward
 *     10 → Backward
 *     00 → Stop
 */

#ifndef BOTICSHIELDV1_H
#define BOTICSHIELDV1_H

#include <Arduino.h>

// ── Shift-register bit patterns ───────────────────────────────────

#define BOTIC_FORWARD       0b01100110   // All motors forward
#define BOTIC_BACKWARD      0b10011001   // All motors backward

#define BOTIC_LEFT          0b01100000   // Soft left (right motors active)
#define BOTIC_RIGHT         0b00000110   // Soft right (left motors active)

#define BOTIC_STOP          0b00000000   // Stop all motors

// Sharp turns (Tank Turn - Zero Radius)
#define BOTIC_SHARP_LEFT    0b01101001   // Left motors backward, right forward
#define BOTIC_SHARP_RIGHT   0b10010110   // Left motors forward, right backward

// ──────────────────────────────────────────────────────────────────

class BoticShieldV1 {
  public:

    /**
     * @brief Constructor – configure shield pins.
     */
    BoticShieldV1(uint8_t dataPin  = 11,
                  uint8_t clockPin = 13,
                  uint8_t latchPin = 10,
                  uint8_t en1Pin   = 3,
                  uint8_t en2Pin   = 6);

    /**
     * @brief Initialise pins and set default speed.
     */
    void begin(uint8_t speed = 200);

    /** @brief Set motor speed (0–255). */
    void setSpeed(uint8_t speed);

    /** @brief Get current speed. */
    uint8_t getSpeed() const;

    // ── Motion Commands ─────────────────────────────────────────

    void forward();
    void backward();

    // Soft Turns
    void left();
    void right();

    // Sharp Turns (Tank Turn)
    void sharpLeft();
    void sharpRight();

    void stop();

    /**
     * @brief Move for a fixed duration.
     * @param direction F, B, L, R, S (sharp left), T (sharp right)
     * @param ms Duration in milliseconds
     */
    void moveFor(char direction, unsigned long ms);

    /**
     * @brief Send raw byte to shift register.
     */
    void sendRaw(uint8_t data);

  private:
    uint8_t _data, _clock, _latch;
    uint8_t _en1, _en2;
    uint8_t _speed;

    void _shiftSend(uint8_t data);
};

#endif
