#include <Stepper.h>

int in1=8;
int in2=9;
int in3=10;
int in4=11;
int motorSpeed=10;
Stepper myStepper(2048, in1, in3, in2, in4);

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(motorSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(2048);
  delay(500);
}
