/*
    CNC_Shield.h - Library for controlling stepper
    motors using Arduino Uno + CNC Shield v3

    Created by BetaAmyloid, March 9, 2024
*/

#include "Arduino.h"
#include "CNC_Shield.h"

CNC_Shield::CNC_Shield(int StepPin, int DirPin, int LimitPin)
    : _StepPin(StepPin), _DirPin(DirPin), _LimitPin(LimitPin)
{
    _StepPin = StepPin;
    _DirPin = DirPin;
    _LimitPin = LimitPin;
}

CNC_Shield::CNC_Shield(int StepPin, int DirPin)
    : CNC_Shield(StepPin, DirPin, -1)
{
}

CNC_Shield::CNC_Shield(char Axis)
{
    switch (Axis)
    {
    case 'X':
        _StepPin = 2;
        _DirPin = 5;
        _LimitPin = 9;
        break;
    case 'Y':
        _StepPin = 3;
        _DirPin = 6;
        _LimitPin = 10;
        break;
    case 'Z':
        _StepPin = 4;
        _DirPin = 7;
        _LimitPin = 11;
        break;
    case 'A':
        _StepPin = 12;
        _DirPin = 13;
        break;
    default:
        _StepPin = -1;
        _DirPin = -1;
        _LimitPin = -1;
    }
}

void CNC_Shield::begin()
{
    pinMode(_StepPin, OUTPUT);
    pinMode(_DirPin, OUTPUT);
    if (-1 != _LimitPin)
        pinMode(_LimitPin, INPUT_PULLUP);
    digitalWrite(_StepPin, LOW);
    digitalWrite(_DirPin, LOW);
}

void CNC_Shield::setDelay(unsigned long DelayMicroseconds)
{
    _DelayMicroseconds = DelayMicroseconds;
}

void CNC_Shield::step(int Steps, int Direction)
{
    Direction = (Direction == HIGH || Direction == LOW) ? Direction : LOW;
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
    Direction = (Direction == HIGH || Direction == LOW) ? Direction : LOW;
    digitalWrite(_DirPin, Direction);
    for (int i = 0; i < Steps; i++)
    {
        digitalWrite(_StepPin, HIGH);
        delayMicroseconds(_DelayMicroseconds);
        digitalWrite(_StepPin, LOW);
        delayMicroseconds(_DelayMicroseconds);
    }
}