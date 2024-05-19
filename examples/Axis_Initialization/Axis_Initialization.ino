#include <CNC_Shield.h>
#define CW 1  // Clockwise
#define CCW 0 // Counter-Clockwise

CNC_Shield stepper1('X'); // Use Uppercase characters only
CNC_Shield stepper2('Y');
CNC_Shield stepper3('Z');
CNC_Shield stepper4('A'); // A-axis does not a limit switch pin

void setup()
{
    stepper1.begin();
    stepper2.begin();
    stepper3.begin();
    stepper4.begin();
}

void loop()
{
    stepper1.step(200, CW);
    stepper2.step(400, CW);
    stepper3.step(800, CW);
    stepper4.step(1600, CW);
    delay(1000);
    stepper4.step(1600, CCW);
    stepper3.step(800, CCW);
    stepper2.step(400, CCW);
    stepper1.step(200, CCW);
    delay(1000);
}
