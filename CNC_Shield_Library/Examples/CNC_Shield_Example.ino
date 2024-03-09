#include <CNC_Shield.h>
#define CW 1                      //Clockwise          << Change to 0 if reversed
#define CCW 0                     //Counter Clockwise  << Change to 1 if reversed

CNC_Shield stepper1(2, 5, 9);     //stepper1(StepPin, DirectionPin, LimitSwitchPin);

void setup() {
  stepper1.begin();               //Initialize the stepper1
}

void loop() {
  stepper1.step(200, CW);        //moving the stepper motor clockwise
  delay(1000);
  stepper1.step(200, CCW);       //moving the stepper motor counter clockwise
  delay(1000);
}
