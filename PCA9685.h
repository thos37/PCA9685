/**
* Arduino library to control PCA9685 chip.
*/

#ifndef PCA9685_h
#define PCA9685_h

#include "Arduino.h"
#include <Wire.h>

class PCA9685
{
  public:
    PCA9685(uint8_t address);
    void        begin();
    void        wake();
    void        setPWMFrequency(uint16_t frequency);
    uint16_t    getPWMFrequency();
    void        PWM(uint8_t start, uint8_t numchs, uint16_t* values);
    void        PWMSame(uint8_t start, uint8_t numchs, uint16_t value);
    void        PWM(uint8_t channel, uint16_t value);
    void        PWM8(uint8_t start, uint8_t numchs, uint8_t* values);
    void        PWM8Same(uint8_t start, uint8_t numchs, uint8_t value);
    void        PWM8(uint8_t channel , uint8_t value);
    uint16_t    getPWM(uint8_t channel);

  private:
    uint8_t     _address;
    void        PWMPreScale(uint8_t prescale);
};
#endif
