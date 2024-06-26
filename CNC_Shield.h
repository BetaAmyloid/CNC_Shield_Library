/*
    CNC_Shield.h - Library for controlling stepper
    motors using Arduino Uno + CNC Shield v3

    Created by BetaAmyloid, March 9, 2024
*/
#ifndef CNC_Shield_h
#define CNC_Shield_h

#include "Arduino.h"

class CNC_Shield
{
public:
    CNC_Shield(int StepPin, int DirPin, int LimitPin);
    CNC_Shield(int StepPin, int DirPin);
    CNC_Shield(char Axis);
    void begin();
    void setDelay(unsigned long DelayMicroseconds);
    void step(int Steps, int Direction);
    void stepNoLimit(int Steps, int Direction);

private:
    int _StepPin, _DirPin, _LimitPin;
    unsigned long _DelayMicroseconds = 500;
};

#endif