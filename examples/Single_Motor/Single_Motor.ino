#include <CNC_Shield.h>
#define CW 1  // Clockwise
#define CCW 0 // Counter-Clockwise

CNC_Shield stepper1(2, 5, 9);

void setup()
{
    stepper1.begin();
}

void loop()
{
    stepper1.step(200, CW);
    delay(1000);
    stepper1.step(200, CCW);
    delay(1000);
}
