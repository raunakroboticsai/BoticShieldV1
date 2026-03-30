/**
 * @file BoticShieldV1.cpp
 * @brief Implementation – Botic Shield V1 motor library
 *
 * Hardware: L293D + 74HC595 shift register
 * Author:   Raunak Choudhary
 * Version:  1.0.0
 */

#include "BoticShieldV1.h"

// ── Constructor ──────────────────────────────────────────────────────
BoticShieldV1::BoticShieldV1(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin,
                             uint8_t en1Pin, uint8_t en2Pin)
  : _data(dataPin), _clock(clockPin), _latch(latchPin),
    _en1(en1Pin), _en2(en2Pin), _speed(200)
{}

// ── begin ────────────────────────────────────────────────────────────
void BoticShieldV1::begin(uint8_t speed) {
  _speed = speed;

  pinMode(_data,  OUTPUT);
  pinMode(_clock, OUTPUT);
  pinMode(_latch, OUTPUT);
  pinMode(_en1,   OUTPUT);
  pinMode(_en2,   OUTPUT);

  // Safety: ensure motors are stopped before enabling drivers
  _shiftSend(BOTIC_STOP);

  analogWrite(_en1, _speed);
  analogWrite(_en2, _speed);
}

// ── Speed control ────────────────────────────────────────────────────
void BoticShieldV1::setSpeed(uint8_t speed) {
  _speed = speed;
  analogWrite(_en1, _speed);
  analogWrite(_en2, _speed);
}

uint8_t BoticShieldV1::getSpeed() const {
  return _speed;
}

// ── Internal shift-register write ───────────────────────────────────
void BoticShieldV1::_shiftSend(uint8_t data) {
  digitalWrite(_latch, LOW);
  shiftOut(_data, _clock, MSBFIRST, data);
  digitalWrite(_latch, HIGH);
}

// ── Public raw send ──────────────────────────────────────────────────
void BoticShieldV1::sendRaw(uint8_t data) {
  _shiftSend(data);
}

// ── Motion commands ──────────────────────────────────────────────────

void BoticShieldV1::forward() {
  _shiftSend(BOTIC_FORWARD);
}

void BoticShieldV1::backward() {
  _shiftSend(BOTIC_BACKWARD);
}

void BoticShieldV1::left() {
  _shiftSend(BOTIC_LEFT);
}

void BoticShieldV1::right() {
  _shiftSend(BOTIC_RIGHT);
}

void BoticShieldV1::stop() {
  _shiftSend(BOTIC_STOP);
}

void BoticShieldV1::moveFor(char direction, unsigned long ms) {
  switch (direction) {
    case 'F': case 'f': forward();  break;
    case 'B': case 'b': backward(); break;
    case 'L': case 'l': left();     break;
    case 'R': case 'r': right();    break;
    default:            stop();     break;
  }
  delay(ms);
  stop();
}
