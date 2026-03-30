/**
 * @file BoticShieldV1.h
 * @brief Motor control library for Botic Shield V1
 *
 * Hardware: L293D Motor Driver + 74HC595 Shift Register
 * Author:   Raunak Choudhary
 * Version:  1.0.0
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
 *   Per-motor encoding: MSB=0, LSB=1 → Forward
 *                       MSB=1, LSB=0 → Backward
 *                       00 → Coast/Stop
 */

#ifndef BOTICSHIELDV1_H
#define BOTICSHIELDV1_H

#include <Arduino.h>

// ── Shift-register bit patterns (hardware-verified on Botic Shield V1) ───
//
//  Byte layout:  [M1B | M1A | M2A | M2B | M3B | M3A | M4A | M4B]
//                  7     6     5     4     3     2     1     0
//
//  Forward  M2 & M4 spin one direction, M1 & M3 complement for straight drive
//  These values were verified on actual Botic Shield V1 hardware.

#define BOTIC_FORWARD   0b01100110   // All motors forward
#define BOTIC_BACKWARD  0b10011001   // All motors backward
#define BOTIC_LEFT      0b01000100   // Left turn  (right motors drive, left coast)
#define BOTIC_RIGHT     0b00100010   // Right turn (left motors drive, right coast)
#define BOTIC_STOP      0b00000000   // All motors off

class BoticShieldV1 {
  public:

    /**
     * @brief Constructor – configure shield pins.
     * @param dataPin   SER / DS  pin of 74HC595  (default: 11)
     * @param clockPin  SRCLK     pin of 74HC595  (default: 13)
     * @param latchPin  RCLK      pin of 74HC595  (default: 10)
     * @param en1Pin    PWM enable for L293D 1 & 2 (default:  3)
     * @param en2Pin    PWM enable for L293D 3 & 4 (default:  6)
     */
    BoticShieldV1(uint8_t dataPin  = 11,
                  uint8_t clockPin = 13,
                  uint8_t latchPin = 10,
                  uint8_t en1Pin   =  3,
                  uint8_t en2Pin   =  6);

    /**
     * @brief Initialise pins and set default speed.
     *        Must be called inside setup().
     * @param speed  PWM value 0–255 (default: 200)
     */
    void begin(uint8_t speed = 200);

    /** @brief Change motor speed on the fly (0–255). */
    void setSpeed(uint8_t speed);

    /** @brief Return current speed setting. */
    uint8_t getSpeed() const;

    // ── Motion commands ──────────────────────────────────────────────
    void forward();
    void backward();
    void left();
    void right();
    void stop();

    /**
     * @brief Move for a fixed duration then stop.
     * @param direction  One of: 'F','B','L','R'
     * @param ms         Duration in milliseconds
     */
    void moveFor(char direction, unsigned long ms);

    /**
     * @brief Send a raw byte directly to the shift register.
     *        Useful for custom motor patterns or debugging.
     * @param data  8-bit pattern (see bit layout in header)
     */
    void sendRaw(uint8_t data);

  private:
    uint8_t _data, _clock, _latch;
    uint8_t _en1, _en2;
    uint8_t _speed;

    // Internal: latch & shift a byte out to 74HC595
    void _shiftSend(uint8_t data);
};

#endif  // BOTICSHIELDV1_H
