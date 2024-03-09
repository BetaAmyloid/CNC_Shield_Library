/*
    CNC_Shield.h - Library for controlling stepper
    motors using Arduino Uno + CNC Shield v3

    Created by BetaAmyloid, March 9, 2024
*/

#include "Arduino.h"
#include "CNC_Shield.h"

CNC_Shield::CNC_Shield(int StepPin, int DirPin, int LimitPin)
{
    _StepPin = StepPin;
    _DirPin = DirPin;
    _LimitPin = LimitPin;
}

CNC_Shield::CNC_Shield(int StepPin, int DirPin)
{
    _StepPin = StepPin;
    _DirPin = DirPin;
}

void CNC_Shield::begin()
{
    pinMode(_StepPin, OUTPUT);
    pinMode(_DirPin, OUTPUT);
    if (NULL != _LimitPin)
        pinMode(_LimitPin, INPUT_PULLUP);
    digitalWrite(_StepPin, LOW);
    digitalWrite(_DirPin, LOW);
}

void CNC_Shield::setDelay(int DelayMicroseconds)
{
    _DelayMicroseconds = DelayMicroseconds;
}

void CNC_Shield::step(int Steps, int Direction)
{
    digitalWrite(_DirPin, Direction);
    for (int i = 0; i < Steps; i++)
    {
        if (!digitalRead(_LimitPin))
            break;
        else
        {
            digitalWrite(_StepPin, HIGH);
            delayMicroseconds(_DelayMicroseconds);
            digitalWrite(_StepPin, LOW);
            delayMicroseconds(_DelayMicroseconds);
        }
    }
}

void CNC_Shield::stepNoLimit(int Steps, int Direction)
{
    digitalWrite(_DirPin, Direction);
    for (int i = 0; i < Steps; i++)
    {
        digitalWrite(_StepPin, HIGH);
        delayMicroseconds(_DelayMicroseconds);
        digitalWrite(_StepPin, LOW);
        delayMicroseconds(_DelayMicroseconds);
    }
}
