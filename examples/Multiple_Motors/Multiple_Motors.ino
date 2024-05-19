#include <CNC_Shield.h>
#define CW 1  // Clockwise
#define CCW 0 // Counter-Clockwise

CNC_Shield stepper1(2, 5, 9);
CNC_Shield stepper2(3, 6, 10);
CNC_Shield stepper3(4, 7, 11);

void setup()
{
  stepper1.begin();
  stepper2.begin();
  stepper3.begin();
}

void loop()
{
  stepper1.step(200, CW);
  stepper2.step(400, CW);
  stepper3.step(800, CW);
  delay(1000);
  stepper3.step(800, CCW);
  stepper2.step(400, CCW);
  stepper1.step(200, CCW);
  delay(1000);
}
